#version 330

in vec3 position;
in vec2 uv;

out vec2 pass_uv;

uniform float width;
uniform float height;

void main()
{
	vec4 pos = (vec4(position, 1) * vec4(2.0 / width, 2.0 / height, 1, 1));
	//pos.x += 10;
	
	gl_Position = pos;
	
	pass_uv = uv;
}