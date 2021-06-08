cmake_minimum_required(VERSION 3.17)
project(game2)

set(CMAKE_CXX_STANDARD 20)

add_executable(game2 main.cpp src/Game.cpp headers/Game.h src/Player.cpp headers/Player.h src/SwagBall.cpp headers/SwagBall.h src/Controls.cpp headers/Controls.h)

include_directories(C:/SFML/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(game2 ${SFML_LIBRARIES})
endif ()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR} /../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()