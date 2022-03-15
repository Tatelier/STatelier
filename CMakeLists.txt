project(STatelier)

cmake_minimum_required(VERSION 3.23)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS /MP)
set(CMAKE_CXX_FLAGS_DEBUG /ZI)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# STatelier

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/STatelier/src/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/STatelier/include/*.h)

add_executable(STatelier WIN32 ${SOURCES} ${HEADERS})

target_link_directories(STatelier PRIVATE $ENV{HOMEDRIVE}$ENV{HOME}/DxLib/)

target_include_directories(STatelier PRIVATE ${CMAKE_SOURCE_DIR}/STatelier/include)
target_include_directories(STatelier PUBLIC $ENV{HOMEDRIVE}$ENV{HOME}/DxLib/)
target_include_directories(STatelier PRIVATE ${CMAKE_SOURCE_DIR}/statelier-score/include)


target_compile_definitions(STatelier PRIVATE $<$<CONFIG:Debug>:STATELIER_DEBUG>)

# statelier-score

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/statelier-score/src/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/statelier-score/include/*.h)

add_library(statelier-score SHARED ${SOURCES} ${HEADERS})
target_include_directories(statelier-score PRIVATE ${CMAKE_SOURCE_DIR}/statelier-score/include)

# 紐付け

target_link_libraries(STatelier statelier-score)

target_compile_definitions(statelier-score PRIVATE EXPORTS)
add_dependencies(STatelier statelier-score)