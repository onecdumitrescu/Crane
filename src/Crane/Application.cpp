#include "cranepch.h"
#include "Application.h"

#include "Crane/Log.h"

namespace Crane {

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;
    }

    void Application::Run()
    {
        while(true);
    }
}
