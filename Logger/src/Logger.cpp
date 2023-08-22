
#include "Logger.h"

#ifdef WIN32
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#endif // WIN32


namespace Lanter
{

    Logger::Logger()
    { ; }
    Logger::~Logger()
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger.reset();
        }
    }
    bool Logger::init(const std::string& name)
    {
        m_name = name;

        flush();
        if (!m_pWrapperLogger)
        {
            m_pWrapperLogger = std::make_shared<WrapperP7>(m_name);
            if (m_pWrapperLogger)
                m_pWrapperLogger->init();
        }

        std::string path = fs::current_path().u8string() + "/" + name;

        return !fs::exists(path) || !fs::create_directory(path);
    }
    void Logger::flush()
    {
        if (m_pWrapperLogger)
            m_pWrapperLogger->flush();
    }

    void Logger::trace(const std::string& logMessage)
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger->logMsg(P7_TRACE_LEVEL_TRACE, logMessage);
        }
    }
    void Logger::debug(const std::string& logMessage)
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger->logMsg(P7_TRACE_LEVEL_DEBUG, logMessage);
        }
    }
    void Logger::info(const std::string& logMessage)
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger->logMsg(P7_TRACE_LEVEL_INFO, logMessage);
        }
    }
    void Logger::warning(const std::string& logMessage)
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger->logMsg(P7_TRACE_LEVEL_WARNING, logMessage);
        }
    }
    void Logger::error(const std::string& logMessage)
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger->logMsg(P7_TRACE_LEVEL_ERROR, logMessage);
        }
    }
    void Logger::crit(const std::string& logMessage)
    {
        if (m_pWrapperLogger)
        {
            m_pWrapperLogger->logMsg(P7_TRACE_LEVEL_CRITICAL, logMessage);
        }
    }


}//namespace Lanter

