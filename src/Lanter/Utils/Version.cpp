#include "Lanter/Utils/Version.h"

namespace Lanter {
    namespace Utils {

        const std::string &getVersion() {
            static std::string version(L4G_VERSION);

            return version;
        }
    }
}
