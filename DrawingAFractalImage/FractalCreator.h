#pragma once
#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <memory>
#include <utility>
#include <string>
#include <vector>
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "RGB.h"

namespace ses
{
	class FractalCreator
	{
	private:
		int m_width;
		int m_height;
		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total { 0 };

		std::vector<double> m_ranges;
		std::vector<RGB> m_colors;
		std::vector<int> m_rangeTotals;

		bool m_bGotFirstRange { false };

	private:
		void calculateIterations ();
		void calculateTotalIterations ();
		void calculateRangeTotals ();
		void drawFractal ();
		void writeBitmap (std::string);
		int getRange (int iterations) const;

	public:
		FractalCreator (int width, int height);
		virtual ~FractalCreator ();

		void addZoom (const Zoom &zoom);
		void addRange (double rangeEnd, const RGB &rgb);
		void run (std::string name);
	};
}

#endif /* FRACTALCREATOR_H_ */
