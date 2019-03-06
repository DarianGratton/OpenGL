#include "Renderer.hpp"

#include <iostream>

// Function to clear all the errors 
void GLClearError()
{
	// GL_NO_ERROR == 0
	while (glGetError() != GL_NO_ERROR);
}


// Function to check all the errors
// POST: Prints the error number that is occuring.
// PARAM function: name of the function we try to call
// PARAM file: C++ file where the function was called from
// PARAM line: line of the code
bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")" << function << " "
			<< file << ":" << line << std::endl;
		return false;
	}
	return true;
}