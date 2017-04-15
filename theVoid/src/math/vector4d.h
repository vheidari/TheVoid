/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include <ostream>

namespace thevoid { namespace maths {

	struct vector4d {

		float xAixs;
		float yAixs;
		float zAixs;
		float wAixs;

		vector4d();
		vector4d( const float& x, const float& y, const float& z, const float& w);

		vector4d& sum(const vector4d& other);
		vector4d& substract( const vector4d& other);
		vector4d& multipaly(const vector4d& other);
		vector4d& divide(const vector4d& other);

		friend std::ostream& operator<<(std::ostream& stream, const vector4d vector);
	};



}}