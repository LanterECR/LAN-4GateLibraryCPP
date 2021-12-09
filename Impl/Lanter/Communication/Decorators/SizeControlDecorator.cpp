#include "SizeControlDecorator.h"

namespace Lanter {
    namespace Communication {
        SizeControlDecorator::SizeControlDecorator(std::shared_ptr<ICommunication> communication) :
            m_Communication(communication){

        }

        void SizeControlDecorator::doCommunication() {

        }

        bool SizeControlDecorator::open() {
            return false;
        }

        bool SizeControlDecorator::close() {
            return false;
        }

        bool SizeControlDecorator::isOpen() {
            return false;
        }

        bool SizeControlDecorator::connect() {
            return false;
        }

        bool SizeControlDecorator::disconnect() {
            return false;
        }

        bool SizeControlDecorator::isConnected() {
            return false;
        }

        size_t SizeControlDecorator::send(const std::vector<uint8_t> &in) {
            return 0;
        }

        size_t SizeControlDecorator::receive(std::vector<uint8_t> &out) {
            return 0;
        }

        bool SizeControlDecorator::checkHex(const std::string &value) {
            static std::string hex = "0123456789abcdefABCDEF";
            for (std::string::const_iterator i = value.begin(); i != value.end(); i++)
            {
                if (hex.find(*i) == std::string::npos)
                {
                    return false;
                }
            }
            return true;
        }

        int SizeControlDecorator::getReceiveSize(const std::vector<uint8_t> &data) {
            int result = 0;
            if (data.size() >= m_SizeCharsCount)
            {
                std::string size (data.begin(), std::next(data.begin(), m_SizeCharsCount -1));
                if (checkHex(size))
                {
                    result = std::stoi(size);
                }
            }
            return result;
        }

        bool SizeControlDecorator::getDataToQueue(std::vector<uint8_t> &data) {
            bool result = false;

            if (m_MessageSize > 0 && data.size() >= m_MessageSize + m_SizeCharsCount)
            {
                auto startIterator = std::next(data.begin(), m_SizeCharsCount);
                auto endIterator = std::next(startIterator , m_MessageSize);
                std::vector<uint8_t> dataFragment(startIterator, endIterator);
                m_ReceivedData.push_back(dataFragment);

                data.erase(data.begin(), endIterator);

                result = true;
            }
            return result;
        }

        bool SizeControlDecorator::getDataFromQueue(std::vector<uint8_t> &data, size_t maxLen) {
            bool result = false;
            if (!m_ReceivedData.empty())
            {
                auto receivedData = m_ReceivedData.front();
                m_ReceivedData.pop_front();

                if (receivedData.size() > maxLen)
                {
                    m_ReceivedData.push_front(receivedData.mid(0, maxLen));
                }

                data.clear();
                data.append(receivedData.mid(0, maxLen));

                if (data.size() > 0)
                {
                    result = Status::Success;
                }
            }
            return result;
        }

        void SizeControlDecorator::resetState() {
            m_MessageSize = -1;
            m_CurrentBuffer.clear();
            m_ReceivedData.clear();
        }
    }
}