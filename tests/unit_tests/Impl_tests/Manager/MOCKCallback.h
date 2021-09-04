#ifndef LAN_4GATELIB_MOCKCALLBACK_H
#define LAN_4GATELIB_MOCKCALLBACK_H
#include "memory"

#include "Lanter/Message/Request/IRequestData.h"
#include "Lanter/Message/Response/IResponseData.h"
#include "Lanter/Message/Notification/INotificationData.h"

namespace Lanter {
    class MOCKCallback {
    public:
        MOCK_METHOD((void), requestCallback, (std::shared_ptr<IRequestData>));
        MOCK_METHOD((void), responseCallback, (std::shared_ptr<IResponseData>));
        MOCK_METHOD((void), notificationCallback, (std::shared_ptr<INotificationData>));
    };
}
#endif //LAN_4GATELIB_MOCKCALLBACK_H
