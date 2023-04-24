cmake_minimum_required(VERSION 3.25)
project(Slosh)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Slosh main.cpp icons/icons.qrc widgets/Window.h widgets/Window.cpp widgets/toolbar/Toolbar.h widgets/toolbar/Toolbar.cpp widgets/toolbar/ToolbarButton.h widgets/toolbar/ToolbarButton.cpp widgets/Canvas.h widgets/Canvas.cpp)
target_link_libraries(Slosh
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

