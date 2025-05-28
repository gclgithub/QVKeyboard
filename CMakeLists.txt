cmake_minimum_required(VERSION 3.10)
project(QVKeyboard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set project output directory
string(REGEX REPLACE "/code" "" PROJECT_OUTPUT_DIR ${PROJECT_SOURCE_DIR})
set(PROJECT_OUTPUT_DIR "${PROJECT_OUTPUT_DIR}/output")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_OUTPUT_DIR}")
set(LIBRARY_OUTPUT_PATH "${PROJECT_OUTPUT_DIR}")

# 查找Qt依赖
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# 添加子目录
add_subdirectory(pinyin)
add_subdirectory(qt5softkeyboard)
option(Example_QT5SOFTKEYBOARD "Use Qt5SoftKeyboard example" ON)
if(Example_QT5SOFTKEYBOARD)
    add_subdirectory(TestKeyboard)
endif()