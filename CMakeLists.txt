cmake_minimum_required(VERSION 3.12.0)

#set PROJECT_NAME and version
project(HelloWorld)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

#set path for QT
set(CMAKE_PREFIX_PATH F:/QT/5.10.1/msvc2017_64)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

set(project_ui
	MainWindow.ui)

set(project_headers
	MainWindow.h)

set(project_sources
	demoMain.cpp MainWindow.cpp)

add_executable(${PROJECT_NAME} ${project_headers} ${project_ui} ${project_sources})

# Use the widgets module from Qt 5
target_link_libraries(${PROJECT_NAME}
	PUBLIC
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets)

