#include "ServerTCPSession.h"

namespace Lanter
{
    namespace Communication
    {
        ServerTCPSession::ServerTCPSession(tcp::socket socket, std::function<void()> closeConnectionCallback):
            m_Socket (std::move(socket)),
            m_CloseConnectionCallback(std::move(closeConnectionCallback)) {}

        void ServerTCPSession::start()
        {
            receive();
        }

        void ServerTCPSession::stop()
        {
            m_Socket.close();
        }

        size_t ServerTCPSession::send(const std::vector<uint8_t>& data)
        {
            std::error_code ec;
            auto result = asio::write(m_Socket, asio::buffer(data), ec);
            if (ec)
            {
                if (m_CloseConnectionCallback)
                {
                    m_CloseConnectionCallback();
                }
            }

            return result;
        }

        void ServerTCPSession::getData(std::vector<uint8_t>& data)
        {
            popFromQueue(data);
        }

        void ServerTCPSession::receive()
        {
            auto self(shared_from_this());
            m_Socket.async_read_some(asio::buffer(m_ReceiveBuffer, m_MaxMessageSize), [this, self](std::error_code ec, std::size_t length)
            {
                if (ec)
                {
                    if (m_CloseConnectionCallback)
                    {
                        m_CloseConnectionCallback();
                        return;
                    }
                }
                else
                {
                    std::vector <uint8_t> data;
                    data.insert(data.end(), m_ReceiveBuffer, m_ReceiveBuffer + length);
                    pushToQueue(data);
                }

                receive();
            });
        }

        void ServerTCPSession::pushToQueue(const std::vector<uint8_t>& data)
        {
            std::lock_guard <std::mutex> lock(m_QueueMutex);
            m_MessageQueue.push(data);
        }

        void ServerTCPSession::popFromQueue(std::vector<uint8_t>& data)
        {
            std::lock_guard <std::mutex> lock(m_QueueMutex);
            if (!m_MessageQueue.empty())
            {
                data = std::move(m_MessageQueue.front());
                m_MessageQueue.pop();
            }
        }
    }
}