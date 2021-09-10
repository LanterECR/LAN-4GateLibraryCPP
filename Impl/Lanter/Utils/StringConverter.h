#ifndef LAN_4GATELIBRARYCPP_STRINGCONVERTER_H
#define LAN_4GATELIBRARYCPP_STRINGCONVERTER_H

#include <string>
#include <vector>

namespace Lanter {
    namespace Utils {
        class StringConverter {
        public:
            static bool convertToString(const std::vector<uint8_t> & data, std::string & result);
            static bool convertToVector(const std::string & data, std::vector<uint8_t> & result);
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_STRINGCONVERTER_H
