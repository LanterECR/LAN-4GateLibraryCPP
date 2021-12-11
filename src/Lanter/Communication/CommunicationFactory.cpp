#include "Lanter/Communication/CommunicatinFactory.h"

#include "Lanter/Communication/TCP/Server/SingleTCPServer.h"
#include "Lanter/Communication/Decorators/SizeControlDecorator.h"

namespace Lanter {
    namespace Communication {
        std::shared_ptr<ICommunication> CommunicationFactory::getSingleTcpServer(int port) {
            return std::make_shared<SingleTCPServer>(port);
        }

        std::shared_ptr<ICommunication> CommunicationFactory::getSizeControlDecorator(std::shared_ptr<ICommunication> communication) {
            return std::make_shared<SizeControlDecorator>(communication);
        }
    }
}