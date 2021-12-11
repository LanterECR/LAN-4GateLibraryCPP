#include "TCPSession.h"


namespace Lanter {
    namespace Communication {

        TCPSession::TCPSession(tcp::socket socket, std::function<void()> closeConnectionCallback):
            m_Socket (std::move(socket)),
            m_CloseConnectionCallback(std::move(closeConnectionCallback)) {}

        void TCPSession::start() {
            receive();
        }

        void TCPSession::stop() {
            m_Socket.close();
        }

        size_t TCPSession::send(const std::vector<uint8_t> &data) {
            std::error_code ec;
            auto result = asio::write(m_Socket, asio::buffer(data), ec);

            if (ec) {
                if (m_CloseConnectionCallback) {
                    m_CloseConnectionCallback();
                }
            }
            return result;
        }

        void TCPSession::getData(std::vector<uint8_t> &data) {
            popFromQueue(data);
        }

        void TCPSession::receive() {
            auto self(shared_from_this());
            m_Socket.async_read_some(asio::buffer(m_ReceiveBuffer, m_MaxMessageSize),
                                     [this, self](std::error_code ec, std::size_t length) {
                                         if (ec) {
                                             if (m_CloseConnectionCallback) {
                                                 m_CloseConnectionCallback();
                                                 return;
                                             }
                                         } else {
                                             std::vector <uint8_t> data;
                                             data.insert(data.end(), m_ReceiveBuffer, m_ReceiveBuffer + length);
                                             pushToQueue(data);
                                         }

                                         receive();
                                     });
        }

        void TCPSession::pushToQueue(const std::vector<uint8_t> &data) {
            std::lock_guard <std::mutex> lock(m_QueueMutex);

            m_MessageQueue.push(data);
        }

        void TCPSession::popFromQueue(std::vector<uint8_t> &data) {
            std::lock_guard <std::mutex> lock(m_QueueMutex);

            if (!m_MessageQueue.empty()) {
                data = std::move(m_MessageQueue.front());
                m_MessageQueue.pop();
            }
        }


    }
}