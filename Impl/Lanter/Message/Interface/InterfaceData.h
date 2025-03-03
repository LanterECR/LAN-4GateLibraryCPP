#ifndef LAN_4GATELIBRARYCPP_InterfaceDATA_H
#define LAN_4GATELIBRARYCPP_InterfaceDATA_H

#include "Lanter/Message/Interface/IInterfaceData.h"

namespace Lanter {
    namespace Message {
        namespace Interface {
            /// \brief Базовый класс-контейнер для получения экранов от финансового ПО LAN-4Tap
            class InterfaceData : public IInterfaceData {
            public:
                ~InterfaceData() override = default;

                InterfaceType getType() const override;
                bool setType(InterfaceType uiType) override;
                bool resetType() override;

                const std::string& getTitle() const override;
                bool setTitle(const std::string& title) override;
                bool resetTitle() override;

                const std::string& getValue() const override;
                bool setValue(const std::string& value) override;
                bool resetValue() override;

                const std::string& getInfoText() const override;
                bool setInfoText(const std::string& infoText) override;
                bool resetInfoText() override;

                const std::string& getMinLen() const override;
                bool setMinLen(const std::string& minLen) override;
                bool resetMinLen() override;

                const std::string& getMaxLen() const override;
                bool setMaxLen(const std::string& maxLen) override;
                bool resetMaxLen() override;

                const std::string& getResult() const override;
                bool setResult(const std::string& result) override;
                bool resetResult() override;
            private:
                InterfaceType m_Type = InterfaceType::Unknown;

                std::string m_Title;
                std::string m_Value;
                std::string m_InfoText;
                std::string m_MinLen;
                std::string m_MaxLen;
                std::string m_Result;
            };//class InterfaceData
        }//namespace Interface
    }//namespace Message
}//namespace Lanter
#endif //LAN_4GATELIBRARYCPP_InterfaceDATA_H
