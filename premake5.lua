workspace "lua"
	configurations { "debug", "release" }

project "lua"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	files { "src/**.hpp", "src/**.cpp" }

	filter { "configurations:debug" }
		symbols "On"
		defines { "DEBUG=1" }

	filter { "configurations:release" }
		optimize "On"
		defines { "DEBUG=0" }
