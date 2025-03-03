#ifndef LAN_4GATELIBRARYCPP_IInterfaceDATA_H
#define LAN_4GATELIBRARYCPP_IInterfaceDATA_H

#include "Lanter/Utils/VisibilityMacroses.h"
#include "InterfaceType.h"
#include <string>

namespace Lanter
{
    namespace Message
    {
        namespace Interface
        {
            /// \brief Базовый класс-контейнер для получения уведомлений от финансового ПО LAN-4Tap
            class LANTER_VISIBILITY IInterfaceData
            {
            public:
                virtual ~IInterfaceData() = default;

                /// \brief Возвращает код полученного экрана
                /// \return Если поле не установлено - Unknown
                /// \sa Interfaces
                virtual InterfaceType getType() const = 0;

                /// \brief Устанавливает код экрана
                /// \param[in] uiType Код экрана
                /// \return true, если поле успешно установлено
                virtual bool setType(InterfaceType uiType) = 0;

                /// \brief Устанавливает код экрана на значение по умолчанию
                /// \return true, если код успешно убран
                virtual bool resetType() = 0;

                /// \brief Возвращает текст Title экрана, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст Title экрана, если он был передан
                virtual const std::string& getTitle() const = 0;

                /// \brief Устанавливает текст Title экрана
                /// \param[in] текст Title экрана
                /// \return true, если поле успешно установлено
                virtual bool setTitle(const std::string& title) = 0;

                /// \brief Очищает сообщение текста Title экрана
                /// \return true, если сообщение успешно очищено
                virtual bool resetTitle() = 0;

                /// \brief Возвращает текст Value для экрана, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст Value для экрана, если он был передан
                virtual const std::string& getValue() const = 0;

                /// \brief Устанавливает текст Value для экрана
                /// \param[in] текст Value для экрана
                /// \return true, если поле успешно установлено
                virtual bool setValue(const std::string& value) = 0;

                /// \brief Очищает сообщение текста Value для экрана
                /// \return true, если сообщение успешно очищено
                virtual bool resetValue() = 0;

                /// \brief Возвращает текст сообщения на экране, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая текст сообщения на экране, если он был передан
                virtual const std::string& getInfoText() const = 0;

                /// \brief Устанавливает текст сообщения на экране
                /// \param[in] текст сообщения на экране
                /// \return true, если поле успешно установлено
                virtual bool setInfoText(const std::string& infoText) = 0;

                /// \brief Очищает сообщение текста
                /// \return true, если сообщение успешно очищено
                virtual bool resetInfoText() = 0;

                /// \brief Возвращает минимальную длину, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая минимальную длину, если он был передан
                virtual const std::string& getMinLen() const = 0;

                /// \brief Устанавливает минимальную длину
                /// \param[in] минимальную длину
                /// \return true, если поле успешно установлено
                virtual bool setMinLen(const std::string& minLen) = 0;

                /// \brief Очищает минимальную длину
                /// \return true, если сообщение успешно очищено
                virtual bool resetMinLen() = 0;

                /// \brief Возвращает максимальную длину, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая максимальную длину, если он был передан
                virtual const std::string& getMaxLen() const = 0;

                /// \brief Устанавливает максимальную длину
                /// \param[in] максимальную длину
                /// \return true, если поле успешно установлено
                virtual bool setMaxLen(const std::string& maxLen) = 0;

                /// \brief Очищает максимальную длину
                /// \return true, если сообщение успешно очищено
                virtual bool resetMaxLen() = 0;

                /// \brief Возвращает результат, полученный от финансового ПО LAN-4Tap
                /// \return Строка, содержащая результат, если он был передан
                virtual const std::string& getResult() const = 0;

                /// \brief Устанавливает результат
                /// \param[in] результат
                /// \return true, если поле успешно установлено
                virtual bool setResult(const std::string& result) = 0;

                /// \brief Очищает результат
                /// \return true, если сообщение успешно очищено
                virtual bool resetResult() = 0;
            };//class IInterfaceData
        }//namespace Interface
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_IInterfaceDATA_H