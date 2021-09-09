#ifndef LAN_4GATELIB_LAN4GATEFACTORY_H
#define LAN_4GATELIB_LAN4GATEFACTORY_H

#include <memory>

#include "ILan4Gate.h"
#include "Lanter/Communication/ICommunication.h"

namespace Lanter {
    namespace Manager {
        std::shared_ptr<ILan4Gate> getLan4Gate(int ecrNumber, std::shared_ptr<Communication::ICommunication> communication = nullptr);
    }
}

#endif //LAN_4GATELIB_LAN4GATEFACTORY_H
