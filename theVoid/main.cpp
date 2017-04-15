/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include "src\graphic\window.h"
#include "src\math\maths.h"

using namespace std;
using namespace thevoid;
using namespace graphic;
using namespace maths;

int main()
{

	// make window 
	window window(800, 600, "thevoid Engine", false);
	
	// add icon 
	window.w_Icon("..\\Assets\\32.png", "..\\Assets\\64.png");
	
	//change window background color
	glClearColor(0.2f, 0.5f, 0.3f, 1.0f);
	
	GLuint gl_VertextArray;
	glGenVertexArrays(1, &gl_VertextArray);
	glBindVertexArray(gl_VertextArray);

	
	vector4d vec4d(300.0f, 5.0f, 2.0f, 50.0f);
	vec4d.divide(vector4d(5, 10, 50, 400));
	
	std::cout << vec4d << std::endl;
	
	while (!window.w_Closed())
	{
		
		
		window.w_ClearScreen();
		
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.w_Update();
	}

}



