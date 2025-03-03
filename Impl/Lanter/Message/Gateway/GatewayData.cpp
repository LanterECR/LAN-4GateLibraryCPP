#include "GatewayData.h"
#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter
{
    namespace Message
    {
        namespace Gateway
        {
            GatewayCode GatewayData::getCode() const
            {
                return m_Code;
            }//getCode()

            bool GatewayData::setCode(GatewayCode gatewayCode)
            {
                m_Code = gatewayCode;
                return true;
            }//setCode()

            bool GatewayData::resetCode()
            {
                m_Code = GatewayCode::NoCode;
                return m_Code == GatewayCode::NoCode;
            }//resetCode()

            const std::string & GatewayData::getIP() const
            {
                return m_IP;
            }//getIP()

            bool GatewayData::setIP(const std::string & ip)
            {
                if(!ip.empty())
                {
                    m_IP = ip;
                    return true;
                }//ip not empty

                return false;
            }//setIP()

            bool GatewayData::resetIP()
            {
                m_IP.clear();
                return m_IP.empty();
            }//resetIP()

            const int& GatewayData::getPort() const
            {
                return m_Port;
            }
            bool GatewayData::setPort(const int& port)
            {
                m_Port = port;
                return true;
            }
            bool GatewayData::resetPort()
            {
                m_Port = 0;
                return true;
            }

            const int& GatewayData::getLink() const
            {
                return m_Link;
            }
            bool GatewayData::setLink(const int& link)
            {
                m_Link = link;
                return true;
            }
            bool GatewayData::resetLink()
            {
                m_Link = 0;
                return true;
            }

            const int& GatewayData::getStatus() const
            {
                return m_Status;
            }
            bool GatewayData::setStatus(const int& status)
            {
                m_Status = status;
                return true;
            }
            bool GatewayData::resetStatus()
            {
                m_Status = -1;
                return true;
            }

            const std::vector<int8_t>& GatewayData::getData() const
            {
                return m_Data;
            }
            bool GatewayData::setData(const std::vector<int8_t>& data)
            {
                m_Data = data;
                return m_Data.size() == data.size();
            }
            bool GatewayData::resetData()
            {
                m_Data.clear();
                return m_Data.size() == 0;
            }
        }//namespace Gateway
    }//namespace Message
}//namespace Lanter