cmake_minimum_required(VERSION 3.23)

project(
  DataStructures
  #DESCRITPRION "C++ Data Stuctures"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# include(CTest)
# add_subdirectory(tests)

# ------------------------------------------------------------------------------
# Options
# ------------------------------------------------------------------------------

option(DSA_BUILD_TESTS "Build unit tests" ON)
option(DSA_BUILD_EXAMPLES "Build examples" ON)

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

if (DSA_BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE # updates file stamps on extraction
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
endif()

# ------------------------------------------------------------------------------
# Compiler warnings
# ------------------------------------------------------------------------------

add_library(project_warnings INTERFACE)

if (MSVC)
    target_compile_options(project_warnings INTERFACE
        /W4
        /permissive-
    )
else()
    target_compile_options(project_warnings INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wsign-conversion
    )
endif()

# ------------------------------------------------------------------------------
# Modules
# ------------------------------------------------------------------------------

add_subdirectory(hello_world)
add_subdirectory(ring_buffer)





