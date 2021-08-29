#ifndef LAN_4GATELIBRARYCPP_IRESPONSEDATA_H
#define LAN_4GATELIBRARYCPP_IRESPONSEDATA_H

#include <cstdint>
#include <string>
#include <set>
#include <vector>
#include <memory>


#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/OperationCode.h"

#include "ResponseField.h"
#include "CardholderAuthMethod.h"
#include "CardInputMethod.h"
#include "Status.h"


namespace Lanter {
    namespace Message {
        namespace Response {
            ///\brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class LANTER_VISIBILITY IResponseData {
            public:
                virtual ~IResponseData() = default;

                /// \brief Возвращает список установленных полей
                /// \return Список установленных полей
                /// \sa ResponseField
                virtual const std::set<ResponseField> &getFieldsSet() const = 0;

                /// \brief Проверяет было ли установлено поле
                /// \param[in] field Поле, которое необходимо проверить
                /// \return true, если поле было установлено
                virtual bool isFieldSet(ResponseField field) const = 0;

                // \brief Устанавливает значение по умолчанию для поля и удаляет из списка установленных полей
                /// \param[in] field Поле, которое необходимо удалить
                /// \return true, если поле успешно удалено
                virtual bool resetField(ResponseField field) = 0;

                /// \brief Возвращает список обязательных полей для выполненной операции
                /// \return Список обязательных полей
                /// \sa ResponseField
                virtual const std::set<ResponseField> &getMandatoryFields() const = 0;

                /// \brief Возвращает список опциональных полей для выполненной операции
                /// \return Список опциональных полей
                /// \sa ResponseField
                virtual const std::set<ResponseField> &getOptionalFields() const = 0;

                /// \brief Проверяет наличие обязательных полей.
                /// \return true - если все обязательные поля установлены.
                virtual bool validateMandatoryFields() const = 0;

                /// \brief Возвращает логический идентификатор кассового ПО
                /// \return Если поле установлено - логический идентификатор кассового ПО, иначе -1
                virtual int16_t getEcrNumber() const = 0;

                /// \brief Устанавливает лоический иденитфикатор кассового ПО
                /// \param[in] ecrNumber Логический идентификатор кассового ПО в диапазоне [1, 999]
                /// \return true, если поле успешно установлено
                virtual bool setEcrNumber(int16_t ecrNumber) = 0;

                /// \brief Устанавливает значение по умолчанию для поля EcrNumber
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetEcrNumber() = 0;

                /// \brief Возвращает логический идентификатор мерчанта в кассовом ПО
                /// \return Если поле установлено - логический идентификатор мерчанта в кассовом ПО, иначе -1
                virtual int16_t getEcrMerchantNumber() const = 0;

                /// \brief Устанавливает лоический иденитфикатор мерчанта в кассовом ПО
                /// \param[in] ecrMerchantNumber Логический идентификатор мерчанта в кассовом в диапазоне [1, 999]
                /// \return true, если поле успешно установлено
                virtual bool setEcrMerchantNumber(int16_t ecrMerchantNumber) = 0;

                /// \brief Устанавливает значение по умолчанию для поля EcrMerchantNumber
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetEcrMerchantNumber() = 0;

                /// \brief Возвращает код выполненной операции
                /// \return Если поле установлено, возвращает код операции. Иначе NoOperation
                /// \sa OperationCode
                virtual OperationCode getOperationCode() const = 0;

                /// \brief Устанавливает код выполнямой операции
                /// \param[in] operationCode Значение из перечислений OperationCode, за исключением NoOperation
                /// \sa OperationCode
                /// \return true, если поле успешно установлено
                virtual bool setOperationCode(OperationCode operationCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля OperationCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetOperationCode() = 0;

                /// \brief Возвращает код оригинальной операции
                /// \return Если поле установлено, возвращает код оригинальной операции. Иначе NoOperation
                /// \sa OperationCode
                virtual OperationCode getOriginalOperationCode() const = 0;

                /// \brief Устанавливает код оригинальной операции
                /// \param[in] originalOperationCode Значение из перечислений OperationCode, за исключением NoOperation
                /// \sa OperationCode
                /// \return true, если поле успешно установлено
                virtual bool setOriginalOperationCode(OperationCode originalOperationCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля OriginalOperationCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetOriginalOperationCode() = 0;

                /// \brief Возвращает общую суммы выполненной.
                /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getTotalAmount() const = 0;

                /// \brief Устанавливает сумму в минимальных единицах валюты (копейки для рублей)
                /// \param[in] totalAmount Значение суммы в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setTotalAmount(int64_t totalAmount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TotalAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTotalAmount() = 0;

                /// \brief Возвращает частичную сумму операции в минимальных единицах валюты (копейки для рублей)
                /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getPartialAmount() const = 0;

                /// \brief Устанавливает частичную сумму в минимальных единицах валюты (копейки для рублей)
                /// \param[in] partialAmount Значение суммы в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setPartialAmount(int64_t partialAmount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля PartialAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetPartialAmount() = 0;

                /// \brief Возвращает сумму комиссии эквайера
                /// \return Если поле установлено - значение суммы комиссии в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getAcquirerFeeAmount() const = 0;

                /// \brief Устанавливает сумму комиссии эквайера
                /// \param[in] amountAcquirerFee Значение суммы в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setAcquirerFeeAmount(int64_t amountAcquirerFee) = 0;

                /// \brief Устанавливает значение по умолчанию для поля AcquirerFeeAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAcquirerFeeAmount() = 0;

                /// \brief Возвращает сумму комиссии терминала
                /// \return Если поле установлено - значение суммы комиссии в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getTerminalFeeAmount() const = 0;

                /// \brief Устанавливает сумму комиссии терминала
                /// \param[in] amountTerminalFee Значение суммы в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setTerminalFeeAmount(int64_t amountTerminalFee) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TerminalFeeAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTerminalFeeAmount() = 0;

                /// \brief Возвращает сумму чаевых
                /// \return Если поле установлено - значение суммы чаевых в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getTipsAmount() const = 0;

                /// \brief Устанавливает сумму чаевых
                /// \param[in] tipsAmount Значение суммы в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setTipsAmount(int64_t tipsAmount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TipsAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTipsAmount() = 0;

                /// \brief Возвращает код валюты согласно ISO 4217
                /// \return Если поле установлено - значение кода валюты в диапазоне [0, 999]. Иначе -1
                virtual int16_t getCurrencyCode() const = 0;

                /// \brief Устанавливает код валюты согласно ISO 4217
                /// \param[in] currencyCode значение кода валюты в диапазоне [0, 999]
                /// \return true, если поле успешно установлено
                virtual bool setCurrencyCode(int16_t currencyCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CurrencyCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCurrencyCode() = 0;

                /// \brief Возвращает номер чека в финансовом ПО LAN-4Tap
                /// \return Строка, содержащая номер чека.
                virtual const std::string &getReceiptReference() const = 0;

                /// \brief Устанавливает номер чека в финансовом ПО LAN-4Tap
                /// \param[in] receiptReference строка, содержащая номер чека
                /// \return true, если поле успешно установлено
                virtual bool setReceiptReference(const std::string &receiptReference) = 0;

                /// \brief Устанавливает значение по умолчанию для поля ReceiptReference
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetReceiptReference() = 0;

                /// \brief Возвращает RRN операции
                /// \return Строка, содержащая RRN операции
                virtual const std::string &getRRN() const = 0;

                /// \brief Устанавливает RRN операции
                /// \param[in] rrn Строка, содержащая RRN операции
                /// \return true, если поле успешно установлено
                virtual bool setRRN(const std::string &rrn) = 0;

                /// \brief Устанавливает значение по умолчанию для поля RRN
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetRRN() = 0;

                /// \brief Возвращает статус операции
                /// \return Значение из перечисления Status. Если поле не установлено - NoStatus
                virtual Status getStatus() const = 0;

                /// \brief Устанавливает статус операции
                /// \param[in] status Значение из перечисления Status, за исключением NoStatus
                /// \return true, если поле успешно установлено
                virtual bool setStatus(Status status) = 0;

                /// \brief Устанавливает значение по умолчанию для поля Status
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetStatus() = 0;

                /// \brief Возвращает статус ранее выполненной операции
                /// \return Значение из перечисления Status. Если поле не установлено - NoStatus
                virtual Status getOriginalOperationStatus() const = 0;

                /// \brief Устанавливает статус ранее выполненной операции
                /// \param[in] originalOperationStatus Значение из перечисления Status, за исключением NoStatus
                /// \return true, если поле успешно установлено
                virtual bool setOriginalOperationStatus(Status originalOperationStatus) = 0;

                /// \brief Устанавливает значение по умолчанию для поля OriginalOperationStatus
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetOriginalOperationStatus() = 0;

                /// \brief Возвращает время выполнения операции на хосте
                /// \return Строка формата YYYYMMDDHHMMSS, содержащая время выполнения операции на хосте
                virtual const std::string &getTransDateTime() const = 0;

                /// \brief Устанавливает время выполнения операции на хосте
                /// \param[in] transDateTime Строка формата YYYYMMDDHHMMSS, содержащая время выполнения операции на хосте
                /// \return true, если поле успешно установлено
                virtual bool setTransDateTime(const std::string &transDateTime) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TransDateTime
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTransDateTime() = 0;

                /// \brief Возвращает время выполнения операции в финансовом ПО LAN-4Tap
                /// \return Строка формата YYYYMMDDHHMMSS, содержащая время выполнения операции в финансовом ПО LAN-4Tap
                virtual const std::string &getTerminalDateTime() const = 0;

                /// \brief Устанавливает время выполнения операции в финансовом ПО LAN-4Tap
                /// \param[in] terminalDateTime Строка формата YYYYMMDDHHMMSS, содержащая время выполнения операции в финансовом ПО LAN-4Tap
                /// \return true, если поле успешно установлено
                virtual bool setTerminalDateTime(const std::string &terminalDateTime) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TerminalDateTime
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTerminalDateTime() = 0;

                /// \brief Возвращает маскированный PAN карты
                /// \return строка, содержащая маскированный PAN
                virtual const std::string &getCardPAN() const = 0;

                /// \brief Устанавливает маскированный PAN карты
                /// \param[in] cardPan строка, содержащая маскированный PAN
                /// \return true, если поле успешно установлено
                virtual bool setCardPAN(const std::string &cardPan) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardPAN
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardPAN() = 0;

                /// \brief Возвращает срок действия карты
                /// \return Строка формата YYMM, содержащая срок действия карты
                virtual const std::string &getExpireDate() const = 0;

                /// \brief Устанавливает срок действия карты
                /// \param[in] expireDate Строка формата YYMM, содержащая срок действия карты
                /// \return true, если поле успешно установлено
                virtual bool setExpireDate(const std::string &expireDate) = 0;

                /// \brief Устанавливает значение по умолчанию для поля ExpireDate
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetExpireDate() = 0;

                /// \brief Возвращает имя держателя карты
                /// \return Строка, содержщая имя держателя карты
                virtual const std::string &getCardholderName() const = 0;

                /// \brief Устанавливает имя держателя карты
                /// \param[in] cardholderName Строка, содержащая имя держателя карты
                /// \return true, если поле успешно установлено
                virtual bool setCardholderName(const std::string &cardholderName) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardholderName
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardholderName() = 0;

                /// \brief Возвращает способ авторизации держателя карты
                /// \return Значение из перечисления CardholderAuthMethod. Если поле не установлено - NoMethod
                virtual CardholderAuthMethod getCardholderAuthMethod() const = 0;

                /// \brief Устанавливает способ авторизации держателя карты
                /// \param[in] cardholderAuthMethod Значение из перечисления CardholderAuthMethod, за исключением NoMethod
                /// \return true, если поле успешно установлено
                virtual bool setCardholderAuthMethod(CardholderAuthMethod cardholderAuthMethod) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardholderAuthMethod
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardholderAuthMethod() = 0;

                /// \brief Возвращает код авторизации на хосте
                /// \return Строка, содержащая код авторизации
                virtual const std::string &getAuthCode() const = 0;

                /// \brief Устанавливает код авторизации на хосте
                /// \param[in] authCode Строка, содержащая код авторизации.
                /// \return true, если поле успешно установлено
                virtual bool setAuthCode(const std::string &authCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля AuthCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAuthCode() = 0;

                /// \brief Возвращает код ответа хоста или финансового ПО LAN-4Tap
                /// \return Строка, содержащая код ответа
                virtual const std::string &getResponseCode() const = 0;

                /// \brief Устанавливает код ответа хоста или финансового ПО LAN-4Tap
                /// \param[in] responseCode Строка, содержащая код ответа
                /// \return true, если поле успешно установлено
                virtual bool setResponseCode(const std::string &responseCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля ResponseCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetResponseCode() = 0;

                /// \brief Возвращает текст ответа от хоста или финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст ответа
                virtual const std::string &getResponseText() const = 0;

                /// \brief Возвращает текст ответа от хоста или финансового ПО LAN-4Tap
                /// \param[in] responseText Строка, содержащая текст ответа
                /// \return true, если поле успешно установлено
                virtual bool setResponseText(const std::string &responseText) = 0;

                /// \brief Устанавливает значение по умолчанию для поля ResponseText
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetResponseText() = 0;

                /// \brief Возвращает идентификатор операции в финансовом ПО LAN-4Tap
                /// \return Строка, содержащая STAN операции
                virtual const std::string &getSTAN() const = 0;

                /// \brief Устанавливает идентификатор операции в финансовом ПО LAN-4Tap
                /// \param[in] stan Строка, содержащая STAN операции
                /// \return true, если поле успешно установлено
                virtual bool setSTAN(const std::string &stan) = 0;

                /// \brief Устанавливает значение по умолчанию для поля STAN
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetSTAN() = 0;

                /// \brief Возвращает ID операции на хосте
                /// \return Строка, содержащая ID операции
                virtual const std::string &getTransactionID() const = 0;

                /// \brief Устанавливает ID операции на хосте
                /// \param[in] transactionId Строка, содержащая ID операции
                /// \return true, если поле успешно установлено
                virtual bool setTransactionID(const std::string &transactionId) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TransactionID
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTransactionID() = 0;

                /// \brief Возвращает ID терминала на хосте
                /// \return Строка, содержащая ID терминала
                virtual const std::string &getTerminalID() const = 0;

                /// \brief Устанавливает ID терминала на хосте
                /// \param[in] terminalId Строка, содержащая ID терминала
                /// \return true, если поле успешно установлено
                virtual bool setTerminalID(const std::string &terminalId) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TerminalID
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTerminalID() = 0;

                /// \brief Возвращает EMV AID карты
                /// \return Строка, содержащая EMV AID
                virtual const std::string &getCardEmvAid() const = 0;

                /// \brief Устанавливает EMV AID карты
                /// \param[in] cardEmvAid Строка, содержащая EMV AID
                /// \return true, если поле успешно установлено
                virtual bool setCardEmvAid(const std::string &cardEmvAid) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardEmvAid
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardEmvAid() = 0;

                /// \brief Возвращает название прилжения карты
                /// \return Строка, содержащая название приложения карты
                virtual const std::string &getCardAppName() const = 0;

                /// \brief Устанавливает название прилжения карты
                /// \param[in] cardAppName Строка, содержащая название приложения карты
                /// \return true, если поле успешно установлено
                virtual bool setCardAppName(const std::string &cardAppName) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardAppName
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardAppName() = 0;

                /// \brief Возвращает способ предоставления карты
                /// \return Значение из перечисления CardInputMethod. Если поле не установлено - NoMethod
                virtual CardInputMethod getCardInputMethod() const = 0;

                /// \brief Устанавливает способ предоставления карты
                /// \param[in] cardInputMethod Значение из перечисления CardInputMethod, за исключением NoMethod
                /// \return true, если поле успешно установлено
                virtual bool setCardInputMethod(CardInputMethod cardInputMethod) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardInputMethod
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardInputMethod() = 0;

                /// \brief Возвращает название эмитента карты
                /// \return Строка, содержащая название эмитента
                virtual const std::string &getIssuerName() const = 0;

                /// \brief Устанавливает название эмитента карты
                /// \param[in] issuerName Строка, содержащая название эмитента
                /// \return true, если поле успешно установлено
                virtual bool setIssuerName(const std::string &issuerName) = 0;

                /// \brief Устанавливает значение по умолчанию для поля IssuerName
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetIssuerName() = 0;

                /// \brief Возвращает дополнительные данные операции
                /// \return Строка, содержащая дополнительные данные операции. Формат зависит от операции
                virtual const std::string &getAdditionalInfo() const = 0;

                /// \brief Устанавливает дополнительные данные операции
                /// \param[in] additionalInfo Строка, содержащая дополнительные данные операции. Формат зависит от операции
                /// \return true, если поле успешно установлено
                virtual bool setAdditionalInfo(const std::string &additionalInfo) = 0;

                /// \brief Устанавливает значение по умолчанию для поля AdditionalInfo
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAdditionalInfo() = 0;

                /// \brief Возвращает открытые данные карты
                /// \return Строка, содержащая открыте данные карты
                /// Строка может начинаться с префикса 0x. После префикса - TLV открытых данных карты в ASCII HEX.
                /// Регистр не важен.
                virtual const std::string &getCardData() const = 0;

                /// \brief Устанавливает открытые данные карты
                /// \param[in] cardData Строка, содержащая открыте данные карты
                /// Строка может начинаться с префикса 0x. После префикса - TLV открытых данных карты в ASCII HEX.
                /// Регистр не важен.
                /// \return true, если поле успешно установлено
                virtual bool setCardData(const std::string &cardData) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardData
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardData() = 0;

                /// \brief Возвращает зашифрованные данные карты
                /// \return Строка, содержащая зашифрованные данные карты
                /// Строка может начинаться с префикса 0x. После префикса - зашифрованные данные карты в ASCII HEX.
                /// После расшифровки - данные карты в формате TLV
                /// Регистр не важен.
                virtual const std::string &getCardDataEnc() const = 0;

                /// \brief Устанавливает зашифрованные данные карты.
                /// Строка может начинаться с префикса 0x. После префикса - зашифрованные данные карты в ASCII HEX.
                /// После расшифровки - данные карты в формате TLV
                /// Регистр не важен.
                /// \param[in] cardDataEnc Строка, содержащая зашифрованные данные карты
                /// \return true, если поле успешно установлено
                virtual bool setCardDataEnc(const std::string &cardDataEnc) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardDataEnc
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardDataEnc() = 0;

                /// \brief Возвращает ID мерчанта на хосте
                /// \return Строка, содержащая ID мерчанта
                virtual const std::string &getMerchantID() const = 0;

                /// \brief Устанавливает ID мерчанта на хосте
                /// \param[in] merchantId Строка, содержащая ID мерчанта на хосте
                /// \return true, если поле успешно установлено
                virtual bool setMerchantID(const std::string &merchantId) = 0;

                /// \brief Устанавливает значение по умолчанию для поля MerchantID
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetMerchantID() = 0;

                /// \brief Дополнительные данные работы с картой
                /// \return Дополнительные данные работы с картой
                virtual const std::string &getTVR() const = 0;

                /// \brief Дополнительные данные работы с картой
                /// \param[in] tvr Дополнительные данные работы с картой
                /// \return true, если поле успешно установлено
                virtual bool setTVR(const std::string &tvr) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TVR
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTVR() = 0;

                /// \brief Дополнительные данные работы с картой
                /// \return Дополнительные данные работы с картой
                virtual const std::string &getTSI() const = 0;

                /// \brief Дополнительные данные работы с картой
                /// \param[in] tsi Дополнительные данные работы с картой
                /// \return true, если поле успешно установлено
                virtual bool setTSI(const std::string &tsi) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TSI
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTSI() = 0;

                /// \brief Дополнительные данные работы с картой
                /// \return Дополнительные данные работы с картой
                virtual const std::string &getTC() const = 0;

                /// \brief Дополнительные данные работы с картой
                /// \param[in] tc Дополнительные данные работы с картой
                /// \return true, если поле успешно установлено
                virtual bool setTC(const std::string &tc) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TC
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTC() = 0;

                /// \brief Дополнительные данные работы с картой
                /// \return Дополнительные данные работы с картой
                virtual const std::string &getCID() const = 0;

                /// \brief Дополнительные данные работы с картой
                /// \param[in] cid Дополнительные данные работы с картой
                /// \return true, если поле успешно установлено
                virtual bool setCID(const std::string &cid) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CID
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCID() = 0;

                /// \brief Дополнительные данные работы с картой
                /// \return Дополнительные данные работы с картой
                virtual const std::string &getKVR() const = 0;

                /// \brief Дополнительные данные работы с картой
                /// \param[in] kvr Дополнительные данные работы с картой
                /// \return true, если поле успешно установлено
                virtual bool setKVR(const std::string &kvr) = 0;

                /// \brief Устанавливает значение по умолчанию для поля KVR
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetKVR() = 0;

                /// \brief Дополнительные данные работы с картой
                /// \return Дополнительные данные работы с картой
                virtual const std::string &getCDAResult() const = 0;

                /// \brief Дополнительные данные работы с картой
                /// \param[in] cdaResult Дополнительные данные работы с картой
                /// \return true, если поле успешно установлено
                virtual bool setCDAResult(const std::string &cdaResult) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CDAResult
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCDAResult() = 0;

                /// \brief Возвращает количество операций продажи, выполненных с последней сверки итогов
                /// \return Количество операций продажи
                virtual int32_t getSalesCount() const = 0;

                /// \brief Устанавливает количество операций продажи, выполненных с последней сверки итогов
                /// \param[in] salesCount количество операций продажи
                /// \return true, если поле успешно установлено
                virtual bool setSalesCount(int32_t salesCount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля SalesCount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetSalesCount() = 0;

                /// \brief Возвращает количество операций отмены, выполненных с последней сверки итогов
                /// \return Количество операций отмены
                virtual int32_t getVoidCount() const = 0;

                /// \brief Устанавливает количество операций отмены, выполненных с последней сверки итогов
                /// \param[in] voidCount количество операций продажи
                /// \return true, если поле успешно установлено
                virtual bool setVoidCount(int32_t voidCount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля VoidCount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetVoidCount() = 0;

                /// \brief Возвращает количество операций возврата, выполненных с последней сверки итогов
                /// \return Количество операций возврата
                virtual int32_t getRefundCount() const = 0;

                /// \brief Устанавливает количество операций возврата, выполненных с последней сверки итогов
                /// \param[in] refundCount количество операций возврата
                /// \return true, если поле успешно установлено
                virtual bool setRefundCount(int32_t refundCount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля RefundCount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetRefundCount() = 0;

                /// \brief Возвращает массив, содержащий краткую информацию по операциям продажи
                /// \return std::vector, содержащий указатели std::shared_ptr на IResponseData
                virtual const std::vector<std::shared_ptr<IResponseData> > &getSaleArray() const = 0;

                /// \brief Устанавливает массив, содержащий краткую информацию по операциям продажи
                /// \param[in] salesArray std::vector, содержащий указатели std::shared_ptr на IResponseData
                /// \return true, если поле успешно установлено
                virtual bool setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray) = 0;

                /// \brief Устанавливает значение по умолчанию для поля SalesArray
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetSalesArray() = 0;

                /// \brief Возвращает массив, содержащий краткую информацию по операциям отмены
                /// \return std::vector, содержащий указатели std::shared_ptr на IResponseData
                virtual const std::vector<std::shared_ptr<IResponseData> > &getVoidArray() const = 0;

                /// \brief Устанавливает массив, содержащий краткую информацию по операциям отмены
                /// \param[in] voidArray std::vector, содержащий указатели std::shared_ptr на IResponseData
                /// \return true, если поле успешно установлено
                virtual bool setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray) = 0;

                /// \brief Устанавливает значение по умолчанию для поля VoidArray
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetVoidArray() = 0;

                /// \brief Возвращает массив, содержащий краткую информацию по операциям возврата
                /// \return std::vector, содержащий указатели std::shared_ptr на IResponseData
                virtual const std::vector<std::shared_ptr<IResponseData> > &getRefundArray() const = 0;

                /// \brief Устанавливает массив, содержащий краткую информацию по операциям возврата
                /// \param[in] refundArray std::vector, содержащий указатели std::shared_ptr на IResponseData
                /// \return true, если поле успешно установлено
                virtual bool setRefundArray(const std::vector<std::shared_ptr<IResponseData> > &refundArray) = 0;

                /// \brief Устанавливает значение по умолчанию для поля RefundArray
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetRefundArray() = 0;
            };//class IResponseData
        }//namespace Response
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_IRESPONSEDATA_H
