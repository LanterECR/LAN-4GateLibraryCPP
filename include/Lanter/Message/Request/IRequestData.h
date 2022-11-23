#ifndef LAN_4GATELIBRARYCPP_IREQUESTDATA_H
#define LAN_4GATELIBRARYCPP_IREQUESTDATA_H

#include <cstdint>
#include <string>
#include <set>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/OperationCode.h"

#include "RequestField.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            ///\brief Базовый класс-контейнер для отправки запросов финансовому ПО LAN-4Tap
            class LANTER_VISIBILITY IRequestData {
            public:
                virtual ~IRequestData() = default;

                /// \brief Возвращает список установленных полей
                /// \return Список установленных полей
                /// \sa RequestField
                virtual const std::set<RequestField> &getFieldsSet() const = 0;

                /// \brief Проверяет было ли установлено поле
                /// \param[in] field Поле, которое необходимо проверить
                /// \return true, если поле было установлено
                virtual bool isFieldSet(RequestField field) const = 0;

                /// \brief Устанавливает значение по умолчанию для поля и удаляет из списка установленных полей
                /// \param[in] field Поле, которое необходимо удалить
                /// \return true, если поле успешно удалено
                virtual bool resetField(RequestField field) = 0;

                /// \brief Возвращает список обязательных полей для выполняемой операции
                /// \return Список обязательных полей
                /// \sa RequestField
                virtual const std::set<RequestField> &getMandatoryFields() const = 0;

                /// \brief Возвращает список опциональных полей для выполняемой операции
                /// \return Список опциональных полей
                /// \sa RequestField
                virtual const std::set<RequestField> &getOptionalFields() const = 0;

                /// \brief Проверяет наличие обязательных полей.
                /// \return true - если все обязательные поля установлены.
                virtual bool validateMandatoryFields() const = 0;

                /// \brief Возвращает логический идентификатор кассового ПО
                /// \return Если поле установлено - логический идентификатор кассового ПО, иначе -1
                virtual int16_t getEcrNumber() const = 0;

                /// \brief Устанавливает логический идентификатор кассового ПО
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

                /// \brief Устанавливает логический идентификатор мерчанта в кассовом ПО
                /// \param[in] ecrMerchantNumber Логический идентификатор мерчанта в кассовом в диапазоне [1, 999]
                /// \return true, если поле успешно установлено
                virtual bool setEcrMerchantNumber(int16_t ecrMerchantNumber) = 0;


                /// \brief Устанавливает значение по умолчанию для поля EcrMerchantNumber
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetEcrMerchantNumber() = 0;

                /// \brief Возвращает код выполняемой операции
                /// \return Если поле установлено, возвращает код операции. Иначе NoOperation
                /// \sa OperationCode
                virtual OperationCode getOperationCode() const = 0;

                /// \brief Устанавливает код выполняемой операции
                /// \param[in] operationCode Значение из перечислений OperationCode, за исключением NoOperation
                /// \return true, если поле успешно установлено
                virtual bool setOperationCode(OperationCode operationCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля OperationCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetOperationCode() = 0;

                /// \brief Возвращает установленную сумму операции в минимальных единицах валюты (копейки для рублей)
                /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getAmount() const = 0;

                /// \brief Устанавливает сумму в минимальных единицах валюты (копейки для рублей)
                /// \param[in] amount Значение суммы в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setAmount(int64_t amount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля Amount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAmount() = 0;

				/// \brief Возвращает установленную сумму по ЭС операции в минимальных единицах валюты (копейки для рублей)
				/// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
				virtual int64_t getECertAmount() const = 0;

				/// \brief Устанавливает сумму по ЭС в минимальных единицах валюты (копейки для рублей)
				/// \param[in] amount Значение суммы в диапазоне [0, 999999999999]
				/// \return true, если поле успешно установлено
				virtual bool setECertAmount(int64_t amount) = 0;

				/// \brief Устанавливает значение по умолчанию для поля ECertAmount
				/// и удаляет из списка установленных полей
				/// \return true, если успешно удалено.
				virtual bool resetECertAmount() = 0;

				/// \brief Возвращает установленную частичную сумму в минимальных единицах валюты (копейки для рублей)
                /// \return Если поле установлено - значение суммы операции в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getPartialAmount() const = 0;

                /// \brief Устанавливает частичную сумму в минимальных единицах валюты (копейки для рублей)
                /// \param[in] partialAmount Значение частичной суммы операции в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setPartialAmount(int64_t partialAmount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля PartialAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetPartialAmount() = 0;

                /// \brief Возвращает установленную сумму чаевых в минимальных единицах валюты (копейки для рублей)
                /// \return Если поле установлено - значение суммы чаевых в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getTipsAmount() const = 0;

                /// \brief Устанавливает сумму чаевых в минимальных единицах валюты (копейки для рублей)
                /// \param[in] tipsAmount Значение суммы чаевых операции в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setTipsAmount(int64_t tipsAmount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TipsAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTipsAmount() = 0;

                /// \brief Возвращает установленную сумму кэшбека в минимальных единицах валюты (копейки для рублей)
                /// \return Если поле установлено - значение суммы чаевых в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getCashbackAmount() const = 0;

                /// \brief Устанавливает сумму кэшбека в минимальных единицах валюты (копейки для рублей)
                /// \param[in] cashbackAmount Значение суммы кэшбека операции в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setCashbackAmount(int64_t cashbackAmount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CashbackAmount
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCashbackAmount() = 0;

                /// \brief Возвращает строку, содержащую установленный код валюты согласно ISO 4217
                /// \return Если код валюты не установлен, возвращаемая строка пуста
                virtual const std::string & getCurrencyCode() const = 0;

                /// \brief Устанавливает код валюты согласно ISO 4217
                /// \param[in] currencyCode Строка, содержащая код валюты в диапазоне [1, 999]
                /// \return true, если поле успешно установлено
                virtual bool setCurrencyCode(const std::string &currencyCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CurrencyCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCurrencyCode() = 0;

                /// \brief Возвращает установленное значение RRN
                /// \return строка, содержащая RRN.
                virtual const std::string &getRRN() const = 0;

                /// \brief Устанавливает RRN, полученный в ответ на одну из предыдущих операций
                /// \param[in] RRN Строка, содержащая RRN.
                /// \return true, если поле успешно установлено
                virtual bool setRRN(const std::string &RRN) = 0;

                /// \brief Устанавливает значение по умолчанию для поля RRN
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetRRN() = 0;

                /// \brief Возвращает установленное значение кода авторизации
                /// \return строка, содержащая код авторизации
                virtual const std::string &getAuthCode() const = 0;

                /// \brief Устанавливает код авторизации, полученный в ответ на одну из предыдущих операций
                /// \param[in] authCode Строка, содержащая код авторизации.
                /// \return true, если поле успешно установлено
                virtual bool setAuthCode(const std::string &authCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля AuthCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAuthCode() = 0;

                /// \brief Возвращает установленное значение номера чека
                /// \return Строка, содержащая номер чека
                virtual const std::string &getReceiptReference() const = 0;

                /// \brief Устанавливает значение номера чека в финансовом ПО LAN-4Tap,
                /// полученное в ответ на одной из предыдущих операций
                /// \param[in] receiptReference Строка, содержащая номер чека в финансовом ПО LAN-4Tap
                /// \return true, если поле успешно установлено
                virtual bool setReceiptReference(const std::string &receiptReference) = 0;


                /// \brief Устанавливает значение по умолчанию для поля ReceiptReference
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetReceiptReference() = 0;

                /// \brief Возвращает установленное значение идентификатора транзакции
                /// \return Строка содержащая значение идентификатора транзакции
                virtual const std::string &getTransactionID() const = 0;

                /// \brief Устанавливает значение идентификатора транзакции, полученное в ответ на одной из предыдущих операций
                /// \param[in] transactionId Строка, содержащая идентификатор транзакции
                /// \return true, если поле успешно установлено
                virtual bool setTransactionID(const std::string &transactionId) = 0;

                /// \brief Устанавливает значение по умолчанию для поля TransactionID
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetTransactionID() = 0;

                /// \brief Возвращает установленное значение, содержащее зашифрованные данные карты
                /// \return Строка, содержащая зашифрованные данные карты
                virtual const std::string &getCardDataEnc() const = 0;

                /// \brief Устанавливает значение зашифрованных данных карты, полученное в ответ на одну из предыдущих операций
                /// \param[in] cardDataEnc Строка, содержащая зашифрованные данные карты
                /// \return true, если поле успешно установлено
                virtual bool setCardDataEnc(const std::string &cardDataEnc) = 0;

                /// \brief Устанавливает значение по умолчанию для поля CardDataEnc
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetCardDataEnc() = 0;

                /// \brief Возвращает установленное значение списка открытых тегов операции FastTrack
                /// \return Строка, содержащая список открытых тегов операции FastTrack
                /// \sa setOpenTags
                virtual const std::string &getOpenTags() const = 0;

                /// \brief Устанавливает список тегов, которые необходимо получить от финансового ПО LAN-4Tap в открытом виде
                /// \param[in] openTags Строка, отформатированная по следующему шаблону:
                /// Каждый тег должен быть закодирован 4 байтами в текстовом шестнадцатеричном представлении.
                /// Например, тег DF82 кодируется, как 0000DF82, а тег 82 - 00000082
                /// Несколько тегов записываются друг за другом, например  0000DF8200000082.
                /// Опционально, строка может начинаться с лидирующей последовательности 0x
                /// Регистр текста не важен
                /// \return true, если поле успешно установлено
                virtual bool setOpenTags(const std::string &openTags) = 0;

                /// \brief Устанавливает значение по умолчанию для поля OpenTags
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetOpenTags() = 0;

                /// \brief Возвращает установленное значение списка шифруемых тегов операции FastTrack
                /// \return Строка, содержащая список шифруемых тегов операции FastTrack
                /// \sa setEncTags
                virtual const std::string &getEncTags() const = 0;

                /// \brief Устанавливает список тегов, которые необходимо получить от финансового ПО LAN-4Tap в зашифрованном виде
                /// \param[in] encTags Строка, отформатированная по следующему шаблону:
                /// Каждый тег должен быть закодирован 4 байтами в текстовом шестнадцатеричном представлении.
                /// Например, тег DF82 кодируется, как 0000DF82, а тег 82 - 00000082
                /// Несколько тегов записываются друг за другом, например  0000DF8200000082.
                /// Опционально, строка может начинаться с лидирующей последовательности 0x
                /// Регистр текста не важен
                /// \return true, если поле успешно установлено
                virtual bool setEncTags(const std::string &encTags) = 0;

                /// \brief Устанавливает значение по умолчанию для поля EncTags
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetEncTags() = 0;

                /// \brief Возвращает установленный код провайдера платежа
                /// \return Строка, содержащая установленный код провайдера платежа
                virtual const std::string &getProviderCode() const = 0;

                /// \brief Устанавливает код провайдера платежа
                /// \param[in] providerCode Строка, содержащая код провайдера платежа
                /// \return true, если поле успешно установлено
                virtual bool setProviderCode(const std::string &providerCode) = 0;

                /// \brief Устанавливает значение по умолчанию для поля ProviderCode
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetProviderCode() = 0;

                /// \brief Возвращает установленное значение дополнительных параметров операции
                /// \return Строка, содержащая дополнительные параметры операции
                virtual const std::string &getAdditionalInfo() const = 0;

                /// \brief Устанавливает дополнительные параметры операции
                /// \param[in] additionalInfo Строка, содержащая дополнительные параметры операции. Формат зависит от операции.
                /// \return true, если поле успешно установлено
                virtual bool setAdditionalInfo(const std::string &additionalInfo) = 0;

                /// \brief Устанавливает значение по умолчанию для поля AdditionalInfo
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAdditionalInfo() = 0;

                /// \brief Возвращает баланс бонусного счета
                /// \return Если поле установлено - баланс бонусного счета в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getBonusBalance() const = 0;

                /// \brief Устанавливает баланс бонусного счета
                /// \param balance Значение в диапазоне [0, 999999999999]
                /// \return true, если поле успешно установлено
                virtual bool setBonusBalance(int64_t balance) = 0;

                /// \brief Устанавливает значение по умолчанию для поля BonusBalance
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetBonusBalance() = 0;

                /// \brief Возвращает сумму бонусов, которые должны быть использованы в операции
                /// \return Если поле установлено - количество бонусов в диапазоне [0, 999999999999]. Иначе -1.
                virtual int64_t getBonusAmount() const = 0;

                /// \brief Устанавливает сумму бонусов, которая должна быть использована в операции
                /// \param amount Количество бонусов в диапазоне [0, 999999999999].
                /// \return true, если поле успешно установлено
                virtual bool setBonusAmount(int64_t amount) = 0;

                /// \brief Устанавливает значение по умолчанию для поля BonusAmount
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetBonusAmount() = 0;

                /// \brief Возвращает кэшированный PAN карты, используемый в операции
                /// \return Строка, содержащая кэшированный PAN карты, использованный в операции
                virtual const std::string & getHashCardTrack2() const = 0;

                /// \brief Устанавливает кэшированный PAN карты, используемый в операции
                /// \param hashTrack2 Строка, содержащая кэшированный PAN карты
                /// \return true, если поле успешно установлено
                virtual bool setHashCardTrack2(const std::string & cardTrack2) = 0;

                /// \brief Устанавливает значение по умолчанию для поля HashCardTrack2
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetHashCardTrack2() = 0;

                /// \brief Возвращает код провайдера оплаты. Например, ID оператора связи
                /// Используется для операции Payment
                /// \return
                virtual const std::string & getPaymentProviderCode() const = 0;

                /// \brief Устанавливает код провайдера оплаты. Например, ID оператора связи
                /// Используется для операции Payment
                /// \param code строка, содержащая код провайдера оплаты
                /// \return true, если поле успешно установлено
                virtual bool setPaymentProviderCode(const std::string & code) = 0;

                /// \brief Устанавливает значение по умолчанию для поля HashCardTrack2
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetPaymentProviderCode() = 0;

                /// \brief Возвращает первый параметр оплаты
                /// \return Строка, содержащая первый параметр оплаты
                virtual const std::string & getPaymentParam1() const = 0;

                /// \brief Устанавливает первый параметр оплаты
                /// \param param Строка, содержащая первый параметр оплаты
                /// \return true, если поле успешно установлено
                virtual bool setPaymentParam1(const std::string & param) = 0;

                /// \brief Устанавливает значение по умолчанию для поля PaymentParam1
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetPaymentParam1() = 0;

                /// \brief Возвращает второй параметр оплаты
                /// \return Строка, содержащая второй параметр оплаты
                virtual const std::string & getPaymentParam2() const = 0;

                /// \brief Устанавливает второй параметр оплаты
                /// \param param Строка, содержащая второй параметр оплаты
                /// \return true, если поле успешно установлено
                virtual bool setPaymentParam2(const std::string & param) = 0;

                /// \brief Устанавливает значение по умолчанию для поля PaymentParam2
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetPaymentParam2() = 0;

                /// \brief Возвращает третий параметр оплаты
                /// \return Строка, содержащая третий параметр оплаты
                virtual const std::string & getPaymentParam3() const = 0;

                /// \brief Устанавливает третий параметр оплаты
                /// \param param Строка, содержащая третий параметр оплаты
                /// \return true, если поле успешно установлено
                virtual bool setPaymentParam3(const std::string & param) = 0;

                /// \brief Устанавливает значение по умолчанию для поля PaymentParam3
                /// и удаляет из списка установленных полей
                /// \return true, если поле успешно удалено
                virtual bool resetPaymentParam3() = 0;


                /// \brief Возвращает установленные параметры операции на экране терминала
                /// \return Строка, содержащая установленные параметры операции на экране терминала
                virtual const std::string &getAdditionalChoice() const = 0;

                /// \brief Устанавливает параметры операции на экране терминала
                /// \param[in] additionalChoice Строка, содержащая установленные параметры операции на экране терминала
                /// \return true, если поле успешно установлено
                virtual bool setAdditionalChoice(const std::string &additionalInfo) = 0;

                /// \brief Устанавливает параметры операции на экране терминала для поля AdditionalChoice
                /// и удаляет из списка установленных полей
                /// \return true, если успешно удалено.
                virtual bool resetAdditionalChoice() = 0;

				/// \brief Возвращает ID корзины
				/// \return Строка, содержащая ID корзины
				virtual const std::string & getBasketID() const = 0;

				/// \brief Устанавливает ID корзины
				/// \param param Строка, содержащая ID корзины
				/// \return true, если поле успешно установлено
				virtual bool setBasketID(const std::string & id) = 0;

				/// \brief Устанавливает значение по умолчанию для поля BasketID
				/// и удаляет из списка установленных полей
				/// \return true, если поле успешно удалено
				virtual bool resetBasketID() = 0;

				/// \brief Возвращает PAN HASH
				/// \return Строка, содержащая HASH PAN
				virtual const std::string & getCardPANHash() const = 0;

				/// \brief Устанавливает PAN HASH
				/// \param param Строка, содержащая HASH PAN
				/// \return true, если поле успешно установлено
				virtual bool setCardPANHash(const std::string & id) = 0;

				/// \brief Устанавливает значение по умолчанию для поля CardPANHash
				/// и удаляет из списка установленных полей
				/// \return true, если поле успешно удалено
				virtual bool resetCardPANHash() = 0;
			};//class IRequestData
        }//namespace Request
    }//namespace Message
}//namespace Lanter

#endif //LAN_4GATELIBRARYCPP_IREQUESTDATA_H
