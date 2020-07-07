//
// Created by Владимир Лысенков on 24.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_IRESPONSEDATA_H
#define LAN_4GATELIBRARYCPP_IRESPONSEDATA_H

#include <cstdint>
#include <string>
#include <set>
#include <vector>
#include <memory>

#include "Lanter/Message/OperationCodes.h"
#include "ResponseFields.h"
#include "CardholderAuthMethod.h"
#include "CardInputMethod.h"
#include "Status.h"

namespace Lanter {
    namespace Message {
        namespace Response {
            class IResponseData {
            public:
                virtual ~IResponseData() = default;

                /// \brief Возвращает список установленных полей
                /// \return Список установленных полей
                /// \sa ResponseFields
                virtual const std::set<ResponseFields> &getFieldsSet() const = 0;

                /// \brief Возвращает список обязательных полей для выполненной операции
                /// \return Список обязательных полей
                /// \sa ResponseFields
                virtual const std::set<ResponseFields> &getMandatoryFields() const = 0;

                /// \brief Возвращает список опциональных полей для выполненной операции
                /// \return Список опциональных полей
                /// \sa ResponseFields
                virtual const std::set<ResponseFields> &getOptionalFields() const = 0;

                /// \brief Проверяет наличие обязательных полей.
                /// \return true - если все обязательные поля установлены.
                virtual bool validateMandatoryFields() = 0;

                /// \brief Возвращает логический идентификатор кассового ПО
                /// \return Если поле установлено - логический идентификатор кассового ПО, иначе -1
                virtual int16_t getEcrNumber() const = 0;

                /// \brief Устанавливает лоический иденитфикатор кассового ПО
                /// \param ecrNumber Логический идентификатор кассового ПО в диапазоне [1, 999]
                /// \throws invalid_argument, если значение вне разрешенного диапазона
                virtual void setEcrNumber(int16_t ecrNumber) = 0;

                /// \brief Возвращает логический идентификатор мерчанта в кассовом ПО
                /// \return Если поле установлено - логический идентификатор мерчанта в кассовом ПО, иначе -1
                virtual int16_t getEcrMerchantNumber() const = 0;

                /// \brief Устанавливает лоический иденитфикатор мерчанта в кассовом ПО
                /// \param ecrNumber Логический идентификатор мерчанта в кассовом в диапазоне [1, 999]
                /// \throws invalid_argument, если значение вне разрешенного диапазона
                virtual void setEcrMerchantNumber(int16_t ecrMerchantNumber) = 0;

                /// \brief Возвращает код выполненной операции
                /// \return Если поле установлено, возвращает код операции. Иначе NoOperation
                /// \sa OperationCodes
                virtual OperationCodes getOperationCode() const = 0;

                /// \brief Устанавливает код выполнямой операции
                /// \param operationCode Значение из перечислений OperationCodes, за исключением NoOperation
                /// \sa OperationCodes
                /// \throws invalid_argument, если передается недопустимый код операции
                virtual void setOperationCode(OperationCodes operationCode) = 0;

                /// \brief Возвращает код оригинальной операции
                /// \return Если поле установлено, возвращает код оригинальной операции. Иначе NoOperation
                /// \sa OperationCodes
                virtual OperationCodes getOriginalOperationCode() const = 0;

                /// \brief Устанавливает код оригинальной операции
                /// \param operationCode Значение из перечислений OperationCodes, за исключением NoOperation
                /// \sa OperationCodes
                /// \throws invalid_argument, если передается недопустимый код операции
                virtual void setOriginalOperationCode(OperationCodes originalOperationCode) = 0;

                /// \brief Возвращает общую суммы выполненной.
                /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getTotalAmount() const = 0;

                /// \brief Устанавливает сумму в минимальных единицах валюты (копейки для рублей)
                /// \param totalAmount Значение суммы в диапазоне [0, 999999999999]
                virtual void setTotalAmount(int64_t totalAmount) = 0;

                /// \brief Возвращает частичную сумму операции в минимальных единицах валюты (копейки для рублей)
                /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getPartialAmount() const = 0;

                /// \brief Устанавливает частичную сумму в минимальных единицах валюты (копейки для рублей)
                /// \param partialAmount Значение суммы в диапазоне [0, 999999999999]
                virtual void setPartialAmount(int64_t partialAmount) = 0;

                /// \brief
                /// \return
                virtual int64_t getAcquirerFeeAmount() const = 0;

                /// \brief
                /// \param amountAcquirerFee
                virtual void setAcquirerFeeAmount(int64_t amountAcquirerFee) = 0;

                /// \brief
                /// \return
                virtual int64_t getTerminalFeeAmount() const = 0;

                /// \brief
                /// \param amountTerminalFee
                virtual void setTerminalFeeAmount(int64_t amountTerminalFee) = 0;

                /// \brief
                /// \return
                virtual int64_t getTipsAmount() const = 0;

                /// \brief
                /// \param tipsAmount
                virtual void setTipsAmount(int64_t tipsAmount) = 0;

                /// \brief
                /// \return
                virtual int16_t getCurrencyCode() const = 0;

                /// \brief
                /// \param currencyCode
                virtual void setCurrencyCode(int16_t currencyCode) = 0;

                /// \brief
                /// \return
                virtual const std::string &getReceiptReference() const = 0;

                /// \brief
                /// \param receiptReference
                virtual void setReceiptReference(const std::string &receiptReference) = 0;

                /// \brief
                /// \return
                virtual const std::string &getRRN() const = 0;

                /// \brief
                /// \param rrn
                virtual void setRRN(const std::string &rrn) = 0;

                /// \brief
                /// \return
                virtual Status getStatus() const = 0;

                /// \brief
                /// \param status
                virtual void setStatus(Status status) = 0;

                /// \brief
                /// \return
                virtual Status getOriginalOperationStatus() const = 0;

                /// \brief
                /// \param originalOperationStatus
                virtual void setOriginalOperationStatus(Status originalOperationStatus) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTransDateTime() const = 0;

                /// \brief
                /// \param transDateTime
                virtual void setTransDateTime(const std::string &transDateTime) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTerminalDateTime() const = 0;

                /// \brief
                /// \param terminalDateTime
                virtual void setTerminalDateTime(const std::string &terminalDateTime) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCardPan() const = 0;

                /// \brief
                /// \param cardPan
                virtual void setCardPan(const std::string &cardPan) = 0;

                /// \brief
                /// \return
                virtual const std::string &getExpireDate() const = 0;

                /// \brief
                /// \param expireDate
                virtual void setExpireDate(const std::string &expireDate) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCardholderName() const = 0;

                /// \brief
                /// \param cardholderName
                virtual void setCardholderName(const std::string &cardholderName) = 0;

                /// \brief
                /// \return
                virtual CardholderAuthMethod getCardholderAuthMethod() const = 0;

                /// \brief
                /// \param cardholderAuthMethod
                virtual void setCardholderAuthMethod(CardholderAuthMethod cardholderAuthMethod) = 0;

                /// \brief
                /// \return
                virtual const std::string &getAuthCode() const = 0;

                /// \brief
                /// \param authCode
                virtual void setAuthCode(const std::string &authCode) = 0;

                /// \brief
                /// \return
                virtual const std::string &getResponseCode() const = 0;

                /// \brief
                /// \param responseCode
                virtual void setResponseCode(const std::string &responseCode) = 0;

                /// \brief
                /// \return
                virtual const std::string &getResponseText() const = 0;

                /// \brief
                /// \param responseText
                virtual void setResponseText(const std::string &responseText) = 0;

                /// \brief
                /// \return
                virtual const std::string &getSTAN() const = 0;

                /// \brief
                /// \param stan
                virtual void setSTAN(const std::string &stan) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTransactionID() const = 0;

                /// \brief
                /// \param transactionId
                virtual void setTransactionID(const std::string &transactionId) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTerminalID() const = 0;

                /// \brief
                /// \param terminalId
                virtual void setTerminalID(const std::string &terminalId) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCardEmvAid() const = 0;

                /// \brief
                /// \param cardEmvAid
                virtual void setCardEmvAid(const std::string &cardEmvAid) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCardAppName() const = 0;

                /// \brief
                /// \param cardAppName
                virtual void setCardAppName(const std::string &cardAppName) = 0;

                /// \brief
                /// \return
                virtual Response::CardInputMethod getCardInputMethod() const = 0;

                /// \brief
                /// \param cardInputMethod
                virtual void setCardInputMethod(Response::CardInputMethod cardInputMethod) = 0;

                /// \brief
                /// \return
                virtual const std::string &getIssuerName() const = 0;

                /// \brief
                /// \param issuerName
                virtual void setIssuerName(const std::string &issuerName) = 0;

                /// \brief
                /// \return
                virtual const std::string &getAdditionalInfo() const = 0;

                /// \brief
                /// \param additionalInfo
                virtual void setAdditionalInfo(const std::string &additionalInfo) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCardData() const = 0;

                /// \brief
                /// \param cardData
                virtual void setCardData(const std::string &cardData) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCardDataEnc() const = 0;

                /// \brief
                /// \param cardDataEnc
                virtual void setCardDataEnc(const std::string &cardDataEnc) = 0;

                /// \brief
                /// \return
                virtual const std::string &getMerchantID() const = 0;

                /// \brief
                /// \param merchantId
                virtual void setMerchantID(const std::string &merchantId) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTVR() const = 0;

                /// \brief
                /// \param tvr
                virtual void setTVR(const std::string &tvr) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTSI() const = 0;

                /// \brief
                /// \param tsi
                virtual void setTSI(const std::string &tsi) = 0;

                /// \brief
                /// \return
                virtual const std::string &getTC() const = 0;

                /// \brief
                /// \param tc
                virtual void setTC(const std::string &tc) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCID() const = 0;

                /// \brief
                /// \param cid
                virtual void setCID(const std::string &cid) = 0;

                /// \brief
                /// \return
                virtual const std::string &getKVR() const = 0;

                /// \brief
                /// \param kvr
                virtual void setKVR(const std::string &kvr) = 0;

                /// \brief
                /// \return
                virtual const std::string &getCDAResult() const = 0;

                /// \brief
                /// \param cdaResult
                virtual void setCDAResult(const std::string &cdaResult) = 0;

                /// \brief
                /// \return
                virtual int32_t getSalesCount() const = 0;

                /// \brief
                /// \param salesCount
                virtual void setSalesCount(int32_t salesCount) = 0;

                /// \brief
                /// \return
                virtual int32_t getVoidCount() const = 0;

                /// \brief
                /// \param voidCount
                virtual void setVoidCount(int32_t voidCount) = 0;

                /// \brief
                /// \return
                virtual int32_t getRefundCount() const = 0;

                /// \brief
                /// \param refundCount
                virtual void setRefundCount(int32_t refundCount) = 0;

                /// \brief
                /// \return
                virtual const std::vector<std::shared_ptr<IResponseData> > &getSalesArray() const = 0;

                /// \brief
                /// \param salesArray
                virtual void setSalesArray(const std::vector<std::shared_ptr<IResponseData> > &salesArray) = 0;

                /// \brief
                /// \return
                virtual const std::vector<std::shared_ptr<IResponseData> > &getVoidArray() const = 0;

                /// \brief
                /// \param voidArray
                virtual void setVoidArray(const std::vector<std::shared_ptr<IResponseData> > &voidArray) = 0;

                /// \brief
                /// \return
                virtual const std::vector<std::shared_ptr<IResponseData> > &getRefundArray() const = 0;

                /// \brief
                /// \param refundArray
                virtual void setRefundArray(const std::vector<std::shared_ptr<IResponseData> > &refundArray) = 0;
            };
        }//Response
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_IRESPONSEDATA_H
