#version 330

out vec4 mColor;
in vec2 pass_uv;

uniform sampler2D mTexture;

void main()
{
	mColor = texture(mTexture, pass_uv);
}