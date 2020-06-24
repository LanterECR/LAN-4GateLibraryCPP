//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_RANGECHECKER_H
#define LAN_4GATELIBRARYCPP_RANGECHECKER_H

#include <cstdint>
#include <string>

namespace Lanter {
    namespace Utils {
        bool checkValueRange(int64_t value, int64_t min, int64_t max);
        void createRangeMessage(int64_t value, int64_t min, int64_t max, std::string &outputMessage);
    }
}
#endif //LAN_4GATELIBRARYCPP_RANGECHECKER_H
