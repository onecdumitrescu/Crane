#import "cranepch.h"
#import "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Crane {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        CRANE_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        CRANE_CORE_ASSERT(status, "Failed to initialize Glad!");

        CRANE_CORE_INFO("OpenGL Info:");
        CRANE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        CRANE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        CRANE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}
