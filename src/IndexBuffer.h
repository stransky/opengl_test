#pragma once

class IndexBuffer
{
private:
    unsigned int m_RendererID;
    unsigned int count;
public:
    IndexBuffer(const void *data, unsigned int size);

    IndexBuffer(unsigned int mRendererId);

    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return count; }
};
