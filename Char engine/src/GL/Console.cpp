#include "Console.h"
#include "Figure.h"

GL::Console::Console(int width, int height)
{
    mWidth = width;
    mHeight = height;
    /*
    vao.addVertexBufferObject({
        {  0.0f, -1.0f,  0.0f },
        {  0.0f,  0.0f,  0.0f },
        {  1.0f,  0.0f,  0.0f },
        {  1.0f, -1.0f,  0.0f }
        });

    float width_sym = 1.0f / 16.0f;
    char c = '@';
    uint32_t y = c >> 4;
    uint32_t x = c & 0b1111;

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
    */

    GL::CharacterSymbol('A', symbolVAO);
    GL::CharacterSymbol('B', symbolVAO1);

    shader.bindAttribute(0, "position");
    shader.bindAttribute(1, "uv");

    shader.link();

    shader.use();
}

void GL::Console::swap()
{
    glLoadIdentity();
    glScalef(2.0f / mWidth, 2.0f / mHeight, 1.0f);
    glTranslatef(-mWidth * 0.5f, mHeight * 0.5f, 0.0f);

    shader.setUniformInt("mTexture", 0);
    glActiveTexture(GL_TEXTURE0);
    mLuicidaConsoleFont.bind();

    shader.use();
    symbolVAO.draw(GL_TRIANGLES);
    glTranslatef(1.0f, 0.0f, 0.0f);
    symbolVAO1.draw();
}

GL::Console::~Console()
{

}