cmake_minimum_required(VERSION 3.23) 
project(NHF) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#############
# FONTOS    #
#########################################################
# EZT A SORT KELL KIKOMMENTELNI A TESZTELÉSHEZ          #
# MÁSHOGY LINKEL, DEFINIÁLJA A CPORTA MAKRÓT STB.       #
# set(CPORTA on)                                        #
#########################################################


# EZ A GOOGLE TESZTHEZ KELL
# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     GIT_REPOSITORY https://github.com/google/googletest.git
#     GIT_TAG        v1.14.0
# )
# FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
    PRIVATE
        AssetManager/AssetManager.cpp
        Bullets/Bullet.cpp
        Bullets/CircleBullet.cpp
        Collectables/Coin.cpp
        Collisions/Collisions.cpp
        Color/Color.cpp
        Enemies/SmallEnemy.cpp
        Enemies/LargeEnemy.cpp
        GameObjects/GameObject.cpp
        GameObjects/Player.cpp
        ParticleSystem/ParticleSystem.cpp
        Utils/Vec2.cpp
        World/World.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if(CPORTA)
    target_sources(${PROJECT_NAME} PRIVATE test_main.cpp)
    #target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
else()
    target_sources(${PROJECT_NAME} PRIVATE main.cpp)
endif()

target_compile_options(${PROJECT_NAME} 
PRIVATE
        #-Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -lGL -lm -lpthread -ldl -lrt -lX11
)
if(CPORTA)
    target_compile_options(${PROJECT_NAME} PRIVATE -DCPORTA)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -fsanitize=address
            -fno-omit-frame-pointer
    )
    target_link_options(${PROJECT_NAME}
        PRIVATE
            -fsanitize=address
    )
endif()