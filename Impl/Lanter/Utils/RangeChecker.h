#ifndef LAN_4GATELIBRARYCPP_RANGECHECKER_H
#define LAN_4GATELIBRARYCPP_RANGECHECKER_H

#include <cstdint>
#include <string>

namespace Lanter
{
    namespace Utils
    {
        bool checkValueRange(int64_t value, int64_t min, int64_t max);
    }
}
#endif //LAN_4GATELIBRARYCPP_RANGECHECKER_H