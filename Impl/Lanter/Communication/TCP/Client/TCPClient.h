#ifndef LAN_4GATELIBRARYCPP_TCPCLIENT_H
#define LAN_4GATELIBRARYCPP_TCPCLIENT_H

#include "ICommunication.h"

#include <memory>

#include "asio.hpp"

namespace Lanter {
    namespace Communication {
        class TCPSession;
        class TCPClient : public ICommunication{
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
            asio::ip::tcp::endpoint m_Endpoint;
            asio::io_service m_Context;
            std::shared_ptr<TCPSession> m_CurrentConnection;
        };
    }
}

#endif //LAN_4GATELIBRARYCPP_TCPCLIENT_H
