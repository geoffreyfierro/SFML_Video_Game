cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp GFGame/Game.cpp GFGame/Game.h GFGame/GameText.cpp GFGame/GameText.h GFGame/Game_Interface.cpp GFGame/Game_Interface.h GFGame/Thumbnail.cpp GFGame/Thumbnail.h GFGame/GFGame.cpp GFGame/GFGame.h GFGame/Player.cpp GFGame/Player.h GFGame/Platform.cpp GFGame/Platform.h GFGame/Background.cpp GFGame/Background.h GFGame/Map.cpp GFGame/Map.h GFGame/Monster.cpp GFGame/Monster.h GFGame/Hearts.cpp GFGame/Hearts.h GFGame/MonsterArray.cpp GFGame/MonsterArray.h GFGame/FinishFlag.cpp GFGame/FinishFlag.h GFGame/WonGameScreen.cpp GFGame/WonGameScreen.h GFGame/LostGameScreen.cpp GFGame/LostGameScreen.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()