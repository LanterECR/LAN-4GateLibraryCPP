//Включение фичи наследования
%module(directors="1") Lan4Gate
//Определение классов, от которых можно наследоваться
%feature("director") ICommunication;
%feature("director") IRequestCallback;
%feature("director") IResponseCallback;
%feature("director") INotificationCallback;
%feature("director") IInterfaceCallback;
%feature("director") IGatewayCallback;
%feature("director") IInteractionCallback;
%feature("director") IReceiptCallback;
%feature("director") IConnectionCallback;
%feature("director") ILoggerCallback;

%include "windows.i"
%include "inttypes.i"
%include "std_string.i"
%include "std_vector.i"
%include "std_set.i"
%include "std_shared_ptr.i"
%include "enums.swg"

//Определение классов, для которых необходим shared_ptr
%shared_ptr(Lanter::Manager::ILan4Gate);
%shared_ptr(Lanter::Communication::ICommunication);
%shared_ptr(Lanter::Message::Interaction::IInteractionData);
%shared_ptr(Lanter::Message::Receipt::IReceiptData);
%shared_ptr(Lanter::Message::Notification::INotificationData);
%shared_ptr(Lanter::Message::Interface::IInterfaceData);
%shared_ptr(Lanter::Message::Gateway::IGatewayData);
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

#include "Lanter/Message/Interface/InterfaceType.h"
#include "Lanter/Message/Interface/IInterfaceData.h"

#include "Lanter/Message/Gateway/GatewayCode.h"
#include "Lanter/Message/Gateway/IGatewayData.h"

#include "Lanter/Message/Interaction/InteractionCode.h"
#include "Lanter/Message/Interaction/IInteractionData.h"

#include "Lanter/Message/Receipt/ReceiptCode.h"
#include "Lanter/Message/Receipt/IReceiptData.h"

#include "Lanter/Manager/Callback/IRequestCallback.h"
#include "Lanter/Manager/Callback/IResponseCallback.h"
#include "Lanter/Manager/Callback/INotificationCallback.h"
#include "Lanter/Manager/Callback/IInterfaceCallback.h"
#include "Lanter/Manager/Callback/IGatewayCallback.h"
#include "Lanter/Manager/Callback/IInteractionCallback.h"
#include "Lanter/Manager/Callback/IReceiptCallback.h"
#include "Lanter/Manager/Callback/IConnectionCallback.h"
#include "Lanter/Manager/Callback/ILoggerCallback.h"

#include "Lanter/Manager/ILan4Gate.h"
#include "Lanter/Manager/Lan4GateLogger.h"
#include "Lanter/Manager/Lan4GateFactory.h"

#include "Lanter/Utils/Version.h"
%}

namespace std {
    //Определение векторов и сетов для классов
    //В Java тип byte имеет диапазон от -128 до 127, а uint8_t в C++ имеет диапазон от 0 до 255. Поэтому при преобразовании byte будет в short
    //Используем int8_t
    %template(ByteVector) vector<int8_t>;
    //В шаблоне используется полная спецификация enum т.к. SWIG не может самостоятельно разрешить данную фишку
    %template(RequestFieldsArray) set<enum Lanter::Message::Request::RequestField>;
    %template(ResponseFieldsArray) set<enum Lanter::Message::Response::ResponseField>;
    %template(ResponseArray) vector< shared_ptr<Lanter::Message::Response::IResponseData> >;
    %template(ReceiptArray) vector<string>;
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

%include "Lanter/Message/Interface/InterfaceType.h"
%include "Lanter/Message/Interface/IInterfaceData.h"

%include "Lanter/Message/Gateway/GatewayCode.h"
%include "Lanter/Message/Gateway/IGatewayData.h"

%include "Lanter/Message/Interaction/InteractionCode.h"
%include "Lanter/Message/Interaction/IInteractionData.h"

%include "Lanter/Message/Receipt/ReceiptCode.h"
%include "Lanter/Message/Receipt/IReceiptData.h"

%include "Lanter/Manager/Callback/IRequestCallback.h"
%include "Lanter/Manager/Callback/IResponseCallback.h"
%include "Lanter/Manager/Callback/INotificationCallback.h"
%include "Lanter/Manager/Callback/IInterfaceCallback.h"
%include "Lanter/Manager/Callback/IGatewayCallback.h"
%include "Lanter/Manager/Callback/IInteractionCallback.h"
%include "Lanter/Manager/Callback/IReceiptCallback.h"
%include "Lanter/Manager/Callback/IConnectionCallback.h"
%include "Lanter/Manager/Callback/ILoggerCallback.h"

%include "Lanter/Manager/ILan4Gate.h"
%include "Lanter/Manager/Lan4GateLogger.h"
%include "Lanter/Manager/Lan4GateFactory.h"

%include "Lanter/Utils/Version.h"