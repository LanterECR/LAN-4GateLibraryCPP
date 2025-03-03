#include "InterfaceData.h"
#include "Lanter/Utils/FieldRangeChecker.h"

namespace Lanter
{
    namespace Message
    {
        namespace Interface
        {
            InterfaceType InterfaceData::getType() const
            {
                return m_Type;
            }//getCode()

            bool InterfaceData::setType(InterfaceType uiType)
            {
                m_Type = uiType;
                return true;
            }//setCode()

            bool InterfaceData::resetType()
            {
                m_Type = InterfaceType::Unknown;
                return m_Type == InterfaceType::Unknown;
            }//resetCode()

            const std::string& InterfaceData::getTitle() const
            {
                return m_Title;
            }//getTitle()

            bool InterfaceData::setTitle(const std::string& title)
            {
                if (!title.empty())
                {
                    m_Title = title;
                    return true;
                }//title not empty

                return false;
            }//setTitle()

            bool InterfaceData::resetTitle()
            {
                m_Title.clear();
                return m_Title.empty();
            }//resetTitle()

            const std::string& InterfaceData::getValue() const
            {
                return m_Value;
            }//getValue()

            bool InterfaceData::setValue(const std::string& value)
            {
                if (!value.empty())
                {
                    m_Value = value;
                    return true;
                }//value not empty

                return false;
            }//setValue()

            bool InterfaceData::resetValue()
            {
                m_Value.clear();
                return m_Value.empty();
            }//resetValue()

            const std::string& InterfaceData::getInfoText() const
            {
                return m_InfoText;
            }//getInfoText()

            bool InterfaceData::setInfoText(const std::string& infoText)
            {
                if (!infoText.empty())
                {
                    m_InfoText = infoText;
                    return true;
                }//infoText not empty

                return false;
            }//setInfoText()

            bool InterfaceData::resetInfoText()
            {
                m_InfoText.clear();
                return m_InfoText.empty();
            }//resetInfoText()

            const std::string& InterfaceData::getMinLen() const
            {
                return m_MinLen;
            }//getMinLen()

            bool InterfaceData::setMinLen(const std::string& minLen)
            {
                if (!minLen.empty())
                {
                    m_MinLen = minLen;
                    return true;
                }//minLen not empty

                return false;
            }//setMinLen()

            bool InterfaceData::resetMinLen()
            {
                m_MinLen.clear();
                return m_MinLen.empty();
            }//resetMinLen()

            const std::string& InterfaceData::getMaxLen() const
            {
                return m_MaxLen;
            }//getMaxLen()

            bool InterfaceData::setMaxLen(const std::string& maxLen)
            {
                if (!maxLen.empty())
                {
                    m_MaxLen = maxLen;
                    return true;
                }//maxLen not empty

                return false;
            }//setMaxLen()

            bool InterfaceData::resetMaxLen()
            {
                m_MaxLen.clear();
                return m_MaxLen.empty();
            }//resetMaxLen()

            const std::string& InterfaceData::getResult() const
            {
                return m_Result;
            }//getResult()

            bool InterfaceData::setResult(const std::string& result)
            {
                if (!result.empty())
                {
                    m_Result = result;
                    return true;
                }//result not empty

                return false;
            }//setResult()

            bool InterfaceData::resetResult()
            {
                m_Result.clear();
                return m_Result.empty();
            }//resetResult()
        }//namespace Interface
    }//namespace Message
}//namespace Lanter