#ifndef TESTL4G_TCPSESSION_H
#define TESTL4G_TCPSESSION_H

#include <deque>
#include <functional>
#include <mutex>

#include "asio.hpp"

using asio::ip::tcp;

namespace Lanter {
    namespace Communication {
        class ClientTCPSession : public std::enable_shared_from_this<ClientTCPSession> {
        public:

            explicit ClientTCPSession(tcp::socket socket, std::function<void()> closeConnectionCallback);

            void start();

            void stop();

            size_t send(const std::vector<uint8_t> &data);

            void getData(std::vector<uint8_t> &data);

            void receive();

            bool connect(const asio::ip::tcp::endpoint & address);

            bool isConnected() const { return m_IsConnected; }
        private:
            void pushToQueue(const std::vector<uint8_t> &data);

            void popFromQueue(std::vector<uint8_t> &data);

            void clearQueue();

            tcp::socket m_Socket;

            std::function<void()> m_CloseConnectionCallback;

            enum { m_MaxMessageSize = 16384 };

            uint8_t m_ReceiveBuffer[m_MaxMessageSize];

            std::deque<std::vector<uint8_t> > m_MessageQueue;
            std::mutex m_QueueMutex;

            bool m_IsConnected = false;
        };
    }
}

#endif //TESTL4G_TCPSESSION_H
