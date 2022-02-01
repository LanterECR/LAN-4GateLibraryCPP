%module(directors="1") Lan4Gate

%feature("director") ICommunication;
%feature("director") ILan4Gate;
%feature("director") RequestCallback;
%feature("director") ResponseCallback;
%feature("director") NotificationCallback;
%feature("director") InteractionCallback;
%feature("director") ConnectionCallback;

%include "windows.i"
//%include "inttypes.i"
%include "std_string.i"
%include "std_vector.i"
%include "std_set.i"
%include "std_shared_ptr.i"

%shared_ptr(Lanter::Manager::ILan4Gate);
%shared_ptr(Lanter::Communication::ICommunication);
%shared_ptr(Lanter::Message::Interaction::IInteractionData);
%shared_ptr(Lanter::Message::Notification::INotificationData);
%shared_ptr(Lanter::Message::Request::IRequestData);
%shared_ptr(Lanter::Message::Response::IResponseData);

#define LANTER_VISIBILITY

%{
#include "Lan4GateIncude.h"

#include "Communication/ICommunication.h"
#include "Communication/CommunicatinFactory.h"

#include "Message/OperationCode.h"

#include "Message/Request/RequestField.h"
#include "Message/Request/IRequestData.h"

#include "Message/Response/Status.h"
#include "Message/Response/CardInputMethod.h"
#include "Message/Response/CardholderAuthMethod.h"
#include "Message/Response/ResponseField.h"
#include "Message/Response/IResponseData.h"

#include "Message/Notification/NotificationCode.h"
#include "Message/Notification/INotificationData.h"

#include "Message/Interaction/InteractionCode.h"
#include "Message/Interaction/IInteractionData.h"

#include "Manager/Callback/RequestCallback.h"
#include "Manager/Callback/ResponseCallback.h"
#include "Manager/Callback/NotificationCallback.h"
#include "Manager/Callback/InteractionCallback.h"
#include "Manager/Callback/ConnectionCallback.h"

#include "Manager/ILan4Gate.h"
#include "Manager/Lan4GateFactory.h"

#include "Utils/Version.h"
%}

namespace std {
        %template(ByteVector) vector<uint8_t>;
        %template(RequestFieldsArray) set<enum Lanter::Message::Request::RequestField>;
        %template(ResponseFieldsArray) set<enum Lanter::Message::Response::ResponseField>;
        %template(ResponseArray) vector< shared_ptr<Lanter::Message::Response::IResponseData> >;
};



%include "Lan4GateIncude.h"

%include "Communication/ICommunication.h"
%include "Communication/CommunicatinFactory.h"

%include "Message/OperationCode.h"

%include "Message/Request/RequestField.h"
%include "Message/Request/IRequestData.h"

%include "Message/Response/Status.h"
%include "Message/Response/CardInputMethod.h"
%include "Message/Response/CardholderAuthMethod.h"
%include "Message/Response/ResponseField.h"
%include "Message/Response/IResponseData.h"

%include "Message/Notification/NotificationCode.h"
%include "Message/Notification/INotificationData.h"

%include "Message/Interaction/InteractionCode.h"
%include "Message/Interaction/IInteractionData.h"

%include "Manager/Callback/RequestCallback.h"
%include "Manager/Callback/ResponseCallback.h"
%include "Manager/Callback/NotificationCallback.h"
%include "Manager/Callback/InteractionCallback.h"
%include "Manager/Callback/ConnectionCallback.h"

%include "Manager/ILan4Gate.h"
%include "Manager/Lan4GateFactory.h"

%include "Utils/Version.h"
