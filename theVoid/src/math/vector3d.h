/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include <ostream>


namespace thevoid { namespace maths {

	struct vector3d
	{
		float xAxis;
		float yAxis;
		float zAxis;


		vector3d();
		vector3d(const float& x, const float& y, const float& z);

		vector3d& sum(const vector3d& other);
		vector3d& substract(const vector3d& other);
		vector3d& multipaly(const vector3d& other);
		vector3d& divide(const vector3d& other);

		friend std::ostream& operator<<(std::ostream& stream ,  const vector3d vector);
	};



}}

