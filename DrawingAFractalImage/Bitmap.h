#pragma once
#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

namespace ses
{
	class Bitmap
	{
	private:
		int m_width {0};
		int m_height {0};
		std::unique_ptr<std::uint8_t[]> m_pPixels { nullptr };

	public:
		Bitmap (int width, int height);
		virtual ~Bitmap ();

		bool write (std::string fileName);
		void setPixel (int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
	};
}

#endif /* BITMAP_H_ */
