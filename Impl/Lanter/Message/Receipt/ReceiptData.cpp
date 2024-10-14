#include "ReceiptData.h"
#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter
{
    namespace Message
    {
        namespace Receipt
        {
            ReceiptCode ReceiptData::getCode() const
            {
                return m_Code;
            }

            bool ReceiptData::setCode(const ReceiptCode& code)
            {
                if (Utils::checkReceiptRange(static_cast<int64_t>(code)))
                {
                    m_Code = code;
                    return true;
                }//if check

                return false;
            }

            bool ReceiptData::resetCode()
            {
                m_Code = ReceiptCode::NoReceipt;
                return true;
            }

            const std::vector<std::string>& ReceiptData::getMessage() const
            {
                return m_Lines;
            }//getMessage()

            bool ReceiptData::setMessage(const std::vector<std::string>& receiptMessage)
            {
                if (!receiptMessage.empty())
                {
                    m_Lines = receiptMessage;
                    return true;
                }//receiptMessage not empty

                return false;
            }//setMessage()

            bool ReceiptData::resetMessage()
            {
                m_Lines.clear();
                return m_Lines.empty();
            }//resetMessage()
        }
    }
}