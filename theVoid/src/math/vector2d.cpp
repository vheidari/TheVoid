/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include "vector2d.h"

namespace thevoid {namespace maths {

		vector2d::vector2d()
		{
			xAxis = 0.0f;
			yAxis = 0.0f;
		}

		vector2d::vector2d(const float& x, const float& y)
		{
			this->xAxis = x;
			this->yAxis = y;
		}

		vector2d& vector2d::sum(const vector2d& other)
		{
			xAxis += other.xAxis;
			yAxis += other.yAxis;

			return *this;
		}

		vector2d& vector2d::substract(const vector2d& other)
		{
			xAxis -= other.xAxis;
			yAxis -= other.yAxis;
			
			return *this;
		}
		vector2d& vector2d::multiply(const vector2d& other)
		{
			xAxis *= other.xAxis;
			yAxis *= other.yAxis;

			return *this;
		}
		vector2d& vector2d::divide(const vector2d& other)
		{
			xAxis /= other.xAxis;
			yAxis /= other.yAxis;
			
			return *this;
		}

		std::ostream& operator<<(std::ostream& stream, const vector2d vector) {
			stream << "vector2d (" << vector.xAxis << " , " << vector.yAxis << ")";
			return stream;
		}

	
}}