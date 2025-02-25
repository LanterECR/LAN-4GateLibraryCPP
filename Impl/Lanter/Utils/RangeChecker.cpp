#include "RangeChecker.h"

namespace Lanter
{
    namespace Utils
    {
        bool checkValueRange(int64_t value, int64_t min, int64_t max)
        {
            return (value >= min && value <= max);
        }
    }
}