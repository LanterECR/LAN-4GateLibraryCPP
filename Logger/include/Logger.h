#ifndef LAN_LOGGERLIB_LOGGER_H
#define LAN_LOGGERLIB_LOGGER_H

#include <ILogger.h>
#include "WrapperLogger.h"

namespace Lanter
{
    /// Использование Logger
    /// Logger.debug("Hello world !!!");                            // вывод строки в лог
    /// Logger.debug(LOG_STREAM << "Hello world" << " !!!");        // потоковый вывод
    /// Logger.debug(LOG_STREAM_FUNC << "Hello world" << " !!!");   // потоковый вывод с указанием функции, которая выводит сообщение

    ///\brief Интерфейс класса Logger
    /// \sa LanParking
    class Logger: public ILogger
    {
    public:
        Logger();
        ~Logger();
        /// \brief инициализация Logger
        /// \param[in] name имя Logger
        bool init(const std::string& name);

        /// \brief вывод строки в лог trace
        /// \param[in] logMessage сообщение для логирования
        virtual void trace(const std::string& logMessage);

        /// \brief вывод строки в лог debug
        /// \param[in] logMessage сообщение для логирования
        virtual void debug(const std::string& logMessage);

        /// \brief вывод строки в лог info
        /// \param[in] logMessage сообщение для логирования
        virtual void info(const std::string& logMessage);

        /// \brief вывод строки в лог warning
        /// \param[in] logMessage сообщение для логирования
        virtual void warning(const std::string& logMessage);

        /// \brief вывод строки в лог error
        /// \param[in] logMessage сообщение для логирования
        virtual void error(const std::string& logMessage);

        /// \brief вывод строки в лог critical
        /// \param[in] logMessage сообщение для логирования
        virtual void crit(const std::string& logMessage);

        /// \brief при асинхранном логере, немедленно скинет на диск
        virtual void flush();

    private:
        std::string m_name;
        WrapperLoggerPtr m_pWrapperLogger = 0;
    };//class Logger

}//namespace Lanter

#endif //LAN_LOGGERLIB_LOGGER_H
