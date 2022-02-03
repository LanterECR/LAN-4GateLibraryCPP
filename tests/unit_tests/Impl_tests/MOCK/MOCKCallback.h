#ifndef LAN_4GATELIB_MOCKCALLBACK_H
#define LAN_4GATELIB_MOCKCALLBACK_H

#include "Lanter/Manager/Callback/IRequestCallback.h"
#include "Lanter/Manager/Callback/IResponseCallback.h"
#include "Lanter/Manager/Callback/INotificationCallback.h"
#include "Lanter/Manager/Callback/IInteractionCallback.h"
#include "Lanter/Manager/Callback/IConnectionCallback.h"

namespace Lanter {
    class MOCKRequestCallback : public Manager::Callback::IRequestCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Request::IRequestData>), (override));
    };

    class MOCKResponseCallback : public Manager::Callback::IResponseCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Response::IResponseData>), (override));
    };

    class MOCKNotificationCallback : public Manager::Callback::INotificationCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Notification::INotificationData>), (override));
    };

    class MOCKInteractionCallback : public Manager::Callback::IInteractionCallback {
    public:
        MOCK_METHOD((void), newData, (std::shared_ptr<Message::Interaction::IInteractionData>), (override));
    };

    class MOCKConnectionCallback : public Manager::Callback::IConnectionCallback {
    public:
        MOCK_METHOD((void), newState, (bool));
    };
}
#endif //LAN_4GATELIB_MOCKCALLBACK_H
