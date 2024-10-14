#include "JSONReceiptParser.h"
#include "Lanter/MessageProcessor/JSONFields/JSONReceiptFields.h"
#include "Lanter/Message/Receipt/ReceiptDataFactory.h"
#include "JSONGetFieldHelper.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Parser
        {
            std::shared_ptr<IReceiptData> JSONReceiptParser::parseData(const Json::Value& object)
            {
                std::shared_ptr<IReceiptData> result = ReceiptDataFactory::getReceiptData();
                if (result)
                {
                    try
                    {
                        if (getCode(object, *result))
                        {
                            getMessage(object, *result);
                        }
                        else
                        {
                            result.reset();
                        }
                    }
                    catch (const std::exception& e)
                    {
                        throw;
                    }
                }
                return result;
            }

            bool JSONReceiptParser::getCode(const Json::Value& object, IReceiptData& data)
            {
                int code;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONReceiptFields::getCode(), code))
                    {
                        return data.setCode(static_cast<ReceiptCode>(code));
                    }
                }
                catch (const std::exception& e)
                {
                    throw;
                }
                return false;
            }

            bool JSONReceiptParser::getMessage(const Json::Value& object, IReceiptData& data)
            {
                Json::Value lines;
                try
                {
                    if (JSONGetFieldHelper::getField(object, JSONReceiptFields::getMessage(), lines))
                    {
                        if (lines.isArray())
                        {
                            std::vector<std::string> result;

                            for (const auto& line : lines)
                            {
                                result.emplace_back(line.asString());
                            }
                            return data.setMessage(result);
                        }
                    }
                }
                catch (const std::exception& e)
                {
                    throw;
                }
                return false;
            }
        }
    }
}