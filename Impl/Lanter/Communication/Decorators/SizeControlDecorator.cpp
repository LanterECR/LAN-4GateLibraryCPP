#include "SizeControlDecorator.h"

#include <sstream>

namespace Lanter {
    namespace Communication {
        SizeControlDecorator::SizeControlDecorator(std::shared_ptr<ICommunication> communication) :
            m_Communication(communication){

        }

        void SizeControlDecorator::doCommunication() {
            if(m_Communication != nullptr) {
                m_Communication->doCommunication();
            }
        }

        bool SizeControlDecorator::open() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->open();
            }
            return result;
        }

        bool SizeControlDecorator::close() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->close();
            }
            return result;
        }

        bool SizeControlDecorator::isOpen() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->isOpen();
            }
            return result;
        }

        bool SizeControlDecorator::connect() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->connect();
            }
            return result;
        }

        bool SizeControlDecorator::disconnect() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->disconnect();
            }
            return result;
        }

        bool SizeControlDecorator::isConnected() {
            bool result = false;
            if(m_Communication != nullptr) {
                result = m_Communication->isConnected();
            }
            return result;
        }

        //TODO Переделать нормально. Большие потери памяти
        size_t SizeControlDecorator::send(const std::vector<uint8_t> &in) {
            bool result = false;
            if(m_Communication != nullptr) {
                std::string hexLength;

                std::stringstream ss;
                ss << std::hex << in.size();
                ss >> hexLength;

                while(hexLength.size() < m_SizeCharsCount) {
                    hexLength = "0" + hexLength;
                }

                std::vector<uint8_t> resultData(hexLength.begin(), hexLength.end());
                resultData.insert(resultData.end(), in.begin(), in.end());

                result = m_Communication->send(resultData);
            }
            return result;
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
                std::string size (data.begin(), std::next(data.begin(), m_SizeCharsCount));
                if (checkHex(size))
                {
                    std::stringstream ss;
                    ss << std::hex << size;
                    ss >> result;
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

        bool SizeControlDecorator::getDataFromQueue(std::vector<uint8_t> &data) {
            bool result = false;
            if (!m_ReceivedData.empty())
            {
                auto receivedData = m_ReceivedData.front();
                m_ReceivedData.pop_front();

                data.clear();
                std::swap(data, receivedData);

                result = !data.empty();
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