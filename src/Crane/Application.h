#pragma once

#include "Core.h"

namespace Crane {
    
    class CRANE_API Application
    {
    public:
        Application();
        virtual ~Application() = default;

        void Run();
        
        inline static Application& Get() { return *s_Instance; }
    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}
