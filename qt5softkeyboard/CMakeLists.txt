set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SRC_FILES
    "*.cpp"
    "*.h" 
    "*.ui"
)


# 添加Qt模块
find_package(Qt5Gui)
include_directories(${Qt5Gui_PRIVATE_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../pinyin/include)

add_library(Qt5Input SHARED ${SRC_FILES} res.qrc)

# 链接依赖库
target_link_libraries(Qt5Input
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    pinyin
)

# 设置插件输出路径
set_target_properties(Qt5Input PROPERTIES
    DEBUG_POSTFIX "d"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins/platforminputcontexts"
)
# MSVC编码设置
if(MSVC)
    target_compile_options(Qt5Input PRIVATE "/utf-8")
endif()

get_filename_component(ROOT_DIRECTORY ${PROJECT_SOURCE_DIR} DIRECTORY)
SET(PROJECT_OUTPUT_DIR "${ROOT_DIRECTORY}/output")
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "${ROOT_DIRECTORY}/install"  CACHE PATH "set install directory" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
install (DIRECTORY "${PROJECT_OUTPUT_DIR}/release/" DESTINATION bin/release FILES_MATCHING PATTERN "*.dll")
install (DIRECTORY "${PROJECT_OUTPUT_DIR}/debug/" DESTINATION bin/debug FILES_MATCHING PATTERN "*.dll")