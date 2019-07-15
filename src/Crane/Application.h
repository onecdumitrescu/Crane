#pragma once

#include "Core.h"

#include "Window.h"
#include "Crane/LayerStack.h"
#include "Crane/Events/Event.h"
#include "Crane/Events/ApplicationEvent.h"

#include "Crane/ImGui/ImGuiLayer.h"

#include "Crane/Renderer/Shader.h"
#include "Crane/Renderer/Buffer.h"
#include "Crane/Renderer/VertexArray.h"

#include "Crane/Renderer/OrthographicCamera.h"

namespace Crane {
    
    class CRANE_API Application
    {
    public:
        Application();
        virtual ~Application() = default;

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }
        
        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;

        bool m_Running = true;

        LayerStack m_LayerStack;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;

        // TEST
        std::shared_ptr<Shader> m_BlueShader;
        std::shared_ptr<VertexArray> m_SquareVA;

        OrthographicCamera m_Camera;
    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}
