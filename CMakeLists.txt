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

# Dependencies
if(NOT CPORTA)
    set(RAYLIB_VERSION 5.0)
    find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
    if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
    endif()
endif()

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
    PRIVATE
        main.cpp
        test_main.cpp
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
#target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)

target_compile_options(${PROJECT_NAME} 
PRIVATE
        #-Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
)
if(CPORTA)
    target_compile_options(${PROJECT_NAME} PRIVATE -DCPORTA)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
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