#ifndef TESTL4G_COMMUNICATINFACTORY_H
#define TESTL4G_COMMUNICATINFACTORY_H

#include <memory>

#include "ICommunication.h"

namespace Lanter {
    namespace Communication {
        std::shared_ptr<ICommunication> getSingleTcpServer(int port = 20501);
    }
}
#endif //TESTL4G_COMMUNICATINFACTORY_H
