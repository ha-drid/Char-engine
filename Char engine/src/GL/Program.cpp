#include "Program.h"

GL::Program::Program(const std::string& vertex_shader, const std::string& fragment_shader)
{
	mProgram = glCreateProgram();
	mVertexShader = loadShader(vertex_shader, GL_VERTEX_SHADER);
	mFragmentShader = loadShader(fragment_shader, GL_FRAGMENT_SHADER);
}

void GL::Program::link()
{
	glAttachShader(mProgram, mVertexShader);
	glAttachShader(mProgram, mFragmentShader);

	glLinkProgram(mProgram);
}

void GL::Program::bindAttribute(uint32_t index, const std::string& name)
{
	glBindAttribLocation(mProgram, index, name.c_str());
}

void GL::Program::use()
{
	glUseProgram(mProgram);
}



GL::Program::~Program()
{
	glDetachShader(mProgram, mVertexShader);
	glDetachShader(mProgram, mFragmentShader);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
	glDeleteProgram(mProgram);
}
//загрузка шейдера из файла
uint32_t GL::Program::loadShader(const std::string& path, uint32_t shaderType)
{
	uint32_t shader = glCreateShader(shaderType);

	// загрузка кода шейдера
	// выгл€дит страшно, но так проще, отвечаю
	std::ifstream fis(path);
	// он посчитал, что это прототип функции (идиот просто), поэтому конструктор будет таким {}
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };

	// загрузка кода шейдера в OpenGL
	const char* c = shaderCode.c_str();
	// да, тут именно указатель на указатель, char**
	glShaderSource(shader, 1, &c, nullptr);

	// скомпилировать шейдер
	glCompileShader(shader);

	// получить результат компил€ции (1 = успешно; 0 = неуспешно)
	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	int len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);

	// если есть какие-то ошибки или ворнинги
	if (len > 0)
	{
		std::cout << path << ":" << std::endl << buf;
	}

	if (!status) {
		// если не удалось скомпилировать шейдер, выплюнем исключение
		throw std::runtime_error("could not compile shader: " + path);
	}

	return shader;
}

int GL::Program::getUniformLocation(const std::string& name)
{
	return glGetUniformLocation(mProgram, name.c_str());
}

int GL::Program::getAttributLocation(const std::string& name)
{
	return glGetAttribLocation(mProgram, name.c_str());
}

void GL::Program::setUniformFloat1(const std::string& name, float cnt)
{
	glUniform1f(getUniformLocation(name), cnt);
}

void GL::Program::setUniformFLoat3(const std::string& name, float v0, float v1, float v2)
{
	glUniform3f(getUniformLocation(name), v0, v1, v2);
}

void GL::Program::setUniformInt(const std::string& name, int cnt)
{
	glUniform1i(getUniformLocation(name), cnt);
}

void GL::Program::setUniformVec3(const std::string& name, size_t size, const float* array)
{
	glUniform3fv(getUniformLocation(name), size, array);
}
