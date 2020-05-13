cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
#[=======================================================================[
 We dont support the NuGet version of Allegro. We DO support vcpkg:

 VCPKG_ROOT needs to be an Environment Var that refers to the directory
 where the vcpkg.exe progra was installed, along with its file structure.
 #]=======================================================================]
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
		message("vcpkg support ENABLED")
		set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake"
			CACHE STRING "")
endif()

project(GardenShower VERSION 0.1.0 LANGUAGES CXX C)

if(MSVC AND NOT VCPKG_TOOLCHAIN)
	message(FATAL_ERROR "Visual Studio support requires the use of vcpkg. See README.md")
endif() 

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(Allegro5 REQUIRED COMPONENTS acodec audio color font image primitives ttf)

# Game source files
set(SOURCES
	"src/main.cpp"
	"src/scene.cpp"
	"src/input.cpp"
	"src/scene-types.cpp"
	"src/BaseScene.cpp"
	"src/TitleScreen.cpp"
	"src/GardenA.cpp"
	"src/PauseScreen.cpp"
	"src/player.cpp"
	"src/rect.cpp")

add_executable(game ${SOURCES})

target_link_libraries(game PRIVATE Allegro5::Allegro5
	Allegro5::acodec
	Allegro5::audio
	Allegro5::color
	Allegro5::font
	Allegro5::image
	Allegro5::primitives
	Allegro5::ttf)