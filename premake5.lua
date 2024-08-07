workspace "DDE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DDE"
	location "DDE"
	kind "SharedLib"
	language"C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines
		{
			"DDE_PLATFORM_WINDOWS",
			"DDE_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "DDE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "DDE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "DDE_DIST"
		symbols "On"
	
	


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language"C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DDE/vendor/spdlog/include",
		"DDE/src"
	}
	links
	{
		"DDE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines
		{
			"DDE_PLATFORM_WINDOWS"
		}
	filter "configurations:Debug"
		defines "DDE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "DDE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "DDE_DIST"
		symbols "On"