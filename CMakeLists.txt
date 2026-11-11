cmake_minimum_required(VERSION 3.28)

project(TrophySystem)

set (CMAKE_CXX_STANDARD 26)

add_executable(main
        Header/gl_utils.h
        Header/projectile.h
        Header/tank.h
        Header/trophy_system.h
        Header/vec2.h

        Source/gl_utils.cpp
        Source/projectile.cpp
        Source/tank.cpp
        Source/trophy_system.cpp

        Source/main.cpp

)