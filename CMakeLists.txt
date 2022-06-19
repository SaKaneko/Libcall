cmake_minimum_required(VERSION 3.1)
#enable_language(CXX)
set(CMAKE_CXX_STANDARD 17) # C++17...
#set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
#set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11
set(CMAKE_CXX_COMPILER g++)
## Set our project name
project(Libcall CXX)

set(libcall_src
    main.cpp
    src/help.cpp
    src/config.cpp
)

## Define the executable
add_executable(libcall ${libcall_src})

install(TARGETS libcall
        DESTINATION bin)