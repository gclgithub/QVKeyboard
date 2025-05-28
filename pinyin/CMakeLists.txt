file(GLOB SRC_FILES 
    "share/*.cpp" 
    "include/*.h"
)

add_library(pinyin STATIC ${SRC_FILES})
target_link_libraries(pinyin Qt5::Core)
# 包含头文件目录
target_include_directories(pinyin PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# # 添加编译定义
# target_compile_definitions(qtpinyin PRIVATE
#     HAVE_PINYIN
#     QT_NO_CAST_TO_ASCII
#     QT_ASCII_CAST_WARNINGS
#     QT_NO_CAST_FROM_ASCII
#     QT_NO_CAST_FROM_BYTEARRAY
# )

# # 配置调试版本后缀
# set_target_properties(qtpinyin PROPERTIES
#     DEBUG_POSTFIX "d"
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib"
# )

# # 禁用警告
# if(MSVC)
#     target_compile_options(qtpinyin PRIVATE /W0)
# else()
#     target_compile_options(qtpinyin PRIVATE -w)
# endif()