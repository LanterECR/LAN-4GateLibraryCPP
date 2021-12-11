#include "SingleTCPServer.h"

#include "ServerTCPSession.h"
namespace Lanter {
    namespace Communication {

        SingleTCPServer::SingleTCPServer(int port) :
            m_Port(port) { }

        void SingleTCPServer::doCommunication() {
            if(m_ServerAcceptor != nullptr) {
                m_Context.poll();
            }
        }

        bool SingleTCPServer::open() {
            bool result = true;
            try {
                m_ServerAcceptor = std::make_shared<tcp::acceptor>(m_Context, tcp::endpoint(tcp::v4(), m_Port));
                accept();
            } catch (std::exception &) {
                result = false;
            }
            return result;
        }

        bool SingleTCPServer::close() {
            disconnect();
            if(m_ServerAcceptor != nullptr) {
                m_ServerAcceptor.reset();
            }
            return m_CurrentConnection == nullptr && m_ServerAcceptor == nullptr;
        }

        bool SingleTCPServer::isOpen() {
            return m_ServerAcceptor != nullptr && m_ServerAcceptor->is_open();
        }

        bool SingleTCPServer::disconnect() {
            if(m_CurrentConnection) {
                m_CurrentConnection->stop();
            }
            m_CurrentConnection.reset();
            return true;
        }

        bool SingleTCPServer::isConnected() {
            return m_CurrentConnection != nullptr;
        }

        size_t SingleTCPServer::send(const std::vector<uint8_t> &in) {
            size_t result = 0;
            if(m_CurrentConnection != nullptr) {
                m_CurrentConnection->send(in);
            }
            return result;
        }

        size_t SingleTCPServer::receive(std::vector<uint8_t> &out) {
            size_t result = 0;

            if(m_CurrentConnection != nullptr) {
                m_CurrentConnection->getData(out);

                result = out.size();
            }

            return result;
        }

        void SingleTCPServer::accept() {
            if(m_ServerAcceptor != nullptr) {
                m_ServerAcceptor->async_accept([this](std::error_code ec, tcp::socket socket) {
                    if (!ec)
                    {
                        if(m_CurrentConnection == nullptr) {
                            m_CurrentConnection = std::make_shared<ServerTCPSession>(std::move(socket), [this](){disconnect();});
                            m_CurrentConnection->start();
                        } else {
                            socket.close();
                        }
                        accept();
                    }
                });

            }
        }


    }
}