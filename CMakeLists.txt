cmake_minimum_required(VERSION 3.12.0)

#set PROJECT_NAME and version
project(HelloWorld)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

#set path for QT
set(CMAKE_PREFIX_PATH F:/QT/5.10.1/msvc2017_64)

#without console by default
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

file(GLOB SOURCE_FILE *.cpp)
file(GLOB UI_FILE *.ui)
file(GLOB HEAD_FILE *.h)

set(log4cpp_DIR ${PROJECT_SOURCE_DIR}/lib/log4cpp)
find_package(log4cpp REQUIRED)
if(log4cpp_FOUND)
	message("found log4cpp include dir is ${log4cpp_INCLUDE_DIR}")
	include_directories(${log4cpp_INCLUDE_DIR})
endif()

set(project_ui
	${UI_FILE})

set(project_headers
	${HEAD_FILE})

set(project_sources
	${SOURCE_FILE})

add_executable(${PROJECT_NAME} ${project_headers} ${project_ui} ${project_sources})

# Use the widgets module from Qt 5
target_link_libraries(${PROJECT_NAME}
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets)
	
target_link_libraries(${PROJECT_NAME} ${log4cpp_LIBRARY})

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/installed)
set(WINDEPLOYQT_DIR F:/QT/5.10.1/msvc2017_64/bin)
#exec windeployqt automatically when build install in VS
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_DIR}/windeployqt.exe 
				${PROJECT_BINARY_DIR}/Release/${PROJECT_NAME}.exe)")
install(DIRECTORY ${PROJECT_BINARY_DIR}/Release/ DESTINATION /)

set(CPACK_GENERATOR NSIS)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${PROJECT_NAME})

INCLUDE(CPack)