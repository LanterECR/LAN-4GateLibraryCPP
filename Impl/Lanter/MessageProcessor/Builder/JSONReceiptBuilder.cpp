#include "JSONReceiptBuilder.h"
#include "JSONAddFieldHelper.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "Lanter/MessageProcessor/JSONFields/JSONReceiptFields.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            bool JSONReceiptBuilder::createObject(const IReceiptData& receiptData, Json::Value& object)
            {
                try
                {
                    if (!addCode(receiptData, object))
                    {
                        return false;
                    }

                    addMessage(receiptData, object);

                    return true;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }

            bool JSONReceiptBuilder::addCode(const IReceiptData& receiptData, Json::Value& object)
            {
                if (receiptData.getCode() != ReceiptCode::NoReceipt)
                {
                    if (!AddFieldsHelper::addField(object, JSONReceiptFields::getCode(), static_cast<int>(receiptData.getCode())))
                    {
                        return false;
                    }
                }
                return fieldExists(object, JSONReceiptFields::getCode());
            }

            bool JSONReceiptBuilder::addMessage(const IReceiptData& receiptData, Json::Value& object)
            {
                try
                {
                    if (!receiptData.getMessage().empty())
                    {
                        Json::Value lines;
                        for (const auto& arrayReceiptData : receiptData.getMessage())
                        {
                            lines.append(arrayReceiptData);
                        }

                        if(AddFieldsHelper::addField(object, JSONReceiptFields::getMessage(), lines))
                        {
                            return true;
                        }
                    }

                    return false;
                }
                catch (const std::exception&)
                {
                    throw;
                }
            }// bool JSONReceiptBuilder::addMessage
        }
    }
}