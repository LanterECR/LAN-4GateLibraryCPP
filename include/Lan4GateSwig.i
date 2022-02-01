//Включение фичи наследования
%module(directors="1") Lan4Gate
//Определение классов, от которых можно наследоваться
%feature("director") ICommunication;
//%feature("director") ILan4Gate;
%feature("director") RequestCallback;
%feature("director") ResponseCallback;
%feature("director") NotificationCallback;
%feature("director") InteractionCallback;
%feature("director") ConnectionCallback;

%include "windows.i"
%include "inttypes.i"
%include "std_string.i"
%include "std_vector.i"
%include "std_set.i"
%include "std_shared_ptr.i"

//Определение классов, для которых необходим shared_ptr
%shared_ptr(Lanter::Manager::ILan4Gate);
%shared_ptr(Lanter::Communication::ICommunication);
%shared_ptr(Lanter::Message::Interaction::IInteractionData);
%shared_ptr(Lanter::Message::Notification::INotificationData);
%shared_ptr(Lanter::Message::Request::IRequestData);
%shared_ptr(Lanter::Message::Response::IResponseData);

//Включение пустого дефайна для корректной отработки макроса экспорта/импорта
#define LANTER_VISIBILITY

%{
#include "Lanter/Communication/ICommunication.h"
#include "Lanter/Communication/CommunicatinFactory.h"

#include "Lanter/Message/OperationCode.h"

#include "Lanter/Message/Request/RequestField.h"
#include "Lanter/Message/Request/IRequestData.h"

#include "Lanter/Message/Response/Status.h"
#include "Lanter/Message/Response/CardInputMethod.h"
#include "Lanter/Message/Response/CardholderAuthMethod.h"
#include "Lanter/Message/Response/ResponseField.h"
#include "Lanter/Message/Response/IResponseData.h"

#include "Lanter/Message/Notification/NotificationCode.h"
#include "Lanter/Message/Notification/INotificationData.h"

#include "Lanter/Message/Interaction/InteractionCode.h"
#include "Lanter/Message/Interaction/IInteractionData.h"

#include "Lanter/Manager/Callback/RequestCallback.h"
#include "Lanter/Manager/Callback/ResponseCallback.h"
#include "Lanter/Manager/Callback/NotificationCallback.h"
#include "Lanter/Manager/Callback/InteractionCallback.h"
#include "Lanter/Manager/Callback/ConnectionCallback.h"

#include "Lanter/Manager/ILan4Gate.h"
#include "Lanter/Manager/Lan4GateFactory.h"

#include "Lanter/Utils/Version.h"
%}

namespace std {
    //Определение векторов и сетов для классов
    %template(ByteVector) vector<uint8_t>;
    //В шаблоне используется полная спецификация enum т.к. SWIG не может самостоятельно разрешить данную фишку
    %template(RequestFieldsArray) set<enum Lanter::Message::Request::RequestField>;
    %template(ResponseFieldsArray) set<enum Lanter::Message::Response::ResponseField>;
    %template(ResponseArray) vector< shared_ptr<Lanter::Message::Response::IResponseData> >;
};

%include "Lanter/Communication/ICommunication.h"
%include "Lanter/Communication/CommunicatinFactory.h"

%include "Lanter/Message/OperationCode.h"

%include "Lanter/Message/Request/RequestField.h"
%include "Lanter/Message/Request/IRequestData.h"

%include "Lanter/Message/Response/Status.h"
%include "Lanter/Message/Response/CardInputMethod.h"
%include "Lanter/Message/Response/CardholderAuthMethod.h"
%include "Lanter/Message/Response/ResponseField.h"
%include "Lanter/Message/Response/IResponseData.h"

%include "Lanter/Message/Notification/NotificationCode.h"
%include "Lanter/Message/Notification/INotificationData.h"

%include "Lanter/Message/Interaction/InteractionCode.h"
%include "Lanter/Message/Interaction/IInteractionData.h"

%include "Lanter/Manager/Callback/RequestCallback.h"
%include "Lanter/Manager/Callback/ResponseCallback.h"
%include "Lanter/Manager/Callback/NotificationCallback.h"
%include "Lanter/Manager/Callback/InteractionCallback.h"
%include "Lanter/Manager/Callback/ConnectionCallback.h"

%include "Lanter/Manager/ILan4Gate.h"
%include "Lanter/Manager/Lan4GateFactory.h"

%include "Lanter/Utils/Version.h"
