add_library(RingBuffer INTERFACE)

target_sources(RingBuffer
    INTERFACE
        FILE_SET HEADERS
        FILES
        ring_buffer.hpp
)

add_subdirectory(tests)
