//
// Created by Владимир Лысенков on 24.06.2020.
//
#include "RangeChecker.h"

#include <exception>
#include <sstream>
namespace Lanter {
    namespace Utils {
        bool checkValueRange(int64_t value, int64_t min, int64_t max) {
            return value >= min && value <= max;
        }
    }
}
