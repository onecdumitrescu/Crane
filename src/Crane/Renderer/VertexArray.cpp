#include "cranepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Crane {

    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    CRANE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            case RendererAPI::API::OpenGL:  return new OpenGLVertexArray();
        }

        CRANE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
