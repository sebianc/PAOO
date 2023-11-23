# CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(ClasaPAOO3 VERSION 1.0)

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()

add_subdirectory(clasa)

add_executable(ClasaPAOO3 main.cpp)

target_link_libraries(ClasaPAOO3 PUBLIC Clasa)

target_include_directories(ClasaPAOO3 PUBLIC "${PROJECT_SOURCE_DIR}/clasa")
