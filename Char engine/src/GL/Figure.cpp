#include "Figure.h"

void GL::CharacterSymbol(char symbol, GL::VAO& vao)
{
    vao.addVertexBufferObject({
        {  0.0f, -1.0f,  0.0f },
        {  0.0f,  0.0f,  0.0f },
        {  1.0f,  0.0f,  0.0f },
        {  1.0f, -1.0f,  0.0f }
        });

    static float width_sym = 1.0f / 16.0f;

    uint32_t y = symbol >> 4;
    uint32_t x = symbol & 0b1111;

    struct { float top, left, right, bottom; } rct;
    rct.top = (float)y * width_sym;
    rct.bottom = rct.top + width_sym;
    rct.left = (float)x * width_sym;
    rct.right = rct.left + width_sym;

    vao.addVertexBufferObject({
        { rct.left, rct.bottom },
        { rct.left, rct.top    },
        { rct.right, rct.top   },
        { rct.right, rct.bottom},
        });

    vao.addIndices({
        0, 1, 2,
        0, 2, 3
        });
}