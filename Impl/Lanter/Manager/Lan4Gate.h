#ifndef LAN_4GATELIB_LAN4GATE_H
#define LAN_4GATELIB_LAN4GATE_H

#include <unordered_map>
#include <atomic>

#include "Lanter/Manager/ILan4Gate.h"

namespace Lanter {
    namespace Manager {
        class Lan4Gate : public ILan4Gate {
        public:
            ~Lan4Gate() override;

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

        private:
            /// \brief Генерирует ID для колбеков
            /// \return id в диапазоне от 1 до SIZE_MAX
            static size_t generateID();

            std::atomic<bool> m_IsStarted;
            std::shared_ptr<Communication::ICommunication> m_Communication;

            std::unordered_map<size_t, std::function<void(std::shared_ptr<Message::Request::IRequestData>)> > m_RequestCallbacks;

            std::unordered_map<size_t, std::function<void(std::shared_ptr<Message::Response::IResponseData>)> > m_ResponseCallbacks;

            std::unordered_map<size_t, std::function<void(std::shared_ptr<Message::Notification::INotificationData>)> > m_NotificationCallbacks;
        };
    }
}

#endif //LAN_4GATELIB_LAN4GATE_H
