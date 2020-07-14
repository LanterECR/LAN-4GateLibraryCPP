//
// Created by Владимир Лысенков on 13.07.2020.
//

#ifndef LAN_4GATELIBRARYCPP_STRINGCONVERTER_H
#define LAN_4GATELIBRARYCPP_STRINGCONVERTER_H

#include <string>
#include <vector>

namespace Lanter {
    namespace Utils {
        class StringConverter {
        public:
            static bool convertToString(const std::vector<unsigned char> & data, std::string & result);
            static bool convertToVector(const std::string & data, std::vector<unsigned char> & result);
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_STRINGCONVERTER_H
