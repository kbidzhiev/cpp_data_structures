add_library(HelloWorld)

target_sources(HelloWorld
    PRIVATE
        src/hw.cpp
)

target_include_directories(HelloWorld
    PUBLIC
        include
)

add_subdirectory(tests)
add_subdirectory(examples)
