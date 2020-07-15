//
// Created by Владимир Лысенков on 07.07.2020.
//

#include "JSONMessageBuilder.h"

#include "Lanter/MessageProcessor/JSONMessageFields.h"

#include "Lanter/MessageProcessor/JSONFieldExists.h"

#include "JSONRequestBuilder.h"
#include "JSONResponseBuilder.h"
#include "JSONNotificationBuilder.h"

#include "Lanter/Utils/StringTrimmer.h"
#include "Lanter/Utils/StringConverter.h"

namespace Lanter {
    namespace MessageProcessor {

        bool createVector(const Json::Value & root, std::vector<unsigned char> & resultData) {
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
        bool JSONMessageBuilder::createMessage(std::shared_ptr<IRequestData> data, std::vector<unsigned char> &resultData) {
            bool result = false;
            resultData.clear();
            try {
                Json::Value root;
                root[JSONRootFields::getClassField()] = JSONClassFieldValues::getRequestValue();

                Json::Value object;
                JSONRequestBuilder requestBuilder;
                if(requestBuilder.createObject(*data, object)) {
                    root[JSONRootFields::getObjectField()] = object;
                    result = createVector(root, resultData);
                }
            } catch (std::exception &) {
                result = false;
            }

            return result;
        }

        bool JSONMessageBuilder::createMessage(std::shared_ptr<IResponseData> data, std::vector<unsigned char> &resultData) {
            bool result = false;
            resultData.clear();
            try {
                Json::Value root;
                root[JSONRootFields::getClassField()] = JSONClassFieldValues::getResponseValue();

                Json::Value object;
                JSONResponseBuilder requestBuilder;
                if(requestBuilder.createObject(*data, object)) {
                    root[JSONRootFields::getObjectField()] = object;
                    result = createVector(root, resultData);
                }
            } catch (std::exception &) {
                result = false;
            }

            return result;
        }

        bool JSONMessageBuilder::createMessage(std::shared_ptr<INotificationData> data, std::vector<unsigned char> &resultData) {
            bool result = false;
            resultData.clear();
            try {
                Json::Value root;
                root[JSONRootFields::getClassField()] = JSONClassFieldValues::getNotificationValue();

                Json::Value object;
                JSONNotificationBuilder requestBuilder;
                if(requestBuilder.createObject(*data, object)) {
                    root[JSONRootFields::getObjectField()] = object;
                    result = createVector(root, resultData);
                }
            } catch (std::exception &) {
                result = false;
            }

            return result;
        }
    }
}