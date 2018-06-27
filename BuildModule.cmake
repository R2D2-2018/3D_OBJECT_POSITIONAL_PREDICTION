include (${build_environment}/flags.cmake)

set (sources ${sources}
    src/main.cpp
    src/wrap-hwlib.cpp
    src/libc-stub.cpp
)

add_definitions (-DBMPTK_TARGET_arduino_due
                 -DBMPTK_TARGET=arduino_due
                 -DBMPTK_BAUDRATE=19200)

set (cxxflags
    "-Os"
    "-ffunction-sections"
    "-fdata-sections"
    "-fno-exceptions"
    "-fno-rtti"
    "-fno-threadsafe-statics")

string (REGEX REPLACE ";" " " cxxflags "${cxxflags}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxxflags}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles -nostdlib -Wl,--defsym=STACK_SIZE=92160")

# The target chip that is compiled for:
include (${toolchain}/targets/arm32/cm3/atmel/sam3x/sam3x8e/sam3x8e.cmake)

# The flashscript used to flash the binary (optional):
include (${toolchain}/targets/arm32/cm3/atmel/sam3x/sam3x8e/flashscripts/arduino_due.cmake)
