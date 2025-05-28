
# 启用 Qt 自动处理
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 添加可执行文件
add_executable(TestKeyboard
    main.cpp
    Widget.cpp
    Widget.h
    Widget.ui
)

# 链接 Qt 库
target_link_libraries(TestKeyboard
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# MSVC 编码设置
if(MSVC)
    target_compile_options(TestKeyboard PRIVATE "/utf-8")
endif()

# 设为启动项目
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT TestKeyboard)