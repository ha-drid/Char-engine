#pragma once
#include <vector>
#include <iostream>
#include "gl.h"

namespace GL
{
	class VAO
	{
	public:
		VAO();
		VAO(const VAO&) = delete;
		void bind();
		void draw(unsigned type = GL_TRIANGLES);
		void addVertexBufferObject(const std::vector<float> data);
		void addVertexBufferObject(const std::vector<glm::vec2> data);
		void addVertexBufferObject(const std::vector<glm::vec3> data);
		void addVertexBufferObject(const std::vector<glm::vec4> data);

		void remixVertexBufferObject2(const std::vector<float> data);

		void addIndices(const std::vector<unsigned> data);
		~VAO();
	private:
		std::vector<uint32_t> mBuffers;
		uint32_t mVao;
		size_t mIndicesCount = 0;
		unsigned mIndicesBuffer = 0;
	};
}