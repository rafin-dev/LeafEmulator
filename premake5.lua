workspace "Prototype-Emulator"

    architecture "x64"
    configurations { "Debug", "Release"}


project "Emulator"

    location "Emulator"
    kind "ConsoleApp"
    language "c++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    includedirs {"vendor/SFML/include"}

    files
    {
        "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.h"
    }

    defaultplatform ("x64")

    cppdialect "C++17"

    defines {"SFML_STATIC"}
    libdirs {"vendor/SFML/lib"}

    links
    {
        "opengl32",
        "freetype",
        "winmm",
        "gdi32",
        "flac",
        "vorbisenc",
        "vorbisfile",
        "vorbis",
        "ogg",
        "ws2_32"
    }

    

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

        links
		{	
			"sfml-graphics-s-d",
			"sfml-window-s-d",
			"sfml-system-s-d",
			"sfml-audio-s-d",
			"sfml-network-s-d"
		}

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

        links
		{	
			"sfml-graphics-s",
			"sfml-window-s",
			"sfml-system-s",
			"sfml-audio-s",
			"sfml-network-s"
		}

    filter { "platforms:x64" }
        architecture "x86_64"
		
	filter { "platforms:Arm64" }
        architecture "ARM64"