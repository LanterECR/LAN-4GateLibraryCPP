//
// Created by Владимир Лысенков on 13.07.2020.
//

#include "StringConverter.h"

namespace Lanter {
    namespace Utils {
        bool StringConverter::convertToString(const std::vector<unsigned char> & data, std::string &result) {
            result.clear();
            std::copy(data.begin(), data.end(), std::back_inserter(result));
            return !result.empty();
        }

        bool StringConverter::convertToVector(const std::string & data, std::vector<unsigned char> & result) {
            result.clear();
            std::copy(data.begin(), data.end(), std::back_inserter(result));
            return !result.empty();
        }
    }
}