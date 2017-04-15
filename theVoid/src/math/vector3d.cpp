/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include "vector3d.h"

namespace thevoid { namespace maths {


	vector3d::vector3d() 
	{
		xAxis = 0.0f;
		yAxis = 0.0f;
		zAxis = 0.0f;
	}

	vector3d::vector3d(const float& x,  const float& y, const float& z)
	{
		this->xAxis = x;
		this->yAxis = y;
		this->zAxis = z;
	}

	vector3d& vector3d::sum(const vector3d& other)
	{
		xAxis += other.xAxis;
		yAxis += other.yAxis;
		zAxis += other.zAxis;

		return *this;
	}

	vector3d& vector3d::substract(const vector3d& other)
	{
		xAxis -= other.xAxis;
		yAxis -= other.yAxis;
		zAxis -= other.zAxis;

		return *this;
	}

	vector3d& vector3d::multipaly(const vector3d& other)
	{
		xAxis *= other.xAxis;
		yAxis *= other.yAxis;
		zAxis *= other.zAxis;

		return *this;
	}

	vector3d& vector3d::divide(const vector3d& other)
	{
		xAxis /= other.xAxis;
		yAxis /= other.yAxis;
		zAxis /= other.zAxis;

		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vector3d vector)
	{
		stream << "vectore3d ( " << vector.xAxis << " , " << vector.yAxis << " , " << vector.zAxis << " )";
		return stream;
	}
}}