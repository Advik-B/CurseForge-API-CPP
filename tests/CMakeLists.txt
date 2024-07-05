cmake_minimum_required(VERSION 3.28)
project(CurseForge_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
#option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(CurseForge_test "main.cpp")
target_link_libraries(CurseForge_test PRIVATE curseforge::static)
