#ifndef LAN_4GATELIB_MOCKCOMM_H
#define LAN_4GATELIB_MOCKCOMM_H

#include "Lanter/Communication/ICommunication.h"

namespace Lanter {
    class MOCKComms : public Communication::ICommunication {
    public:
        MOCK_METHOD(bool, open, (), (override));
        MOCK_METHOD(bool, close, (), (override));
        MOCK_METHOD(bool, isOpen, (), (override));

        MOCK_METHOD(size_t, send, (const std::vector<uint8_t> &), (override));
        MOCK_METHOD(size_t, receive, (std::vector<uint8_t> & ), (override));
    };
}

#endif //LAN_4GATELIB_MOCKCOMM_H
