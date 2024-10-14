#ifndef LAN_4GATELIB_RECEIPTDATA_H
#define LAN_4GATELIB_RECEIPTDATA_H

#include "Lanter/Message/Receipt/IReceiptData.h"

namespace Lanter
{
    namespace Message
    {
        namespace Receipt
        {
            class ReceiptData : public IReceiptData
            {
            public:
                ReceiptCode getCode() const override;
                bool setCode(const ReceiptCode& code) override;
                bool resetCode() override;
                const std::vector<std::string>& getMessage() const;
                bool setMessage(const std::vector<std::string>& receiptMessage);
                bool resetMessage();

            private:
                ReceiptCode m_Code = ReceiptCode::NoReceipt;
                std::vector<std::string> m_Lines;
            };
        }
    }
}
#endif //LAN_4GATELIB_RECEIPTDATA_H