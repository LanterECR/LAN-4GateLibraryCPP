#ifndef LAN_4GATELIBRARYCPP_TCPCLIENT_H
#define LAN_4GATELIBRARYCPP_TCPCLIENT_H

#include "Lanter/Communication/ICommunication.h"

#include <memory>

#include "asio.hpp"

namespace Lanter {
    namespace Communication {
        class ClientTCPSession;
        class TCPClient : public ICommunication, public std::enable_shared_from_this<TCPClient> {
        public:
            TCPClient(const std::string & ip, int port);
            void doCommunication() override;

            bool open() override;

            bool close() override;

            bool isOpen() override;

            bool connect() override;

            bool disconnect() override;

            bool isConnected() override;

            size_t send(const std::vector<uint8_t> &in) override;

            size_t receive(std::vector<uint8_t> &out) override;

        private:
            void disconnectCallback();
            asio::io_context m_Context;
            asio::ip::tcp::endpoint m_Endpoint;
            std::shared_ptr<asio::ip::tcp::socket> m_ClientSocket;

            void asyncReceive();

        private:
            std::vector<uint8_t> m_ReceiveBuffer;
            std::mutex m_QueueMutex;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_TCPCLIENT_H
