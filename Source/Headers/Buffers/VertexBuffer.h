#pragma once
#include <glad/glad.h>
#include <stdint.h>

class VertexBuffer {
public:
    float* mVertices;
    int mSize;
    unsigned int ID;
    VertexBuffer(float vertices[], uint32_t size) {
        mVertices = vertices;
        mSize = size;
        glGenBuffers(1, &ID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        unbind();
    }

    void setLayout(uint32_t index, uint32_t stride, uint32_t vertexSize, uint32_t offset) {
        bind();
        glVertexAttribPointer(index, stride, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(offset * sizeof(float)));
        glEnableVertexAttribArray(index);
        unbind();
    }

    void bind() {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};

