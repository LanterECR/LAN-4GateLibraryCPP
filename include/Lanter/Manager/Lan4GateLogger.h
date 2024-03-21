#ifndef LAN_4GATELIB_LAN4GATELOGGER_H
#define LAN_4GATELIB_LAN4GATELOGGER_H

#include "Lanter/Utils/VisibilityMacroses.h"
#include "Callback/ILoggerCallback.h"

#include <sstream>

#ifndef LIB_LOG_FUNCTION
#	ifdef _MSC_VER
#		define LIB_LOG_FUNCTION __FUNCTION__
#	else
#		define LIB_LOG_FUNCTION __PRETTY_FUNCTION__
#	endif
#endif

namespace Lanter
{
    namespace Manager
    {
        /// \brief Класс для логирования
        class LANTER_VISIBILITY Lan4GateLogger
        {
        public:
            /// \brief добавляет callback
            static void addLoggerCallback(Callback::ILoggerCallback& callback);
            /// \brief выводит в лог
            static void toLog(const char* text);
        };

        class LogTracer
        {
        public:
            explicit LogTracer(const char* func) : m_func(func)
            {
                Lan4GateLogger::toLog(std::string("-->" + m_func).c_str());
            }

            ~LogTracer()
            {
                Lan4GateLogger::toLog(std::string("<--" + m_func).c_str());
            }

        private:
            std::string m_func;
        };
    }
}

#define LOG_STREAM std::stringstream stream; stream
#define LOG_TRACE Lanter::Manager::LogTracer    log_tracer(LIB_LOG_FUNCTION);
#define LOG_DEBUG(arg)                          { arg; Lanter::Manager::Lan4GateLogger::toLog(stream.str().c_str()); }
#endif //LAN_4GATELIB_LAN4GATELOGGER_H