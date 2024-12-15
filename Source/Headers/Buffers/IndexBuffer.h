#pragma once
#include <glad/glad.h>
#include <stdint.h>


class IndexBuffer {
public:
    unsigned int* mIndices;
    int mSize;
    unsigned int ID;
    IndexBuffer(unsigned int indices[], uint32_t size) {
        mIndices = indices;
        mSize = size;
        glGenBuffers(1, &ID);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        unbind();
    }
    void bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    }
    void unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

};

