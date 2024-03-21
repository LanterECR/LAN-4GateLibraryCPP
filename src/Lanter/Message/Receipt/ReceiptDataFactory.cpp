#include "Lanter/Message/Receipt/ReceiptDataFactory.h"
#include "Lanter/Message/Receipt/ReceiptData.h"

namespace Lanter
{
    namespace Message
    {
        namespace Receipt
        {
            std::shared_ptr<IReceiptData> ReceiptDataFactory::getReceiptData(ReceiptCode code)
            {
                auto receipt = std::make_shared<ReceiptData>();
                if(receipt != nullptr)
                {
                    receipt->setCode(code);
                }

                return receipt;
            }

            std::shared_ptr<IReceiptData> ReceiptDataFactory::getReceiptData()
            {
                return getReceiptData(ReceiptCode::NoReceipt);
            }//std::shared_ptr<IReceiptData> ReceiptDataFactory::getReceiptData()
        }//namespace Receipt
    }
}