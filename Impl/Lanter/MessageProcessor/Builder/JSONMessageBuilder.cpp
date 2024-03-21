#include "JSONMessageBuilder.h"
#include "Lanter/MessageProcessor/JSONFields/JSONRootFields.h"
#include "Lanter/MessageProcessor/JSONFields/JSONClassFieldsValues.h"
#include "Lanter/MessageProcessor/JSONFields/JSONFieldExists.h"
#include "JSONRequestBuilder.h"
#include "JSONResponseBuilder.h"
#include "JSONNotificationBuilder.h"
#include "JSONInteractionBuilder.h"
#include "JSONReceiptBuilder.h"
#include "Lanter/Utils/StringTrimmer.h"
#include "Lanter/Utils/StringConverter.h"

namespace Lanter
{
    namespace MessageProcessor
    {
        namespace Builder
        {
            bool createVector(const Json::Value &root, std::vector<uint8_t> &resultData)
            {
                //TODO переделать на современный writer
                //Не могу разобраться с настройками StreamWriter
                Json::FastWriter writer;
                std::string document = writer.write(root);
                Utils::trim(document);
                resultData.clear();
                //Перемещение строки в вектор. После данной строки document может быть невалидна.
                Utils::StringConverter::convertToVector(document, resultData);
                return !resultData.empty();
            }

            bool JSONMessageBuilder::createMessage(std::shared_ptr<IRequestData> data, std::vector<uint8_t> &resultData)
            {
                if(data != nullptr)
                {
                    resultData.clear();
                    try
                    {
                        Json::Value root;
                        root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();

                        Json::Value object;
                        JSONRequestBuilder requestBuilder;
                        if (requestBuilder.createObject(*data, object))
                        {
                            root[JSONRootFields::getObjectField()] = object;
                            return createVector(root, resultData);
                        }
                    }
                    catch (const std::exception &)
                    {
                        throw;
                        ///result = false;
                    }
                }
                return false;
            }

            bool JSONMessageBuilder::createMessage(std::shared_ptr<IResponseData> data, std::vector<uint8_t> &resultData)
            {
                if(data != nullptr)
                {
                    resultData.clear();
                    try
                    {
                        Json::Value root;
                        root[JSONRootFields::getClassField()] = JSONClassFieldValues::getResponseValue();

                        Json::Value object;
                        JSONResponseBuilder responseBuilder;
                        if (responseBuilder.createObject(*data, object))
                        {
                            root[JSONRootFields::getObjectField()] = object;
                            return createVector(root, resultData);
                        }
                    }
                    catch (const std::exception &)
                    {
                        throw;
                        ///result = false;
                    }
                }
                return false;
            }

            bool JSONMessageBuilder::createMessage(std::shared_ptr<INotificationData> data, std::vector<uint8_t> &resultData)
            {
                if(data != nullptr)
                {
                    resultData.clear();
                    try
                    {
                        Json::Value root;
                        root[JSONRootFields::getClassField()] = JSONClassFieldValues::getNotificationValue();

                        Json::Value object;
                        JSONNotificationBuilder notificationBuilder;
                        if (notificationBuilder.createObject(*data, object))
                        {
                            root[JSONRootFields::getObjectField()] = object;
                            return createVector(root, resultData);
                        }
                    }
                    catch (const std::exception &)
                    {
                        throw;
                        ///result = false;
                    }
                }
                return false;
            }

            bool JSONMessageBuilder::createMessage(std::shared_ptr<IInteractionData> data, std::vector<uint8_t> &resultData)
            {
                if(data != nullptr)
                {
                    resultData.clear();
                    try
                    {
                        Json::Value root;
                        root[JSONRootFields::getClassField()] = JSONClassFieldValues::getInteractionValue();

                        Json::Value object;
                        JSONInteractionBuilder interactionBuilder;
                        if (interactionBuilder.createObject(*data, object))
                        {
                            root[JSONRootFields::getObjectField()] = object;
                            return createVector(root, resultData);
                        }
                    }
                    catch (std::exception &)
                    {
                        throw;
                        ///result = false;
                    }
                }
                return false;
            }

            bool JSONMessageBuilder::createMessage(std::shared_ptr<IReceiptData> data, std::vector<uint8_t>& resultData)
            {
                if (data != nullptr)
                {
                    resultData.clear();
                    try
                    {
                        Json::Value root;
                        root[JSONRootFields::getClassField()] = JSONClassFieldValues::getReceiptValue();

                        Json::Value object;
                        JSONReceiptBuilder receiptBuilder;
                        if (receiptBuilder.createObject(*data, object))
                        {
                            root[JSONRootFields::getObjectField()] = object;
                            return createVector(root, resultData);
                        }
                    }
                    catch (std::exception&)
                    {
                        throw;
                        ///result = false;
                    }
                }
                return false;
            }// bool JSONMessageBuilder::createMessage
        }
    }
}