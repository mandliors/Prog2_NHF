cmake_minimum_required(VERSION 3.23) 
project(Prog2_NHF) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Google Test
find_package(GTest QUIET)
if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
endif ()

# Raylib
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


# Compile options
function(add_compile_options target)
    target_compile_options(${target}
        PRIVATE
            -Werror
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
    )
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${target}
            PRIVATE
                -fsanitize=address
                -fno-omit-frame-pointer
        )
        target_link_options(${target}
            PRIVATE
                -fsanitize=address
        )
    endif()
endfunction()


add_library(${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME}_lib
    PUBLIC
        src # my header files are in the src directory
)
target_sources(${PROJECT_NAME}_lib
    PRIVATE
        src/AssetManager/AssetManager.cpp
        src/Bullets/Bullet.cpp
        src/Bullets/CircleBullet.cpp
        src/Collectables/Coin.cpp
        src/Collisions/Collisions.cpp
        src/Color/Color.cpp
        src/Enemies/SmallEnemy.cpp
        src/Enemies/LargeEnemy.cpp
        src/GameObjects/GameObject.cpp
        src/GameObjects/Player.cpp
        src/ParticleSystem/ParticleSystem.cpp
        src/Utils/Vec2.cpp
        src/World/World.cpp
)
add_compile_options(${PROJECT_NAME}_lib)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE 
        src/main.cpp
)
add_compile_options(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}_lib
        raylib
)

enable_testing()

add_executable(${PROJECT_NAME}_test)
target_sources(${PROJECT_NAME}_test
    PRIVATE
        test/test_main.cpp
)
add_compile_options(${PROJECT_NAME}_test)
target_link_libraries(${PROJECT_NAME}_test
    PRIVATE
        ${PROJECT_NAME}_lib
        GTest::gtest_main
        raylib
)


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)