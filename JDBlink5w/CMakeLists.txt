cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME JDBlink5w) # <-- Name your project/executable here!
set(PICO_BOARD pico_w)
set(PICO_PLATFORM rp2040)

include("$ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake")

# Gooey boilerplate
project(JDBlink5w C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(src)

#Set up files for the release packages
install(CODE "execute_process(COMMAND $ENV{HOME}/bin/picoDeploy.sh ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.elf)")

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
