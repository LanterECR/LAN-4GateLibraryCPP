#ifndef LAN_4GATELIBRARYCPP_GATEWAYDATA_H
#define LAN_4GATELIBRARYCPP_GATEWAYDATA_H

#include "Lanter/Message/Gateway/IGatewayData.h"

namespace Lanter {
    namespace Message {
        namespace Gateway {
            /// \brief Базовый класс-контейнер для шлюза от финансового ПО LAN-4Tap
            class GatewayData : public IGatewayData {
            public:
                ~GatewayData() override = default;

                GatewayCode getCode() const override;
                bool setCode(GatewayCode gatewayCode) override;
                bool resetCode() override;

                const std::string& getIP() const override;
                bool setIP(const std::string& ip) override;
                bool resetIP() override;

                const int& getPort() const override;
                bool setPort(const int& port) override;
                bool resetPort() override;

                const int& getLink() const override;
                bool setLink(const int& link) override;
                bool resetLink() override;

                const int& getStatus() const override;
                bool setStatus(const int& status) override;
                bool resetStatus() override;

                const std::vector<int8_t>& getData() const override;
                bool setData(const std::vector<int8_t>& data) override;
                bool resetData() override;

            private:
                GatewayCode m_Code = GatewayCode::NoCode;
                std::string m_IP;
                int m_Port;
                int m_Link;
                int m_Status;
                std::vector<int8_t> m_Data;
            };//class GatewayData
        }//namespace Gateway
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_GATEWAYDATA_H
