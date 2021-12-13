#ifndef TESTL4G_SINGLETCPSERVER_H
#define TESTL4G_SINGLETCPSERVER_H

#include "asio.hpp"

#include "Lanter/Communication/ICommunication.h"

using asio::ip::tcp;

namespace Lanter {
    namespace Communication {
        class ServerTCPSession;
        class SingleTCPServer : public ICommunication {
        public:
            explicit  SingleTCPServer(int port);

            void doCommunication() override;

            bool open() override;

            bool close() override;

            bool isOpen() override;

            bool connect() override { return true; }

            bool disconnect() override;

            bool isConnected() override;

            size_t send(const std::vector<uint8_t> &in) override;

            size_t receive(std::vector<uint8_t> &out) override;

        private:

            void accept();

            asio::io_context m_Context;
            std::shared_ptr<tcp::acceptor> m_ServerAcceptor;

            std::shared_ptr<ServerTCPSession> m_CurrentConnection;

            int m_Port;
        };
    }
}

#endif //TESTL4G_SINGLETCPSERVER_H
