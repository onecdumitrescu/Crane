#include "cranepch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Crane {

    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    CRANE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            case RendererAPI::API::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
        }

        CRANE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::None:    CRANE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(indices, size);
        }

        CRANE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
