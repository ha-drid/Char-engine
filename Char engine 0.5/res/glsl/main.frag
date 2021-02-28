#version 330

out vec4 mColor;
in vec3 pass_color;

void main()
{
	mColor = vec4(pass_color, 1);
}