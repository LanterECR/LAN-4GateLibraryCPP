#ifndef LAN_4GATELIB_SIZECONTROLDECORATOR_H
#define LAN_4GATELIB_SIZECONTROLDECORATOR_H

#include <memory>
#include <deque>
#include <string>

#include "Lanter/Communication/ICommunication.h"

namespace Lanter {
    namespace Communication {
        class SizeControlDecorator : public ICommunication{
        public:
            explicit SizeControlDecorator(std::shared_ptr<ICommunication> communication);

            void doCommunication() override;

            bool open() override;

            bool close() override;

            bool isOpen() override;

            bool connect() override;

            bool disconnect() override;

            bool isConnected() override;

            size_t send(const std::vector<uint8_t> &in) override;

            size_t receive(std::vector<uint8_t> &out) override;
            bool checkHex(const std::string & value);
            int getReceiveSize(const std::vector<uint8_t> & data);

        private:
            bool getDataToQueue(std::vector<uint8_t> & data);
            bool getDataFromQueue(std::vector<uint8_t> & data);
            void resetState();

            std::shared_ptr<ICommunication> m_Communication;

            int m_SizeCharsCount = 4; //Жесткая фиксация длины на 4 ASCII-HEX символа
            int m_MessageSize = -1;
            std::vector<uint8_t> m_CurrentBuffer;
            std::deque<std::vector<uint8_t> > m_ReceivedData;
        };
    }
}

#endif //LAN_4GATELIB_SIZECONTROLDECORATOR_H
