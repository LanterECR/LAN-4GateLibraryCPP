#include "Lanter/Message/Interface/InterfaceData.h"
#include "Lanter/Message/Interface/InterfaceDataFactory.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interface
        {
            std::shared_ptr<IInterfaceData> InterfaceDataFactory::getInterfaceData(InterfaceType type)
            {
                auto ui = std::make_shared<InterfaceData>();
                if(ui != nullptr)
                {
                    ui->setType(type);
                }

                return ui;
            }

            std::shared_ptr <IInterfaceData> InterfaceDataFactory::getInterfaceData()
            {
                return getInterfaceData(InterfaceType::Unknown);
            } //getInterfaceData()
        }//namespace Interface
    }//namespace Message
}//namespace Lanter