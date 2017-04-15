/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include <ostream>

namespace thevoid { namespace maths {

	struct vector2d
	{
		float xAxis;
		float yAxis;

		vector2d();
		vector2d(const float& x, const float& y);

		vector2d& sum(const vector2d& other);
		vector2d& substract( const vector2d& other);
		vector2d& multiply(const vector2d& other);
		vector2d& divide( const vector2d& other);


		friend std::ostream& operator<<(std::ostream& stream, const vector2d vector);
	};



}}