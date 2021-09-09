#include "Lanter/Manager/Lan4GateFactory.h"

#include "Lanter/Manager/Lan4Gate.h"

namespace Lanter {
    namespace Manager {

        std::shared_ptr<ILan4Gate> getLan4Gate(int ecrNumber, std::shared_ptr<Communication::ICommunication> communication) {
            std::shared_ptr<ILan4Gate> lan4Gate = std::make_shared<Lan4Gate>();
            if(lan4Gate != nullptr) {
                lan4Gate->setEcrNumber(ecrNumber);
                lan4Gate->setCommunication(communication);
            }
            return lan4Gate;
        }
    }
}