#include "Lanter/Utils/Converter.h"

namespace Lanter
{
    namespace Utils
    {
		static const unsigned char base64_enc_map[64] =
		{
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
			'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
			'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
			'8', '9', '+', '/'
		};

		static const unsigned char base64_dec_map[128] =
		{
			127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
			127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
			127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
			127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
			127, 127, 127, 62, 127, 127, 127, 63, 52, 53,
			54, 55, 56, 57, 58, 59, 60, 61, 127, 127,
			127, 64, 127, 127, 127, 0, 1, 2, 3, 4,
			5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
			25, 127, 127, 127, 127, 127, 127, 26, 27, 28,
			29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
			39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
			49, 50, 51, 127, 127, 127, 127, 127
		};



		// Parameters:
		//    dlen  On input, the size in bytes of the output buffer, on output, the size of the resulting data
		// Return: Bool value ,dst will be zero ending
		int Base64_EncodeData(unsigned char* dst, int* dlen, const unsigned char* src, int  slen)
		{
			int i, n;
			int C1, C2, C3;
			unsigned char* p;

			if (slen == 0)
			{
				return (0);
			}

			n = (slen << 3) / 6;

			switch ((slen << 3) - (n * 6))
			{
			case  2:
				n += 3;
				break;

			case  4:
				n += 2;
				break;

			default:
				break;
			}

			if (*dlen < n + 1)
			{
				*dlen = n + 1;
				return (0); // POLARSSL_ERR_BASE64_BUFFER_TOO_SMALL );
			}

			n = (slen / 3) * 3;

			for (i = 0, p = dst; i < n; i += 3)
			{
				C1 = *src++;
				C2 = *src++;
				C3 = *src++;
				*p++ = base64_enc_map[(C1 >> 2) & 0x3F];
				*p++ = base64_enc_map[(((C1 & 3) << 4) + (C2 >> 4)) & 0x3F];
				*p++ = base64_enc_map[(((C2 & 15) << 2) + (C3 >> 6)) & 0x3F];
				*p++ = base64_enc_map[C3 & 0x3F];
			}

			if (i < slen)
			{
				C1 = *src++;
				C2 = ((i + 1) < slen) ? *src++ : 0;
				*p++ = base64_enc_map[(C1 >> 2) & 0x3F];
				*p++ = base64_enc_map[(((C1 & 3) << 4) + (C2 >> 4)) & 0x3F];

				if ((i + 1) < slen)
				{
					*p++ = base64_enc_map[((C2 & 15) << 2) & 0x3F];
				}
				else
				{
					*p++ = '=';
				}

				*p++ = '=';
			}

			*dlen = p - dst;
			*p = 0;

			return (1);
		}

		// Decode a base64-formatted buffer
		int Base64_DecodeData(unsigned char* dst, int* dlen, const char* src, int  slen)
		{
			int i, j, n;
			unsigned long x;
			unsigned char* p;

			for (i = j = n = 0; i < slen; i++)
			{
				if ((slen - i) >= 2 &&
					src[i] == '\r' && src[i + 1] == '\n')
				{
					continue;
				}

				if (src[i] == '\n')
				{
					continue;
				}

				if (src[i] == '=' && ++j > 2)
				{
					return (0);    //POLARSSL_ERR_BASE64_INVALID_CHARACTER );
				}

				if (src[i] > 127 || base64_dec_map[static_cast<int>(src[i])] == 127)
				{
					return (0);    // POLARSSL_ERR_BASE64_INVALID_CHARACTER );
				}

				if (base64_dec_map[static_cast<int>(src[i])] < 64 && j != 0)
				{
					return (0);    // POLARSSL_ERR_BASE64_INVALID_CHARACTER );
				}

				n++;
			}

			if (n == 0)
			{
				return (0);
			}

			n = ((n * 6) + 7) >> 3;

			if (*dlen < n)
			{
				*dlen = n;
				return (0); // POLARSSL_ERR_BASE64_BUFFER_TOO_SMALL );
			}

			for (j = 3, n = x = 0, p = dst; i > 0; i--, src++)
			{
				if (*src == '\r' || *src == '\n')
				{
					continue;
				}

				j -= (base64_dec_map[static_cast<int>(*src)] == 64);
				x = (x << 6) | (base64_dec_map[static_cast<int>(*src)] & 0x3F);

				if (++n == 4)
				{
					n = 0;

					if (j > 0)
					{
						*p++ = (unsigned char)(x >> 16);
					}

					if (j > 1)
					{
						*p++ = (unsigned char)(x >> 8);
					}

					if (j > 2)
					{
						*p++ = (unsigned char)(x);
					}
				}
			}

			*dlen = p - dst;
			return (1);
		}

		std::string Conveter::bytesToBase64(const std::vector<int8_t>& value)
        {
			if (value.size() > 0)
			{
				std::vector<uint8_t> out(value.size() * 3, 0);
				int out_sz = out.size();

				std::vector<uint8_t> in_v(out.size(), 0);
				in_v.assign(value.begin(), value.end());

				if (Base64_EncodeData(&out[0], &out_sz, &in_v[0], in_v.size()) == 1)
				{
					out.resize(out_sz);

					std::string str;
					str.resize(out.size());
					std::copy(out.begin(), out.end(), str.begin());

					return str;
				}
			}

			return std::string();
        }

        std::vector<int8_t> Conveter::bytesFromBase64(const std::string& value)
        {
			if (!value.empty())
			{
				std::vector<int8_t> out(value.size() * 3, 0);
				int out_sz = out.size();

				std::vector<char> in_v(out.size(), 0);
				in_v.assign(value.begin(), value.end());

				if (Base64_DecodeData((uint8_t*) &out[0], &out_sz, &in_v[0], in_v.size()) == 1)
				{
					out.resize(out_sz);
					return out;
				}
			}
			
			return std::vector<int8_t>();
        }
    }
}