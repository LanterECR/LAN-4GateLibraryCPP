#include "ECertGetRequisites.h"

namespace Lanter {
    namespace Message {
        namespace Request {
            void Request::ECertGetRequisites::addSpecificFields() {
				appendMandatoryField(RequestField::EcrMerchantNumber);
			}
        }
    }
}
