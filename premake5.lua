project "Crane"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "cranepch.cpp"
    pchsource "src/cranepch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp",
        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include",
        "vendor/glfw/include",
        "vendor/glad/include",
        "vendor/imgui",
        "vendor/glm"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "CRANE_PLATFORM_WINDOWS",
            "CRANE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        links
        {
            "GLFW",
            "Glad",
            "ImGui",
            "opengl32.lib"
        }

    filter "system:linux"
        systemversion "latest"

        defines
        {
            "CRANE_PLATFORM_LINUX",
            "GLFW_INCLUDE_NONE"
        }

        links
        {
            "GLFW",
            "Glad",
            "ImGui",
            "GL",
            "X11"
        }

    filter "configurations:Debug"
        defines "CRANE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "CRANE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "CRANE_DIST"
        runtime "Release"
        optimize "on"
