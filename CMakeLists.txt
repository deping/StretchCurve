# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("OsgEditor")

# set(OSG_DIR "C:/Program Files/OpenSceneGraph")
# set(QTDIR "C:/Qt/5.11.1/msvc2017_64")
if(NOT OSG_DIR)
	set(OSG_DIR $ENV{OSG_DIR})
	string(REPLACE "\\" "/" OSG_DIR "${OSG_DIR}")
endif()

if(NOT QTDIR)
	set(QTDIR $ENV{QTDIR})
	string(REPLACE "\\" "/" QTDIR "${QTDIR}")
endif()


set(CMAKE_MODULE_PATH "${QTDIR}/lib/cmake;${OSG_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
# find_package(Qt5 REQUIRED COMPONENTS Core Gui OpenGL)
find_package(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer)
include_directories(${OPENSCENEGRAPH_INCLUDE_DIRS})

# Include sub-projects.
add_subdirectory ("OsgEditor")
