
#include "WrapperP7.h"

#include <json/json.h>

#include <fstream>
#include <cstring>
#include <iomanip>

#include <TransformTools.h>

#ifdef WIN32
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#endif // WIN32

#include "P7_Client.h"
#if defined(_WIN32) || defined(_WIN64)
	#define P7_CONVERSE		TM("[%S]")
#else
	#define P7_CONVERSE		TM("[%s]")
#endif // defined(_WIN32) || defined(_WIN64)

#ifdef LOG_ADD_CONSOLE
	#include <iostream>
	#include <ctime>
	#include <mutex>

	std::mutex g_console_mutex;
	void logToConsole(const std::string& name, const tUINT32 level, const std::string log, const tUINT32 verboseLevel)
	{
		std::lock_guard <std::mutex> lock(g_console_mutex);
#ifdef WIN32
		setlocale(LC_ALL, "Russian");

		time_t seconds = std::time(0);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
#else
		time_t seconds = std::time(0);
		tm timeinfo = *localtime(&seconds);
#endif
		if (level < verboseLevel)
			return;

		std::string levelText = "[TRACE]";
		if (level == 5) { levelText = "[CRIT ]"; }
		else if (level == 1) { levelText = "[DEBUG]"; }
		else if (level == 2) { levelText = "[INFO ]"; }
		else if (level == 3) { levelText = "[WARN ]"; }
		else if (level == 4) { levelText = "[ERROR]"; }
		std::cout << "[" << std::put_time(&timeinfo, "%d.%m.%Y %H:%M:%S.%z") << "] " << "[" << name << "] " << levelText << " [" << log << "]" << std::endl;
	}
#else
	void logToConsole(const std::string& name, const tUINT32 level, const std::string log) {}
#endif

namespace Lanter
{
	LogOptions::LogOptions(const std::string& _sinkClient, const std::string& _nameTrace, const std::string& _nameModule, const std::string& _nameThread)
	{
#if defined(_WIN32) || defined(_WIN64)
		std::wstring attr;

		//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		//std::to_wstring()

		attr = std::wstring(_sinkClient.begin(), _sinkClient.end());
		sinkClient = new tXCHAR[attr.size() + 1];
		wcscpy_s(sinkClient, attr.size() + 1, (tXCHAR*)attr.c_str());


		attr = std::wstring(_nameTrace.begin(), _nameTrace.end());
		nameTrace = new tXCHAR[attr.size() + 1];
		wcscpy_s(nameTrace, attr.size() + 1, (tXCHAR*)attr.c_str());

		attr = std::wstring(_nameModule.begin(), _nameModule.end());
		nameModule = new tXCHAR[attr.size() + 1];
		wcscpy_s(nameModule, attr.size() + 1, (tXCHAR*)attr.c_str());

		attr = std::wstring(_nameThread.begin(), _nameThread.end());
		nameThread = new tXCHAR[attr.size() + 1];
		wcscpy_s(nameThread, attr.size() + 1, (tXCHAR*)attr.c_str());

#else
		sinkClient = new tXCHAR[_sinkClient.size() + 1];
		strcpy(sinkClient, _sinkClient.c_str());

		nameTrace = new tXCHAR[_nameTrace.size() + 1];
		strcpy(nameTrace, _nameTrace.c_str());

		nameModule = new tXCHAR[_nameModule.size() + 1];
		strcpy(nameModule, _nameModule.c_str());

		nameThread = new tXCHAR[_nameThread.size() + 1];
		strcpy(nameThread, _nameThread.c_str());

#endif // defined(_WIN32) || defined(_WIN64)

	}
	LogOptions::~LogOptions()
	{
		if (sinkClient)
			delete sinkClient;
		if (nameTrace)
			delete nameTrace;
		if (nameModule)
			delete nameModule;
		if (nameThread)
			delete nameThread;
	}

	LoggerConfig::LoggerConfig(const std::string& name): m_name(name)
	{ ; }
	LoggerConfig::~LoggerConfig()
	{ ; }

	std::string& LoggerConfig::Format()
	{
		return m_format;
	}
	std::string& LoggerConfig::Dir()
	{
		return m_dir;
	}
	std::string& LoggerConfig::Roll()
	{
		return m_roll;
	}
	tUINT32& LoggerConfig::MaxFileCount()
	{
		return m_files;
	}
	tUINT32& LoggerConfig::MaxFileSize()
	{
		return m_fsize;
	}
	tUINT32& LoggerConfig::Level()
	{
		return m_level;
	}

	bool LoggerConfig::saveConfiguration()
	{
		Json::Value options;
		options["name"] = m_name.empty() ? "default" : m_name;
		options["format"] = m_format;
		options["dir"] = m_dir;
		options["roll"] = m_roll;
		options["maxFileCount"] = m_files;
		options["maxFileSize"] = m_fsize;
		options["level"] = m_level;

		Json::Value logger;
		logger["logger"] = options;

		Json::StreamWriterBuilder builder;
		std::string json = Json::writeString(builder, logger);

		std::string pathCfg = fs::current_path().u8string() + "/" + m_name + ".logcfg";
		std::ofstream cfgFile(pathCfg);
		if (cfgFile.is_open())
		{
			cfgFile.write(json.c_str(), json.size());
			cfgFile.close();
		}

		return true;
	}
	bool LoggerConfig::loadConfiguration()
	{
		std::string pathCfg = fs::current_path().u8string() + "/" + m_name + ".logcfg";
		if (!fs::exists(pathCfg))
			saveDefaultConfiguration();

		std::ifstream cfgFile(pathCfg);
		if (!cfgFile.is_open())
			return false;

		std::string json;
		std::getline(cfgFile, json, (char)cfgFile.eof());
		cfgFile.close();

		Json::Value root;
		Json::CharReaderBuilder builder;
		Json::CharReader* reader = builder.newCharReader();

		std::string errors;
		bool parsingSuccessful = reader->parse(json.c_str(), json.c_str() + json.size(), &root, &errors);
		if (!parsingSuccessful)
			return false;

		Json::Value logger = root["logger"];
		if (!logger)
			return false;
				
		m_format = logger["format"].asString();
		m_dir = logger["dir"].asString();
		m_roll = logger["roll"].asString();
		m_files = (tUINT32)str2int(logger["maxFileCount"].asString(), (unsigned int)0);
		m_fsize = (tUINT32)str2int(logger["maxFileSize"].asString(), (unsigned int)0);
		m_level = (tUINT32)str2int(logger["level"].asString(), (unsigned int)0);

		prepareConfig();

		return true;
	}

	void LoggerConfig::prepareConfig()
	{
		std::string clientFileOpt = "/P7.Sink=FileTxt";
//		std::string clientFileOpt = "/P7.Sink=Baical /P7.Addr=127.0.0.1";
		clientFileOpt += " /P7.Format=\"" + m_format + "\"";
		clientFileOpt += " /P7.Dir=" + m_dir;
		clientFileOpt += " /P7.Roll=" + m_roll;
		clientFileOpt += " /P7.Files=" + std::to_string(m_files);
		clientFileOpt += " /P7.FSize=" + std::to_string(m_fsize);
		clientFileOpt += " /P7.Trc.Verb=" + std::to_string(m_level);
		m_pFileOpt = std::make_shared<LogOptions>(clientFileOpt, m_name + "FileTrace", m_name + "FileModule", m_name + "FileThread");
	}

	void LoggerConfig::saveDefaultConfiguration()
	{
		m_format = "[%tf] [%ti] [%lv] %ms";
		m_dir = fs::current_path().u8string() + "/" + m_name;
		m_roll = "100mb";
		m_files = 0;
		m_fsize = 0;
		m_level = P7_TRACE_LEVEL_DEBUG;

		saveConfiguration();
	}

	LoggerDevice::LoggerDevice(LogOptionsPtr pOpt) :
		m_pOpt(pOpt), hClient(0), hTrace(0), pModule(0)
	{ ; }
	LoggerDevice::~LoggerDevice()
	{ ; }

	WrapperP7::WrapperP7(const std::string& name): LoggerConfig(name)
	{
		P7_Set_Crash_Handler();
	}
	WrapperP7::~WrapperP7()
	{
		saveConfiguration();

		clear();
		m_pFile.reset();

		P7_Clr_Crash_Handler();
	}
	void WrapperP7::flush()
	{
		if (m_pFile)
		{
			P7_Flush();
		}
	}

	void WrapperP7::clear()
	{
		if (m_pFile)
		{
			if (m_pFile->hTrace && m_pFile->hClient)
			{
				P7_Trace_Unregister_Thread(m_pFile->hTrace, 0);
				P7_Client_Flush(m_pFile->hClient);
			}
			if (m_pFile->hTrace)
			{
				P7_Trace_Release(m_pFile->hTrace);
				m_pFile->hTrace = 0;
			}

			if (m_pFile->hClient)
			{
				// не смог пока понять, валится тут
				//P7_Client_Release(m_pFile->hClient);
				m_pFile->hClient = 0;
			}
		}
	}
	bool WrapperP7::init()
	{
		if (!m_pFile)
		{
			if (!loadConfiguration() && !m_pFileOpt)
				return false;
			m_pFile = std::make_shared<LoggerDevice>(m_pFileOpt);
		}

		m_pFile->hClient = P7_Client_Create(m_pFile->m_pOpt->sinkClient);
		if (!m_pFile->hClient)
		{
			return false;
		}

		m_pFile->hTrace = P7_Trace_Create(m_pFile->hClient, m_pFile->m_pOpt->nameTrace, NULL);
		if (m_pFile->hTrace)
		{
			m_pFile->pModule = P7_Trace_Register_Module(m_pFile->hTrace, m_pFile->m_pOpt->nameModule);
			if (m_pFile->pModule)
			{
				if (P7_Trace_Register_Thread(m_pFile->hTrace, m_pFile->m_pOpt->nameThread, 0))
					return true;
			}
		}

		//P7_Trace_Set_Verbosity(m_pFile->hTrace, m_pFile->pModule, Level());

		return false;
	}
	void WrapperP7::logMsg(tUINT32 level, const std::string& _what)
	{
		if (m_pFile)
			P7_TRACE_ADD(m_pFile->hTrace, 0, level, m_pFile->pModule, P7_CONVERSE, _what.c_str());

		logToConsole(this->m_name, level, _what, Level());

		flush();
	}
	void WrapperP7::logMsg(const std::string& _where, tUINT32 level, const std::string& _what)
	{
		std::string funcText = _where.length() ? _where + "() " : " ";
		funcText = ": [" + funcText + _what + "]";

		if (m_pFile)
			P7_TRACE_ADD(m_pFile->hTrace, 0, level, m_pFile->pModule, P7_CONVERSE, funcText.c_str());

		logToConsole(this->m_name, level, funcText, Level());

		flush();
	}

}//namespace Lanter

