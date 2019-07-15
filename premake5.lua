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
        "src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include"
    }

    filter "system:windows"
        systemversion "latest"

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
