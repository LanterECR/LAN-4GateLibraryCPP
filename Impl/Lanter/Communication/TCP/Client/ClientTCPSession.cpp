#include "ClientTCPSession.h"


namespace Lanter {
    namespace Communication {

        ClientTCPSession::ClientTCPSession(tcp::socket socket, std::function<void()> closeConnectionCallback):
            m_Socket (std::move(socket)),
            m_CloseConnectionCallback(std::move(closeConnectionCallback)) {}

        void ClientTCPSession::start() {
            receive();
        }

        void ClientTCPSession::stop() {
            clearQueue();
            m_Socket.close();
        }

        size_t ClientTCPSession::send(const std::vector<uint8_t> &data) {
            std::error_code ec;
            auto result = asio::write(m_Socket, asio::buffer(data), ec);

            if (ec) {
                clearQueue();
                if (m_CloseConnectionCallback) {
                    m_IsConnected = false;
                    m_CloseConnectionCallback();
                }
            }
            return result;
        }

        void ClientTCPSession::getData(std::vector<uint8_t> &data) {
            popFromQueue(data);
        }

        void ClientTCPSession::receive() {
            auto self(shared_from_this());
            m_Socket.async_read_some(asio::buffer(m_ReceiveBuffer, m_MaxMessageSize),
                                     [this, self](std::error_code ec, std::size_t length) {
                                         if (ec) {
                                             clearQueue();
                                             m_IsConnected = false;
                                             if (m_CloseConnectionCallback) {
                                                 m_CloseConnectionCallback();
                                             }
                                             return;
                                         } else {
                                             std::vector <uint8_t> data;
                                             data.insert(data.end(), m_ReceiveBuffer, m_ReceiveBuffer + length);
                                             pushToQueue(data);
                                         }

                                         receive();
                                     });
        }

        void ClientTCPSession::pushToQueue(const std::vector<uint8_t> &data) {
            std::lock_guard <std::mutex> lock(m_QueueMutex);

            m_MessageQueue.push_back(data);
        }

        void ClientTCPSession::popFromQueue(std::vector<uint8_t> &data) {
            std::lock_guard <std::mutex> lock(m_QueueMutex);

            if (!m_MessageQueue.empty()) {
                data = std::move(m_MessageQueue.front());
                m_MessageQueue.pop_front();
            }
        }

        void ClientTCPSession::clearQueue() {
            m_MessageQueue.clear();
        }

        bool ClientTCPSession::connect(const tcp::endpoint &address) {
            try {
                m_IsConnected = false;
                std::error_code ec;
                m_Socket.connect(address, ec);
                if(!ec) {
                    m_IsConnected = true;
                    start();
                }
            } catch (std::exception & e) {
                m_IsConnected = false;
            }
            return m_IsConnected;
        }

    }
}