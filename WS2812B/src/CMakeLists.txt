add_executable(${NAME}
        main.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} pico_stdlib PicoLed)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

