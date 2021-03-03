#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <gl.h>

namespace GL
{
	class Program
	{
	public:
		Program(const std::string& vertex_shader, const std::string& fragment_shader);
		void link();
		void bindAttribute(uint32_t index, const std::string& name);
		void use();
		void setFloat(const std::string& name, float cnt);
		void setInt(const std::string& name, int cnt);
		
		~Program();
	private:
		uint32_t loadShader(const std::string& name, uint32_t ShaderType);
		int getLocation(const std::string& name);
		uint32_t mProgram;
		uint32_t mVertexShader;
		uint32_t mFragmentShader;
	};
}
