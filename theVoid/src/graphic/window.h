/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/


#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <string>
#include <png.h>
#include "..\input\mouse.h"

using namespace std;
using namespace thevoid;
using namespace mouse;

namespace thevoid { namespace graphic {
	class window : public mouse
	{
	// public function
	public:
		window(int width, int height, const char *title, bool fullscreen);
		~window();
		void w_Update();
		void w_ClearScreen();
		bool w_init();
		bool w_Closed();
		inline int  w_GetWidth() { return w_Width; }
		inline int w_GetHeigh() { return w_Height; }
		void w_Icon(std::string w_SmallWindowIcon, std::string w_LargeWindowIcon);
		
	// public variable
	public:
		GLFWwindow *w_Window;

	// private function
	private:
		GLFWimage w_LoadIcon(std::string  w_IconPath);
		static void keyCallback(GLFWwindow* w_KCBCwindow, int key, int scancode, int action, int mods);
		static void posCallback(GLFWwindow* w_PCBwindow,  double xPos, double yPos);
	
	// private variable
	private:
		GLFWimage w_WindowIcon[2];
		int w_Width;
		int w_Height;
		const char *w_Title;
		bool w_Fullscreen = false;
		double xPos;
		double yPos;
	
	//protected function	
	protected:

	//protected variable
	protected:

		
	};
}}