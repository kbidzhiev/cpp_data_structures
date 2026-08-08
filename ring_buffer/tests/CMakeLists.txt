add_executable(ring_buffer_tests
    ring_buffer_tests.cpp
)

target_link_libraries(ring_buffer_tests
    PRIVATE
        RingBuffer
        #project_warnings
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ring_buffer_tests)
