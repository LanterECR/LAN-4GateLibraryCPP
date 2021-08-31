#ifndef LAN_4GATELIB_LAN4GATE_H
#define LAN_4GATELIB_LAN4GATE_H

#include <unordered_map>
#include <queue>
#include <atomic>
#include <thread>
#include <mutex>
#include <future>

#include "Lanter/Manager/ILan4Gate.h"

#include "Lanter/MessageProcessor/Builder/IMessageBuilder.h"
#include "Lanter/MessageProcessor/Parser//IMessageParser.h"

namespace Lanter {
    namespace Manager {
        class Lan4Gate : public ILan4Gate {
        public:
            Lan4Gate();
            ~Lan4Gate() override;

            bool setEcrNumber(int16_t ecrNumber) override;

            int16_t getEcrNumber() const override;

            bool start() override;

            bool stop() override;

            bool isStarted() const override;

            void doLan4Gate() override;

            bool runOnThread() override;


            bool setCommunication(std::shared_ptr<Communication::ICommunication> communication) override;

            bool resetCommunication() override;

            std::shared_ptr<Communication::ICommunication> getCommunication() const override;

            size_t addRequestCallback(std::function<void(std::shared_ptr<Message::Request::IRequestData>)> callback) override;

            bool removeRequestCallback(size_t id) override;

            size_t addResponseCallback(std::function<void(std::shared_ptr<Message::Response::IResponseData>)> callback) override;

            bool removeResponseCallback(size_t id) override;

            size_t addNotificationCallback(std::function<void(std::shared_ptr<Message::Notification::INotificationData>)> callback) override;

            bool removeNotificationCallback(size_t id) override;

            size_t requestCallbacksCount() const override;

            size_t responseCallbacksCount() const override;

            size_t notificationCallbacksCount() const override;

            std::shared_ptr<Message::Request::IRequestData> getPreparedRequest(Message::OperationCode operationCode) override;

            std::shared_ptr<Message::Response::IResponseData> getPreparedResponse(Message::OperationCode operationCode) override;

            std::shared_ptr<Message::Notification::INotificationData> getPreparedNotification(Message::Notification::NotificationCode notificationCode ) override;

            bool sendMessage(std::shared_ptr<Message::Request::IRequestData> request) override;

            bool sendMessage(std::shared_ptr<Message::Response::IResponseData> response) override;

            bool sendMessage(std::shared_ptr<Message::Notification::INotificationData> notification) override;

        private:
            bool createParser();
            bool deleteParser();

            bool createBuilder();
            bool deleteBuilder();
            /// \brief Генерирует ID для колбеков
            /// \return id в диапазоне от 1 до SIZE_MAX
            static size_t generateID();

            bool openConnection();
            bool closeConnection();

            bool pushToQueue(const std::vector<uint8_t> & data);
            void popFromQueue(std::vector<uint8_t> &data);

            void sendData();
            void receiveData();
            void notify();
            void notifyRequest();
            void notifyResponse();
            void notifyNotification();

            int16_t m_EcrNumber = 1;

            std::atomic<bool> m_IsStarted;

            std::shared_ptr<Communication::ICommunication> m_Communication;

            std::queue<std::vector<uint8_t> > m_MessageQueue;
            std::mutex m_QueueMutex;

            std::thread m_MainThread;



            std::shared_ptr<MessageProcessor::Builder::IMessageBuilder> m_MessageBuilder;
            std::shared_ptr<MessageProcessor::Parser::IMessageParser> m_MessageParser;

            std::unordered_map<size_t, std::function<void(std::shared_ptr<Message::Request::IRequestData>)> > m_RequestCallbacks;

            std::unordered_map<size_t, std::function<void(std::shared_ptr<Message::Response::IResponseData>)> > m_ResponseCallbacks;

            std::unordered_map<size_t, std::function<void(std::shared_ptr<Message::Notification::INotificationData>)> > m_NotificationCallbacks;

            std::future<void> m_CallbacksFuture;
        };
    }
}

#endif //LAN_4GATELIB_LAN4GATE_H
