cmake_minimum_required(VERSION 3.2)
set(CMAKE_C_COMPILER /depot/qsc/QSCQ/bin/gcc)
set(CMAKE_CXX_COMPILER /depot/qsc/QSCQ/bin/g++)
project(progs)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(Qt5_DIR "/global/libs/qt_qscn_2017.09/5.6.2/linux64_debug_shlib/install/lib/cmake/Qt5" CACHE PATH "Initial cache" FORCE)



# find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
add_subdirectory(prog1)
add_subdirectory(prog2)
add_subdirectory(prog3)
add_subdirectory(prog4)
add_subdirectory(prog5)
add_subdirectory(prog6)
add_subdirectory(prog7)
add_subdirectory(prog8)
add_subdirectory(prog9)
# qt5_use_modules(customfault Core Widgets)
