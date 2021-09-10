#include "Lanter/Communication/CommunicatinFactory.h"

#include "Lanter/Communication/SingleTCPServer.h"

namespace Lanter {
    namespace Communication {
        std::shared_ptr<ICommunication> getSingleTcpServer(int port) {
            return std::make_shared<SingleTCPServer>(port);
        }
    }
}