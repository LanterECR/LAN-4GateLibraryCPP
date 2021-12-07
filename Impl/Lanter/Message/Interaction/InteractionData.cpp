#include "InteractionData.h"

namespace Lanter {
    namespace Message {
        namespace Interaction {

            InteractionCode InteractionData::getCode() const {
                return m_Code;
            }

            void InteractionData::setCode(InteractionCode code) {
                m_Code = code;
            }
        }
    }
}