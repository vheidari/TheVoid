/*
the void open source game engine - start dev in 2017 write in c++ on opengl.
Author : vahid heidari
Email  : vahid-heidari@hotmail.com
Licence : MIT
*/

#include "window.h";


namespace thevoid { namespace graphic {

	void w_resize(GLFWwindow* window, int w_ChangeWidth, int w_ChangeHeigh);
	
	
	// window class constractor
	window::window(int width, int height, const char *title , bool fullscreen)
	{
		w_Width = width;
		w_Height = height;
		w_Title = title;
		w_Fullscreen = fullscreen;
		w_init();
	}
	
	// window class destractor
	window::~window()
	{
		glfwTerminate();
	}

	// initialze glfw and glew 
	bool window::w_init()
	{
		if (!glfwInit())
		{
			std::cout << "thevoid can't initialize GLFW ";
		}


		if (w_Fullscreen) {
			w_Window = glfwCreateWindow(w_Width, w_Height, w_Title, glfwGetPrimaryMonitor(), NULL);
		}
		else
		{
			w_Window = glfwCreateWindow(w_Width, w_Height, w_Title, NULL, NULL);
		}
		
		if (!w_Window)
		{
			std::cout << "thevoid have problem to make window" << std::endl;
			glfwTerminate();
			return false;
		}
		
		
			glfwMakeContextCurrent(w_Window);
			glfwSetKeyCallback(w_Window, keyCallback);
			glfwSetWindowSizeCallback(w_Window, w_resize);
			

			if (glewInit() != GLEW_OK)
			{
				std::cout << "thevoid can't initialze GLEW";
				return false;
			}
			
	}

	// chack window is close
	bool window::w_Closed()
	{
		return glfwWindowShouldClose(w_Window) == 1;
	}

	// clear window screen
	void window::w_ClearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	// window update 
	void window::w_Update()
	{

		glfwSwapBuffers(w_Window);	
		glfwPollEvents();
	}

	//set window icon
	void window::w_Icon(std::string w_SmallWindowIcon, std::string w_LargeWindowIcon)
	{
		//todo add icon
		if (w_SmallWindowIcon != "" && w_LargeWindowIcon != "") {
			w_WindowIcon[0] = w_LoadIcon(w_SmallWindowIcon);
			w_WindowIcon[1] = w_LoadIcon(w_LargeWindowIcon);
			
			if (w_WindowIcon)
			{
				glfwSetWindowIcon(w_Window, 2, w_WindowIcon);
			}
			
		}

	}


	// load icon and check icon is png
	GLFWimage window::w_LoadIcon(std::string  w_IconPath)
	{

		//read header file 
		png_byte pngHeaderFile[8];

		// open file 
		FILE *fp = fopen(w_IconPath.c_str(), "rb");
		
		//check file is open
		if (!fp)
		{
			std::cout << "thevoid have problem to open icon file!" << std::endl;
		}

		// read 8 bit of header file 
		fread(pngHeaderFile, 1, 8, fp);

		// has a png file 
		int isPng = !png_sig_cmp(pngHeaderFile, 0, 8);
		
		if (!isPng) 
		{
			std::cout << "format file incorect !" << std::endl;
			fclose(fp);
			
		}

		//makeing png structure
		png_structp png_Ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		
		if(!png_Ptr)
		{
			fclose(fp);
			std::cout << "can't make png structure" << std::endl;
		}


		//making png info
		png_infop png_StartInfo = png_create_info_struct(png_Ptr);

		if (!png_StartInfo)
		{
			png_destroy_read_struct(&png_Ptr, (png_infopp) NULL, (png_infopp) NULL );
			fclose(fp);
			std::cout << "can't makeing png startInfo !" << std::endl;
		}
		
		png_infop png_EndInfo = png_create_info_struct(png_Ptr);

		if (!png_EndInfo)
		{
			png_destroy_read_struct(&png_Ptr, (png_infopp) NULL, (png_infopp) NULL);
			fclose(fp);
			std::cout << "cat't makign png endInfo!" << std::endl;
		}


		// check png file is damage 
		if (setjmp(png_jmpbuf(png_Ptr)))
		{
			png_destroy_read_struct(&png_Ptr, (png_infopp) NULL, (png_infopp) NULL);
			fclose(fp);
			std::cout << "can't png init" << std::endl;
		}


		// init png file 
		png_init_io(png_Ptr, fp);

		// if read 8 bit complate 
		png_set_sig_bytes(png_Ptr, 8);

		// read all info 
		png_read_info(png_Ptr, png_StartInfo);

		// makeing var for png file
		int png_BitDepth, png_ColorType;
		png_uint_32 png_Width, png_Heigh;

		//get png info 
		png_get_IHDR(png_Ptr, png_StartInfo, &png_Width, &png_Heigh, &png_BitDepth, &png_ColorType, NULL, NULL, NULL);

		png_Width;
		png_Heigh;
		
		// update png info
		png_read_update_info(png_Ptr, png_StartInfo);

		// get row byte size
		int png_RowBytes = png_get_rowbytes(png_Ptr,  png_StartInfo);

		png_byte *png_ImageData = new png_byte[ png_RowBytes * png_Heigh];
		
		if (!png_ImageData)
		{
			png_destroy_read_struct(&png_Ptr, &png_StartInfo, &png_EndInfo );
			fclose(fp);
			std::cout << "can't init Imgae Data !" << std::endl;
		}

		png_bytep  *png_RowPointers = new png_bytep[png_Heigh];

		if (!png_RowPointers)
		{
			png_destroy_read_struct(&png_Ptr, &png_StartInfo, &png_EndInfo);
			delete[] png_ImageData;
			fclose(fp);
			std::cout << "cat init Row pointer !";
		}

		for (unsigned int i = 0; i < png_Heigh; i++)
		{
			png_RowPointers[png_Heigh - 1 - i] = png_ImageData + i * png_RowBytes;
		}

		png_read_image(png_Ptr, png_RowPointers);

		GLFWimage png_ReturnImgae;
		png_ReturnImgae.height = png_Heigh;
		png_ReturnImgae.width = png_Width;
		png_ReturnImgae.pixels = png_ImageData;

		return png_ReturnImgae;
	}

	// change window size
	void w_resize(GLFWwindow *w_window,  int w_ChangeWidth, int w_ChangeHeigh)
	{
		glViewport(0, 0, w_ChangeWidth, w_ChangeHeigh);
	}

	void  window::keyCallback(GLFWwindow* w_KCBCwindow, int key, int scancode, int action, int mods)
	{

		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			std::cout << "w";
		}

	}
	


}//end of graphic name space 
}// end of thevoid name space 