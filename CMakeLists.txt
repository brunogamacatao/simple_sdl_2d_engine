cmake_minimum_required(VERSION 3.2)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
    SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
)

project(hello01)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

hunter_add_package(ZLIB)
find_package(ZLIB CONFIG REQUIRED)

hunter_add_package(tinyxml2)
find_package(tinyxml2 CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

file(GLOB_RECURSE TARGET_H "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE TARGET_CPP "${CMAKE_SOURCE_DIR}/src/*.cpp")
set(TARGET_SRC ${TARGET_CPP} ${TARGET_H})

add_executable(hello01 ${TARGET_SRC})  

target_link_libraries(hello01 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} fmt::fmt ZLIB::zlib tinyxml2::tinyxml2)

file(COPY "${CMAKE_SOURCE_DIR}/images" DESTINATION "${CMAKE_SOURCE_DIR}/build/")
file(COPY "${CMAKE_SOURCE_DIR}/maps" DESTINATION "${CMAKE_SOURCE_DIR}/build/")