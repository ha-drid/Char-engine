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

		void setUniformFloat1(const std::string& name, float cnt);
		void setUniformFLoat3(const std::string& name, float v0, float v1, float v2);

		void setUniformInt(const std::string& name, int cnt);
		void setUniformVec3(const std::string& name, size_t size, const float* array);
		

		~Program();
	private:
		uint32_t loadShader(const std::string& name, uint32_t ShaderType);
		int getUniformLocation(const std::string& name);
		int getAttributLocation(const std::string& name);
		uint32_t mProgram;
		uint32_t mVertexShader;
		uint32_t mFragmentShader;
	};
}
