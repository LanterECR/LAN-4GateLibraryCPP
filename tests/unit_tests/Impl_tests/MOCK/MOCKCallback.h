#ifndef LAN_4GATELIB_MOCKCALLBACK_H
#define LAN_4GATELIB_MOCKCALLBACK_H

#include "Lanter/Manager/Callback/RequestCallback.h"
#include "Lanter/Manager/Callback/ResponseCallback.h"
#include "Lanter/Manager/Callback/NotificationCallback.h"
#include "Lanter/Manager/Callback/InteractionCallback.h"
#include "Lanter/Manager/Callback/ConnectionCallback.h"

namespace Lanter {
    class MOCKRequestCallback : public Manager::Callback::RequestCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Request::IRequestData>), (override));
    };

    class MOCKResponseCallback : public Manager::Callback::ResponseCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Response::IResponseData>), (override));
    };

    class MOCKNotificationCallback : public Manager::Callback::NotificationCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Notification::INotificationData>), (override));
    };

    class MOCKInteractionCallback : public Manager::Callback::InteractionCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Interaction::IInteractionData>), (override));
    };

    class MOCKConnectionCallback : public Manager::Callback::ConnectionCallback {
    public:
        MOCK_METHOD((void), newState, (bool));
    };
}
#endif //LAN_4GATELIB_MOCKCALLBACK_H
