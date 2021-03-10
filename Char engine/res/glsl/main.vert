#version 110 core

in vec3 position;
in vec2 uv;



out vec2 pass_uv;

void main()
{
	gl_Position = gl_ModelViewProjectionMatrix * vec4(position, 1);
	
	pass_uv = uv;
}