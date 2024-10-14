#ifndef LAN_4GATELIB_RECEIPTFACTORY_H
#define LAN_4GATELIB_RECEIPTFACTORY_H

#include "IReceiptData.h"
#include "Lanter/Utils/VisibilityMacroses.h"
#include <memory>

namespace Lanter
{
    namespace Message
    {
        namespace Receipt
        {
            /// \brief Фабричный класс, возвращающий объект взаимодействия
            class LANTER_VISIBILITY ReceiptDataFactory
            {
            public:
                /// \brief Возвращает указатель на объект интерфейс IReceiptData и заполняет поле Code
                /// \param code Код взаимодействия
                /// \sa ReceiptCode
                /// \return Указатель на объект IReceiptData
                static std::shared_ptr<IReceiptData> getReceiptData(ReceiptCode code);

                /// \brief Возвращает указатель на объект интерфейс IReceiptData
                /// \return Указатель на объект IReceiptData
                static std::shared_ptr<IReceiptData> getReceiptData();
            }; //class ReceiptDataFactory
        }
    }
}
#endif //LAN_4GATELIB_RECEIPTFACTORY_H