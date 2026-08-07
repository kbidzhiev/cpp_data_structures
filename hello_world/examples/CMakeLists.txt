add_executable(basic_usage
    basic_usage.cpp
)

target_link_libraries(hello_world # hpp name
    PRIVATE
        hello_world # include foldername
)

