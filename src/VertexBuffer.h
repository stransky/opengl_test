#pragma once

class VertexBuffer
{
private:
    unsigned int m_RendererID;
public:
    VertexBuffer(const void *data, unsigned int size);

    VertexBuffer(unsigned int mRendererId);

    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};
