add_executable(hello_world_tests
    hw_tests.cpp
)

target_link_libraries(hello_world_tests
    PRIVATE
        hello_world
        #project_warnings
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_world_tests)
