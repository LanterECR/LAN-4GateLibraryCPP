#ifndef LAN_LPCLIB_ILOGGER_H
#define LAN_LPCLIB_ILOGGER_H

#include <string>
#include <sstream>
#include <memory>

#ifndef LPC_FUNCTION
#	ifdef _MSC_VER
#		define LPC_FUNCTION __FUNCTION__
#	else
#		define LPC_FUNCTION __PRETTY_FUNCTION__
#	endif
#endif

///\brief Для организации потокового вывода в Logger
/// \sa LanParking
class StreamLogger final
{
public:
    StreamLogger(const std::string& funtionName = "") :
        m_funtionName(funtionName)
    { ; }
    template<typename T> StreamLogger& operator<<(const T& t)
    {
        m_ss << t;
        return *this;
    }
    operator std::string() const
    {
        return m_funtionName.empty() ? m_ss.str() : m_funtionName + "(): [" + m_ss.str() + "]";
    }
private:
    std::stringstream m_ss;
    std::string m_funtionName;
};
#define LOG_STREAM      StreamLogger()
#define LOG_STREAM_FUNC StreamLogger(LPC_FUNCTION)

namespace Lanter
{
    ///\brief Интерфейс класса Logger
    /// \sa LanParking
    class ILogger
    {
    private:
    public:
        /// \brief Инициализация ILogger
        /// \param[in] name имя Logger, расположение файла будет по пути исполняемого файла и имени логера
        /// \return результат инициализации
        virtual bool init(const std::string& name) = 0;

        /// \brief вывод строки в лог trace
        /// \param[in] logMessage сообщение для логирования
        virtual void trace(const std::string& logMessage) = 0;

        /// \brief вывод строки в лог debug
        /// \param[in] logMessage сообщение для логирования
        virtual void debug(const std::string& logMessage) = 0;

        /// \brief вывод строки в лог info
        /// \param[in] logMessage сообщение для логирования
        virtual void info(const std::string& logMessage) = 0;

        /// \brief вывод строки в лог warning
        /// \param[in] logMessage сообщение для логирования
        virtual void warning(const std::string& logMessage) = 0;

        /// \brief вывод строки в лог error
        /// \param[in] logMessage сообщение для логирования
        virtual void error(const std::string& logMessage) = 0;

        /// \brief вывод строки в лог critical
        /// \param[in] logMessage сообщение для логирования
        virtual void crit(const std::string& logMessage) = 0;

        /// \brief при асинхранном логере, немедленно скинет на диск
        /// \param[in] logMessage сообщение для логирования
        virtual void flush() = 0;

    };//class ILogger
    typedef std::shared_ptr<ILogger> LoggerPtr;

    class TracingLog
    {
    private:
        LoggerPtr m_loggerPtr;
        std::string m_where;
        unsigned char m_level;
    public:
        TracingLog(LoggerPtr loggerPtr, const unsigned char level, const std::string& _where) :
            m_loggerPtr(loggerPtr), m_level(level), m_where(_where)
        {
            if (m_loggerPtr)
            {
                switch (m_level)
                {
                case 0x01:
                    m_loggerPtr->debug(LOG_STREAM << "> " + m_where);
                    break;
                default:
                    m_loggerPtr->trace(LOG_STREAM << "> " + m_where);
                }
            }
        }
        ~TracingLog()
        {
            if (m_loggerPtr)
            {
                switch (m_level)
                {
                case 0x01:
                    m_loggerPtr->debug(LOG_STREAM << "< " + m_where);
                    break;
                default:
                    m_loggerPtr->trace(LOG_STREAM << "< " + m_where);
                }
            }
        }
    };

#define LOG_TRACE(logger) TracingLog tracingLog(logger, 0x00, LPC_FUNCTION);
#define LOG_DEBUG(logger) TracingLog tracingLog(logger, 0x01, LPC_FUNCTION);

}//namespace Lanter

#endif //LAN_LPCLIB_ILOGGER_H
