#include "Program.h"

GL::Program::Program(const std::string& name)
{
	mProgram = glCreateProgram();
	mVertexShader = loadShader("res\\glsl\\" + name + ".vert", GL_VERTEX_SHADER);
	mFragmentShader = loadShader("res\\glsl\\" + name + ".frag", GL_FRAGMENT_SHADER);
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

void GL::Program::setFloat(const std::string& name, float animation)
{
	glUniform1f(getLocation(name), animation);
}

GL::Program::~Program()
{
	glDetachShader(mProgram, mVertexShader);
	glDetachShader(mProgram, mFragmentShader);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
	glDeleteProgram(mProgram);
}
//�������� ������� �� �����
uint32_t GL::Program::loadShader(const std::string& path, uint32_t shaderType)
{
	uint32_t shader = glCreateShader(shaderType);

	// �������� ���� �������
	// �������� �������, �� ��� �����, �������
	std::ifstream fis(path);
	// �� ��������, ��� ��� �������� ������� (����� ������), ������� ����������� ����� ����� {}
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };

	// �������� ���� ������� � OpenGL
	const char* c = shaderCode.c_str();
	// ��, ��� ������ ��������� �� ���������, char**
	glShaderSource(shader, 1, &c, nullptr);

	// �������������� ������
	glCompileShader(shader);

	// �������� ��������� ���������� (1 = �������; 0 = ���������)
	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	int len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);

	// ���� ���� �����-�� ������ ��� ��������
	if (len > 0)
	{
		std::cout << path << ":" << std::endl << buf;
	}

	if (!status) {
		// ���� �� ������� �������������� ������, �������� ����������
		throw std::runtime_error("could not compile shader: " + path);
	}

	return shader;
}

int GL::Program::getLocation(const std::string& name)
{
	
	return glGetUniformLocation(mProgram, name.c_str());
}
