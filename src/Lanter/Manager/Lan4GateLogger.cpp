#include "Lanter/Manager/Lan4GateLogger.h"
#include <unordered_map>

namespace Lanter {
    namespace Manager {

        static std::unordered_map<size_t, Callback::ILoggerCallback&> m_callbackLogger;

        void Lan4GateLogger::addLoggerCallback(Callback::ILoggerCallback& callback) {
            m_callbackLogger.emplace(0, callback);
        }
        void Lan4GateLogger::toLog(const char* text) {
            for (const auto& callback : m_callbackLogger) {
                callback.second.message(text);
            }
        }

    }
}