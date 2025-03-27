# Add library cpp files
add_library(Blink INTERFACE)
target_sources(Blink INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/blink.c
)

# Add include directory
target_include_directories(Blink INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${BLINK_PORT_DIR}
    )

# Add the standard library to the build
target_link_libraries(Blink INTERFACE pico_stdlib)