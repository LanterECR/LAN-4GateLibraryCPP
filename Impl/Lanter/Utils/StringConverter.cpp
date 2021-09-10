#include "StringConverter.h"

#include <iterator>

namespace Lanter {
    namespace Utils {
        bool StringConverter::convertToString(const std::vector<uint8_t> & data, std::string &result) {
            result.clear();
            std::copy(data.begin(), data.end(), std::back_inserter(result));
            return !result.empty();
        }

        bool StringConverter::convertToVector(const std::string & data, std::vector<uint8_t> & result) {
            result.clear();
            std::copy(data.begin(), data.end(), std::back_inserter(result));
            return !result.empty();
        }
    }
}