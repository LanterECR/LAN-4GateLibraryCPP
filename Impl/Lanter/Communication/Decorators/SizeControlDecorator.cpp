#include "SizeControlDecorator.h"

#include <algorithm> // для std::min
#include <sstream>

namespace Lanter
{
	namespace Communication	{
		SizeControlDecorator::SizeControlDecorator(std::shared_ptr<ICommunication> communication) :
			m_Communication(communication),
			m_SizeCharsCount(4), //Жесткая фиксация длины на 4 ASCII-HEX символа
			m_MessageSize(-1)
		{
		}

		void SizeControlDecorator::doCommunication()		{
			if(m_Communication != nullptr)			{
				m_Communication->doCommunication();
			}
		}

		bool SizeControlDecorator::open()		{
			bool result = false;
			if(m_Communication != nullptr)			{
				result = m_Communication->open();
			}

			return result;
		}

		bool SizeControlDecorator::close()		{
			bool result = false;
			if(m_Communication != nullptr)			{
				result = m_Communication->close();
			}

			return result;
		}

		bool SizeControlDecorator::isOpen()		{
			bool result = false;
			if(m_Communication != nullptr)			{
				result = m_Communication->isOpen();
			}

			return result;
		}

		bool SizeControlDecorator::connect()		{
			bool result = false;
			if(m_Communication != nullptr)			{
				result = m_Communication->connect();
			}

			return result;
		}

		bool SizeControlDecorator::disconnect()		{
			bool result = false;
			if(m_Communication != nullptr)			{
				result = m_Communication->disconnect();
			}

			return result;
		}

		bool SizeControlDecorator::isConnected()		{
			bool result = false;
			if(m_Communication != nullptr)			{
				result = m_Communication->isConnected();
			}

			return result;
		}

		//TODO Переделать нормально. Большие потери памяти
		size_t SizeControlDecorator::send(const std::vector<uint8_t>& in)		{
			size_t result = 0;
			//if (m_Communication != nullptr)
			//{
			//	const size_t inSize = in.size();
			//	if (inSize > 65534)
			//	{
			//		std::vector<uint8_t> resultData = { 0xFF, 0xFF };
			//		std::string hexLength = std::string(8 - std::min(8, static_cast<int>(std::to_string(inSize).size())), '0') + std::to_string(inSize);
			//		resultData.insert(resultData.end(), hexLength.begin(), hexLength.end());
			//		resultData.insert(resultData.end(), in.begin(), in.end());
			//		result = m_Communication->send(resultData);
			//	}
			//	else
			//	{
			//		std::string hexLength = std::string(m_SizeCharsCount - std::min(m_SizeCharsCount, static_cast<int>(std::to_string(inSize).size())), '0') + std::to_string(inSize);
			//		std::vector<uint8_t> resultData(hexLength.begin(), hexLength.end());
			//		resultData.insert(resultData.end(), in.begin(), in.end());
			//		result = m_Communication->send(resultData);
			//	}
			//}
			if(m_Communication != nullptr)			{
				const size_t& inSize = in.size();
				if (inSize > 65534)
				{

					std::string hexLength;
					std::stringstream ss;
					ss << std::hex << in.size();
					ss >> hexLength;

					while (hexLength.size() < 8)					{
						hexLength = "0" + hexLength;
					}

					std::vector<uint8_t> resultData = { 0xFF, 0xFF };
					resultData.reserve(6 + inSize);
					resultData.insert(resultData.end(), hexLength.begin(), hexLength.end());
					resultData.insert(resultData.end(), in.begin(), in.end());

					result = m_Communication->send(resultData);
				}
				else
				{
					std::string hexLength;
					std::stringstream ss;
					ss << std::hex << in.size();
					ss >> hexLength;

					while (hexLength.size() < m_SizeCharsCount)					{
						hexLength = "0" + hexLength;
					}

					std::vector<uint8_t> resultData(hexLength.begin(), hexLength.end());
					resultData.insert(resultData.end(), in.begin(), in.end());

					result = m_Communication->send(resultData);
				}
			}

			return result;
		}

		size_t SizeControlDecorator::receive(std::vector<uint8_t>& out)		{
			size_t result = 0;
			if (m_Communication)			{
				std::vector<uint8_t> receivedData;
				m_Communication->receive(receivedData);
				if (!receivedData.empty())				{
					m_CurrentBuffer.insert(m_CurrentBuffer.end(), receivedData.begin(), receivedData.end());
				}

				//Эта странная логика с двойным if используется для того, чтобы за один заход получить размер и само сообщение. Как написать чисто пока не придумал.
				if (m_MessageSize <= 0)				{
					m_MessageSize = getReceiveSize(m_CurrentBuffer);
				}

				if (m_MessageSize > 0)
				{
					if (getDataToQueue(m_CurrentBuffer))
					{
						m_MessageSize = -1;
					}
				}

				if (!m_ReceivedData.empty())
				{
					result = getDataFromQueue(out);
				}
			}

			return result;
		}

		bool SizeControlDecorator::checkHex(const std::string& value)		{
			static std::string hex = "0123456789abcdefABCDEF";
			for (std::string::const_iterator i = value.begin(); i != value.end(); ++i)
			{
				if (hex.find(*i) == std::string::npos)
				{
					return false;
				}
			}

			return true;
		}

		int SizeControlDecorator::getReceiveSize(const std::vector<uint8_t>& data)		{
			//int result = 0;
			//if (data.size() >= m_SizeCharsCount + 4) // Проверяем, что в data достаточно байтов
			//{
			//	// Проверяем первые два байта
			//	if (data[0] == 0xff && data[1] == 0xff)
			//	{
			//		// Читаем следующие четыре байта
			//		std::vector<uint8_t> sizeBytes(data.begin() + m_SizeCharsCount, data.begin() + m_SizeCharsCount + 4);

			//		// Преобразуем байты в int
			//		result = (sizeBytes[0] << 24) | (sizeBytes[1] << 16) | (sizeBytes[2] << 8) | sizeBytes[3];
			//	}
			//	else
			//	{
			//		// Если первые два байта не равны 0xff 0xff, преобразуем их в int
			//		result = (data[0] << 8) | data[1];
			//	}
			//}

			//return result;
			
			int result = 0;
			if (data.size() >= m_SizeCharsCount)
			{
				//const std::string smallSize(data.begin(), std::next(data.begin(), m_SizeCharsCount));
				const std::string smallSize(data.begin(), data.begin() + m_SizeCharsCount);
				if (checkHex(smallSize))
				{
					std::stringstream ss;
					ss << std::hex << smallSize;
					ss >> result;
				}

				if (result == 65535)
				{
					result = 0;
					std::string bigSize(data.begin() + m_SizeCharsCount, data.begin() + 12);
					//const std::string bigSize(data.begin() + m_SizeCharsCount, std::next(data.begin() + m_SizeCharsCount, 8));
					if (checkHex(bigSize))
					{
						std::stringstream ss;
						ss << std::hex << bigSize;
						ss >> result;
					}
				}
			}

			return result;
		}

		bool SizeControlDecorator::getDataToQueue(std::vector<uint8_t>& data)		{
			bool result = false;
			int sizeCharsCount = m_SizeCharsCount;
			if (m_MessageSize > 65534)
			{
				sizeCharsCount += 8;
			}

			if ((m_MessageSize > 0) && (data.size() >= (m_MessageSize + sizeCharsCount)))
			{
				auto startIterator = std::next(data.begin(), sizeCharsCount);
				auto endIterator = std::next(startIterator , m_MessageSize);
				std::vector<uint8_t> dataFragment(startIterator, endIterator);
				m_ReceivedData.push_back(dataFragment);

				data.erase(data.begin(), endIterator);

				result = true;
			}

			return result;
		}

		bool SizeControlDecorator::getDataFromQueue(std::vector<uint8_t>& data)		{
			bool result = false;
			if (!m_ReceivedData.empty())
			{
				auto receivedData = m_ReceivedData.front();
				m_ReceivedData.pop_front();

				data.clear();
				std::swap(data, receivedData);

				result = !data.empty();
			}

			return result;
		}

		void SizeControlDecorator::resetState()		{
			m_MessageSize = -1;
			m_CurrentBuffer.clear();
			m_ReceivedData.clear();
		}
	}
}