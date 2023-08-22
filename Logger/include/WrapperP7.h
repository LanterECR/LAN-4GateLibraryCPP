#ifndef LAN_LOGGERLIB_WRAPERP7_H
#define LAN_LOGGERLIB_WRAPERP7_H

#include <string>
#include <memory>

#include "GTypes.h"
#include "P7_Cproxy.h"

namespace Lanter
{
	///\brief Интерфейс класса LogOptions
	/// \sa LanParking
	class LogOptions
	{
	public:
		tXCHAR* sinkClient;
		tXCHAR* nameTrace;
		tXCHAR* nameModule;
		tXCHAR* nameThread;

		LogOptions(const std::string& _sinkClient, const std::string& _nameTrace, const std::string& _nameModule, const std::string& _nameThread);
		~LogOptions();
	};
	typedef std::shared_ptr<LogOptions> LogOptionsPtr;

	///\brief Интерфейс класса LoggerConfig
	/// \sa LanParking
	class LoggerConfig
	{
	public:
		std::string m_name;			/// name logger

	private:
		std::string m_format;		/// set log item format for text sink
		std::string m_dir;			/// option allows to specify directory where P7 files will be created
		std::string m_roll;			/// use option to specify files rolling value
		tUINT32 m_files = 0;		/// option defines maximum P7 logs files in destination folder, in case if count of files is larger than specified value - oldest files will be removed. Default value is 0(OFF), max value – 4096. Example: “/P7.Files=4096”
		tUINT32 m_fsize = 0;		/// option defines maximum P7 logs files cumulative size in MB in destination folder
		tUINT32 m_level = 0;		/// verbosity level for all trace channels and associated modules

		void saveDefaultConfiguration();

	protected:
		// собранные поля для передачи в LoggerDevices
		LogOptionsPtr m_pFileOpt = nullptr;

	public:
		LoggerConfig(const std::string& name);
		~LoggerConfig();

		std::string& Format();
		std::string& Dir();
		std::string& Roll();
		tUINT32& MaxFileCount();
		tUINT32& MaxFileSize();
		tUINT32& Level();

		bool saveConfiguration();
		bool loadConfiguration();

		void prepareConfig();
	};

	///\brief Интерфейс класса LoggerDevice
	/// \sa LanParking
	struct LoggerDevice
	{
		LogOptionsPtr m_pOpt = nullptr;

		hP7_Client       hClient;
		hP7_Trace        hTrace;
		hP7_Trace_Module pModule;

		LoggerDevice(LogOptionsPtr pOpt);
		~LoggerDevice();
	};
	typedef std::shared_ptr<LoggerDevice> LoggerDevicePtr;

	class WrapperP7 : public LoggerConfig
	{
	public:
		WrapperP7(const std::string& name);
		~WrapperP7();

		bool init();

		void logMsg(tUINT32 level, const std::string& _what);
		void logMsg(const std::string& _where, tUINT32 level, const std::string& _what);

		void flush();
	private:
		LoggerDevicePtr m_pFile = nullptr;

		void clear();
	};
	typedef std::shared_ptr<WrapperP7> WrapperP7Ptr;

}//namespace Lanter

#endif //LAN_LOGGERLIB_WRAPERP7_H
