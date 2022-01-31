%module(directors="1") Lan4Gate
%feature("director") ICommunication;
%feature("director") ILan4Gate;
%feature("director") Test;

%include "windows.i"
%include "inttypes.i"
%include "std_string.i"
%include "std_vector.i"
%include "std_shared_ptr.i"

%shared_ptr(Lanter::Manager::ILan4Gate);
%shared_ptr(Lanter::Communication::ICommunication);
%shared_ptr(Lanter::Message::Interaction::IInteractionData);
%shared_ptr(Lanter::Message::Notification::INotificationData);
%shared_ptr(Lanter::Message::Request::IRequestData);
%shared_ptr(Lanter::Message::Response::IResponseData);

#define LANTER_VISIBILITY

// top-level C++ implementation file
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
#include "Message/Interaction/IInteractionData.h"
#include "Manager/ILan4Gate.h"
#include "Manager/Lan4GateFactory.h"
#include "Utils/Version.h"
%}

namespace std {
        %template(ByteVector) vector<uint8_t>;
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
%include "Message/Interaction/IInteractionData.h"
%include "Manager/ILan4Gate.h"
%include "Manager/Lan4GateFactory.h"
%include "Utils/Version.h"

