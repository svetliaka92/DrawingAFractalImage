#pragma once
#ifndef BITMAPFILEHEADER_H_
#define BITMATFILEHEADER_H_

#include <cstdint>

#pragma pack(2)
namespace ses
{
	struct BitmapFileHeader
	{
		char header[2] { 'B', 'M' };
		std::int32_t fileSize;
		std::int32_t reserved { 0 };
		std::int32_t dataOffset;
	};
}

#endif /* BITMAPFILEHEADER_H_ */
