cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17) # C++17...
set(CMAKE_CXX_COMPILER g++)

project(Libcall CXX)

set(libcall_src
    main.cpp
    src/help.cpp
    src/config.cpp
    src/read_config_txt.cpp
    src/targetutil.cpp
    src/dividecode.cpp
)

## Define the executable
add_executable(libcall ${libcall_src})

install(TARGETS libcall
        DESTINATION bin)