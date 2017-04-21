/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include "mouse.h"
#include <iostream>


namespace thevoid {  namespace mouse {


	mouse::mouse()
	{

	}

	mouse::~mouse()
	{

	}

	void mouse::m_XYPosCallBack(GLFWwindow * w_Window, double m_XPos,  double m_YPos)
	{
		std::cout << m_XPos << " * " << m_YPos << std::endl ;
	}
	
}}