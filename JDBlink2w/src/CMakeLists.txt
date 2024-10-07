add_executable(${NAME}
        jdBlink2w.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} pico_stdlib pico_cyw43_arch_none)

set_target_properties(${NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

