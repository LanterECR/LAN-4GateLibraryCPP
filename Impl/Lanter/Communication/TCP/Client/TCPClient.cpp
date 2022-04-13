#include "TCPClient.h"

#include "Lanter/Manager/Lan4GateLogger.h"

namespace Lanter {
    namespace Communication {

        const size_t TCP_CLIENT_BUFFER_SIZE = 16384;
        unsigned char n_spbuffer[TCP_CLIENT_BUFFER_SIZE];

        TCPClient::TCPClient(const std::string &ip, int port) {
            m_ClientSocket = nullptr;
            m_Endpoint = asio::ip::tcp::endpoint(asio::ip::address::from_string(ip), port);
        }

        void TCPClient::doCommunication() {
            m_Context.poll();
        }

        bool TCPClient::open() {
            return connect();
        }

        bool TCPClient::close() {
            return disconnect();
        }

        bool TCPClient::isOpen() {
            return isConnected();
        }

        bool TCPClient::connect() {
            try {
                m_ClientSocket = std::make_shared<asio::ip::tcp::socket>(m_Context);

                std::error_code ec;
                m_ClientSocket->connect(m_Endpoint, ec);
                if (!ec) {
                    asyncReceive();
                    return true;
                }
            }
            catch (std::exception& e) {
            }

            disconnect();

            return false;
        }

        bool TCPClient::disconnect() {
            if (m_ClientSocket)
            {
                m_ClientSocket->cancel();
                m_ClientSocket->close();

                m_Context.stop();
                m_Context.reset();

                m_ClientSocket.reset();
                m_ClientSocket = nullptr;
            }

            return true;
        }

        bool TCPClient::isConnected() {
            bool result = false;
            if (m_ClientSocket && m_ClientSocket->is_open()) {
                result = true;
            }
            return result;
        }

        size_t TCPClient::send(const std::vector<uint8_t> &in) {
            size_t result = 0;
            if (isConnected()) {
                try {
                    asio::error_code ec;
                    result = m_ClientSocket->write_some(asio::buffer(in), ec);
                } catch (std::exception& e) {
                    result = 0;
                }
                if (result == 0) {
                    disconnect();
                }
            }
            return result;
        }

        size_t TCPClient::receive(std::vector<uint8_t> &out) {
            out.clear();

            std::lock_guard <std::mutex> lock(m_QueueMutex);

            if (m_ReceiveBuffer.size() > 0) {
                std::copy(m_ReceiveBuffer.begin(), m_ReceiveBuffer.end(), std::back_inserter(out));
                m_ReceiveBuffer.clear();
            }

            return out.size();
        }

        void TCPClient::disconnectCallback() {
            disconnect();
        }

        void TCPClient::asyncReceive() {
            if (!m_ClientSocket) {
                return;
            }

            auto self(shared_from_this());
            m_ClientSocket->async_read_some(asio::buffer(n_spbuffer, TCP_CLIENT_BUFFER_SIZE),
                [this, self](std::error_code ec, std::size_t length) {
                    if (ec) {
                        disconnect();
                    } else {
                        if (length > 0) {
                            m_ReceiveBuffer.insert(m_ReceiveBuffer.end(), n_spbuffer, n_spbuffer + length);
                        }
                        asyncReceive();
                    }
            });
        }

    }
}