/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include "vector4d.h"

namespace thevoid { namespace maths {

	vector4d::vector4d()
	{
		xAixs = 0.0f;
		yAixs = 0.0f;
		zAixs = 0.0f;
		wAixs = 0.0f;
	}


	vector4d::vector4d(const float& x, const float& y, const float& z, const float& w)
	{
		this->xAixs = x;
		this->yAixs = y;
		this->zAixs = z;
		this->wAixs = w;
	}

	vector4d& vector4d::sum(const vector4d& other)
	{
		xAixs += other.xAixs;
		yAixs += other.yAixs;
		zAixs += other.zAixs;
		wAixs += other.wAixs;

		return *this;
	}

	vector4d& vector4d::substract(const vector4d& other)
	{
		xAixs -= other.xAixs;
		yAixs -= other.yAixs;
		zAixs -= other.zAixs;
		wAixs -= other.wAixs;

		return *this;
	}

	vector4d& vector4d::multipaly(const vector4d& other)
	{
		xAixs *= other.xAixs;
		yAixs *= other.yAixs;
		zAixs *= other.zAixs;
		wAixs *= other.wAixs;

		return *this;
	}

	vector4d& vector4d::divide(const vector4d& other)
	{
		xAixs /= other.xAixs;
		yAixs /= other.yAixs;
		zAixs /= other.zAixs;
		wAixs /= other.wAixs;

		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vector4d vector)
	{
		stream << "vector4d ( " << vector.xAixs << " , " << vector.yAixs << " , " << vector.zAixs << " , " << vector.wAixs << " )";
		return stream;
	}

}}