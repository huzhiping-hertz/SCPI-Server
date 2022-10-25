cmake_minimum_required (VERSION 3.10)
project ("SCPI" C CXX)

set(CMake_CXX_STANDARD 20)
set(CMake_CXX_STANDARD_REQUARED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(VCPKG_FEATURE_FLAGS "versions")
include(c:/work/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(czmq CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(Poco CONFIG REQUIRED Net Util JSON Redis Data)
find_package(RTTR CONFIG REQUIRED Core)

#版本信息
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VERSION "x64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(VERSION "x86")
endif()

#库文件输出路径、执行文件输出路径
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${VERSION})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${VERSION})

#项目头文件
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
#项目源码
add_subdirectory(src/ZmqMessager)
#add_subdirectory(src/DomainModel)
#add_subdirectory(src/CommonUtility)
add_subdirectory(src/ScpiServer)
add_subdirectory(src/UnitTest)