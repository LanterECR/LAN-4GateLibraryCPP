#include "CardVerification.h"

namespace Lanter
{
    namespace Message
	{
        namespace Response
		{
            void Response::ECertRefund::addSpecificFields()
			{
                appendOptionalField(ResponseField::EcrNumber);
				appendOptionalField(ResponseField::OperationCode);
				appendOptionalField(ResponseField::TerminalID);
				appendOptionalField(ResponseField::ResponseCode);
				appendOptionalField(ResponseField::ResponseText);
				appendOptionalField(ResponseField::Status);
			}
        }
    }
}