# Add library cpp files
add_library(Blink INTERFACE)
target_sources(Blink INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lib/Blink/blink.c
)

# Add include directory
target_include_directories(Blink INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/lib/Blink/
    ${CMAKE_CURRENT_LIST_DIR}/port/Blink
    )

# Add the standard library to the build
target_link_libraries(Blink INTERFACE pico_stdlib)
