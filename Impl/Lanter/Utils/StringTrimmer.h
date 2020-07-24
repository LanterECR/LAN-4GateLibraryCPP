#ifndef LAN_4GATELIBRARYCPP_STRINGTRIMMER_H
#define LAN_4GATELIBRARYCPP_STRINGTRIMMER_H

#include <algorithm>
#include <cctype>
#include <locale>

namespace Lanter {
    namespace Utils {

        void ltrim(std::string &s);

        void rtrim(std::string &s);

        void trim(std::string &s);
    }
}

#endif //LAN_4GATELIBRARYCPP_STRINGTRIMMER_H
