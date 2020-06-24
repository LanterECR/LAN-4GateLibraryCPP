//
// Created by Владимир Лысенков on 24.06.2020.
//
#include "RangeChecker.h"

#include <exception>
#include <sstream>
namespace Lanter {
    namespace Utils {
        bool checkValueRange(int64_t value, int64_t min, int64_t max) {
            if (value < min || value > max) {
                std::string message;
                createRangeMessage(value, min, max, message);
                throw std::invalid_argument(message);
            }
            return true;
        }

        void createRangeMessage(int64_t value, int64_t min, int64_t max, std::string &outputMessage) {
            std::stringstream messageStream;
            messageStream << value << " is invalid value.";
            messageStream << "Correct value in range starts from " << min << " to " << max;
            outputMessage = messageStream.str();
        }
    }
}
