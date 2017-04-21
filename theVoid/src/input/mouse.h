/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/

#include "GLFW\glfw3.h";

namespace thevoid { namespace mouse {
	
	class mouse
	{
	
	// public function 
	public:
		mouse();
		~mouse();

		static void m_XYPosCallBack(GLFWwindow * w_Window, double m_XPos, double m_YPos);
		
	// public variable
	public:
		double m_XPos;
		double m_YPos;
	
	// private function 
	private:
	
	// private variable 
	private:


	
	// protected fucntion
	protected:
	
	// protected funtion
	protected:
	
	};

}}