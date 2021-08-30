#include "Lan4Gate.h"

#include <random>

#include "Lanter/Utils/FieldRangeChecker.h"

#include "Lanter/Message/Request/RequestDataFactory.h"
#include "Lanter/Message/Response/ResponseDataFactory.h"
#include "Lanter/Message/Notification/NotificationDataFactory.h"

#include "Lanter/MessageProcessor/Parser/MessageParserFactory.h"
#include "Lanter/MessageProcessor/Builder/MessageBuilderFactory.h"

namespace Lanter {
    namespace Manager {
        Lan4Gate::Lan4Gate() : m_IsStarted(false) {}

        Lan4Gate::~Lan4Gate() {
            Lan4Gate::stop();
        }

        bool Lan4Gate::setEcrNumber(int16_t ecrNumber) {
            bool result = false;

            if(!m_IsStarted) {
                result = Utils::checkEcrNumberRange(ecrNumber);

                if(result) {
                    m_EcrNumber = ecrNumber;
                }
            }

            return result;
        }

        int16_t Lan4Gate::getEcrNumber() const {
            return m_EcrNumber;
        }

        bool Lan4Gate::start() {
            if(m_Communication != nullptr) {
                m_IsStarted = true;
            }
            return m_IsStarted;
        }

        bool Lan4Gate::stop() {
            m_IsStarted = false;

            return !m_IsStarted;
        }

        bool Lan4Gate::isStarted() const {
            return m_IsStarted;
        }


        void Lan4Gate::doLan4Gate() {
            if(m_IsStarted) {
                if(openConnection()) {

                }
            }
        }

        bool Lan4Gate::runOnThread() {
            return isStarted();
        }

        bool Lan4Gate::setCommunication(std::shared_ptr<Communication::ICommunication> communication) {
            if(resetCommunication()) {
                m_Communication = communication;
            }
            return m_Communication == communication;
        }

        //TODO Оптимизировать
        bool Lan4Gate::resetCommunication() {
            if(m_Communication) {
                if(m_Communication->isOpen()) {
                    if (m_Communication->close()) {
                        m_Communication.reset();
                    }
                } else {
                    m_Communication.reset();
                }
            }
            return m_Communication == nullptr;
        }

        std::shared_ptr<Communication::ICommunication> Lan4Gate::getCommunication() const {
            return m_Communication;
        }

        //TODO попытаться оптимизировать работу с колбеками
        size_t Lan4Gate::addRequestCallback(std::function<void(std::shared_ptr<Message::Request::IRequestData>)> callback) {
            size_t result = 0;
            if(callback) {
                int size = m_RequestCallbacks.size();

                size_t id = generateID();
                while(m_RequestCallbacks.find(id) != m_RequestCallbacks.end()) {
                    id = generateID();
                }

                m_RequestCallbacks[id] = callback;

                if(m_RequestCallbacks.size() - size > 0) {
                    result = id;
                } else {
                    result = 0;
                }
            }
            return result;
        }

        bool Lan4Gate::removeRequestCallback(size_t id) {
            bool result = false;

            auto item = m_RequestCallbacks.find(id);
            if(item != m_RequestCallbacks.end()) {
                size_t size = m_RequestCallbacks.size();

                m_RequestCallbacks.erase(item);

                result = size - m_RequestCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::requestCallbacksCount() const {
            return m_RequestCallbacks.size();
        }

        size_t Lan4Gate::addResponseCallback(std::function<void(std::shared_ptr<Message::Response::IResponseData>)> callback) {
            size_t result = 0;
            if(callback) {
                int size = m_ResponseCallbacks.size();

                size_t id = generateID();
                while(m_ResponseCallbacks.find(id) != m_ResponseCallbacks.end()) {
                    id = generateID();
                }

                m_ResponseCallbacks[id] = callback;

                if(m_ResponseCallbacks.size() - size > 0) {
                    result = id;
                } else {
                    result = 0;
                }
            }
            return result;
        }

        bool Lan4Gate::removeResponseCallback(size_t id) {
            bool result = false;

            auto item = m_ResponseCallbacks.find(id);
            if(item != m_ResponseCallbacks.end()) {
                size_t size = m_ResponseCallbacks.size();

                m_ResponseCallbacks.erase(item);

                result = size - m_ResponseCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::responseCallbacksCount() const {
            return m_ResponseCallbacks.size();
        }

        size_t Lan4Gate::addNotificationCallback(std::function<void(std::shared_ptr<Message::Notification::INotificationData>)> callback) {
            size_t result = 0;
            if(callback) {
                int size = m_NotificationCallbacks.size();

                size_t id = generateID();
                while(m_NotificationCallbacks.find(id) != m_NotificationCallbacks.end()) {
                    id = generateID();
                }

                m_NotificationCallbacks[id] = callback;

                if(m_NotificationCallbacks.size() - size > 0) {
                    result = id;
                } else {
                    result = 0;
                }
            }
            return result;
        }

        bool Lan4Gate::removeNotificationCallback(size_t id) {
            bool result = false;

            auto item = m_NotificationCallbacks.find(id);
            if(item != m_NotificationCallbacks.end()) {
                size_t size = m_NotificationCallbacks.size();

                m_NotificationCallbacks.erase(item);

                result = size - m_NotificationCallbacks.size() > 0;
            }

            return result;
        }

        size_t Lan4Gate::notificationCallbacksCount() const {
            return m_NotificationCallbacks.size();
        }

        size_t Lan4Gate::generateID() {
            size_t min = 1;
            size_t max = SIZE_MAX;

            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<size_t> distrib(min, max);

            return distrib(gen);
        }

        bool Lan4Gate::openConnection() {
            bool result = m_Communication->isOpen();

            if(!result){
                result = m_Communication->open();
            }

            return result;
        }

        std::shared_ptr<Message::Request::IRequestData> Lan4Gate::getPreparedRequest(Message::OperationCode operationCode) {
            return Message::Request::RequestDataFactory::getRequestData(operationCode, m_EcrNumber);
        }

        std::shared_ptr<Message::Response::IResponseData> Lan4Gate::getPreparedResponse(Message::OperationCode operationCode) {
            return Message::Response::ResponseDataFactory::getResponseData(operationCode, m_EcrNumber);
        }

        std::shared_ptr<Message::Notification::INotificationData> Lan4Gate::getPreparedNotification(Message::Notification::NotificationCode notificationCode) {
            return Message::Notification::NotificationDataFactory::getNotificationData(notificationCode);
        }
    }
}