#include "InteractionData.h"

#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter {
    namespace Message {
        namespace Interaction {

            InteractionCode InteractionData::getCode() const {
                return m_Code;
            }

            bool InteractionData::setCode(InteractionCode code) {
                bool result = false;
                if (Utils::checkInteractionsRange(static_cast<int32_t>(code))) {
                    m_Code = code;
                    result = true;
                }//if check

                return result;
            }

            bool InteractionData::resetCode() {
                m_Code = InteractionCode::NoInteraction;
                return m_Code == InteractionCode::NoInteraction;
            }
        }
    }
}