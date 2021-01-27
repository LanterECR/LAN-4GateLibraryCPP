#ifndef LAN_4GATELIBRARYCPP_REQUESTDATA_H
#define LAN_4GATELIBRARYCPP_REQUESTDATA_H

#include "Lanter/Message/Request/IRequestData.h"

#include <memory>
#include <set>

#include "Validators/IValidator.h"

namespace Lanter {
    namespace Message {
        namespace Request {

            class RequestData : public IRequestData {
            public:
                RequestData();

                ~RequestData() override = default;

                const std::set<RequestField> &getMandatoryFields() const override;

                const std::set<RequestField> &getOptionalFields() const override;

                bool validateMandatoryFields() const override;

                const std::set<RequestField> &getFieldsSet() const override;

                bool isFieldSet(RequestField field) const override;

                bool resetField(RequestField field) override;

                int16_t getEcrNumber() const override;

                bool setEcrNumber(int16_t ecrNumber) override;

                bool resetEcrNumber() override;

                int16_t getEcrMerchantNumber() const override;

                bool setEcrMerchantNumber(int16_t ecrMerchantNumber) override;

                bool resetEcrMerchantNumber() override;

                OperationCode getOperationCode() const override;

                bool setOperationCode(OperationCode operationCode) override;

                bool resetOperationCode() override;

                int64_t getAmount() const override;

                bool setAmount(int64_t amount) override;

                bool resetAmount() override;

                int64_t getPartialAmount() const override;

                bool setPartialAmount(int64_t partialAmount) override;

                bool resetPartialAmount() override;

                int64_t getTipsAmount() const override;

                bool setTipsAmount(int64_t tipsAmount) override;

                bool resetTipsAmount() override;

                int64_t getCashbackAmount() const override;

                bool setCashbackAmount(int64_t cashbackAmount) override;

                bool resetCashbackAmount() override;

                int16_t getCurrencyCode() const override;

                bool setCurrencyCode(int16_t currencyCode) override;

                bool resetCurrencyCode() override;

                const std::string &getRRN() const override;

                bool setRRN(const std::string &RRN) override;

                bool resetRRN() override;

                const std::string &getAuthCode() const override;

                bool setAuthCode(const std::string &authCode) override;

                bool resetAuthCode() override;

                const std::string &getReceiptReference() const override;

                bool setReceiptReference(const std::string &receiptReference) override;

                bool resetReceiptReference() override;

                const std::string &getTransactionID() const override;

                bool setTransactionID(const std::string &transactionId) override;

                bool resetTransactionID() override;

                const std::string &getCardDataEnc() const override;

                bool setCardDataEnc(const std::string &cardDataEnc) override;

                bool resetCardDataEnc() override;

                const std::string &getOpenTags() const override;

                bool setOpenTags(const std::string &openTags) override;

                bool resetOpenTags() override;

                const std::string &getEncTags() const override;

                bool setEncTags(const std::string &encTags) override;

                bool resetEncTags() override;

                const std::string &getProviderCode() const override;

                bool setProviderCode(const std::string &providerCode) override;

                bool resetProviderCode() override;

                const std::string &getAdditionalInfo() const override;

                bool resetAdditionalInfo() override;

                bool setAdditionalInfo(const std::string &additionalInfo) override;

            private:
                void initValidator();
                void deinitValidator();

                std::set<RequestField> m_FieldsSet; ///< Список установленных полей

                std::shared_ptr<IValidator> m_Validator; ///< Валидатор полей операции

                int16_t m_EcrNumber = -1; ///< Логический номер кассы, используемый для взаимодействия с LAN-4Tap
                int16_t m_EcrMerchantNumber = -1; ///< Логический номер мерчанта в кассовом ПО
                OperationCode m_OperationCode = OperationCode::NoOperation; ///< Код запрашиваемой операции
                int64_t m_Amount = -1; ///< Сумма операции
                int64_t m_PartialAmount = -1; ///< Часть оригинальной суммы. Используется в операциях отмены и возврата
                int64_t m_TipsAmount = -1; ///< Сумма чаевых
                int64_t m_CashbackAmount = -1; ///< Сумма кэшбека
                int16_t m_CurrencyCode = -1; ///< Код валюты согласно ISO 4217
                std::string m_RRN; ///< Retrieval Reference Number, полученный в ответ на предыдущую операцию
                std::string m_AuthCode; ///< Код авторизации на хосте, полученный в ответ на предыдущю операцию
                std::string m_ReceiptReference; ///< Номер чека в финансовом ПО LAN-4Tap. Может отличаться от номера чека в кассовом ПО
                std::string m_TransactionID; ///< Идентификатор транзакции на хосте, полученный в ответ на предыдущую операцию
                std::string m_CardDataEnc; ///< Зашированные данные карты
                std::string m_OpenTags; ///< Теги, которые необходимо получить в открытом виде (формат TLV) в операции FastTrack
                std::string m_EncTags; ///< Теги, которые необходимо получить в зашифрованном виде в операции FastTrack
                std::string m_ProviderCode; ///< Код вендора платежа
                std::string m_AdditionalInfo; ///< Дополнительные данные операции

                std::set<RequestField> m_EmptyFieldsPlaceholder; ///< Пустая коллекция для полей при отсутствии валидатора

            };//class RequestData
        }//namespace Request
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_REQUESTDATA_H
