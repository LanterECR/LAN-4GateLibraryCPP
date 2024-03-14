#include "InteractionData.h"
#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interaction
        {
            InteractionCode InteractionData::getCode() const
            {
                return m_Code;
            }

            bool InteractionData::setCode(InteractionCode code)
            {
                if (Utils::checkInteractionsRange(static_cast<int64_t>(code)))
                {
                    m_Code = code;
                    return true;
                }//if check

                return false;
            }

            bool InteractionData::resetCode()
            {
                m_Code = InteractionCode::NoInteraction;
                return true;
            }
        }
    }
}