cmake_minimum_required(VERSION 3.28)
project(CurseForge_CPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.hpp")
add_executable(CurseForge_CPP src/main.cpp)
add_library(curseforge SHARED ${SOURCES} ${HEADERS})
add_library(curseforge_static STATIC ${SOURCES} ${HEADERS})

target_include_directories(curseforge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(curseforge_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(curseforge PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
target_link_libraries(curseforge_static PRIVATE cpr::cpr nlohmann_json::nlohmann_json)

target_link_libraries(CurseForge_CPP PRIVATE curseforge)
