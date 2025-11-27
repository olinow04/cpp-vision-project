cmake_minimum_required(VERSION 3.20)
project(CppVisionProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR /opt/homebrew/opt/opencv/share/opencv4)
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include path: ${OpenCV_INCLUDE_DIRS}")

file(GLOB_RECURSE CVCORE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/core/*.cpp
)

add_library(cvcore STATIC
    ${CVCORE_SOURCES}
    ${CMAKE_SOURCE_DIR}/src/app.cpp
)

target_include_directories(cvcore
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PUBLIC ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(cvcore
    PUBLIC ${OpenCV_LIBS}
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cvcore)


