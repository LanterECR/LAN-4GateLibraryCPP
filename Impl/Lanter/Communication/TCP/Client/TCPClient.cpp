#include "TCPClient.h"

#include "TCPSession.h"

namespace Lanter {
    namespace Communication {

        TCPClient::TCPClient(const std::string &ip, int port) {
            m_Endpoint = asio::ip::tcp::endpoint(asio::ip::address::from_string(ip), port);
        }

        void TCPClient::doCommunication() {
            m_Context.poll();
        }

        bool TCPClient::open() {
            return connect();
        }

        bool TCPClient::close() {
            disconnect();
            return m_CurrentConnection == nullptr;
        }

        bool TCPClient::isOpen() {
            return isConnected();
        }

        bool TCPClient::connect() {
            if(m_CurrentConnection == nullptr) {
                tcp::socket clientSocket(m_Context);
                m_CurrentConnection = std::make_shared<TCPSession>(std::move(clientSocket), [this](){disconnectCallback();});
            }
            return m_CurrentConnection->connect(m_Endpoint);
        }

        bool TCPClient::disconnect() {
            if(m_CurrentConnection) {
                m_CurrentConnection->stop();
            }
            m_CurrentConnection.reset();
            return true;
        }

        bool TCPClient::isConnected() {
            bool result = false;
            if(m_CurrentConnection != nullptr) {
                result = m_CurrentConnection->isConnected();
            }
            return result;
        }

        size_t TCPClient::send(const std::vector<uint8_t> &in) {
            size_t result = 0;
            if(m_CurrentConnection != nullptr) {
                result = m_CurrentConnection->send(in);
            }
            return result;
        }

        size_t TCPClient::receive(std::vector<uint8_t> &out) {
            size_t result = 0;

            out.clear();
            if(m_CurrentConnection != nullptr) {
                m_CurrentConnection->getData(out);

                result = out.size();
            }

            return result;
        }

        void TCPClient::disconnectCallback() {
            m_CurrentConnection->stop();

        }
    }
}