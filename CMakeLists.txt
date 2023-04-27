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

add_executable(Slosh main.cpp icons/icons.qrc widgets/Window.h widgets/Window.cpp widgets/toolbar/Toolbar.h widgets/toolbar/Toolbar.cpp widgets/toolbar/ToolbarButton.h widgets/toolbar/ToolbarButton.cpp widgets/canvas/Canvas.h widgets/canvas/Canvas.cpp widgets/toolbar/ToolbarActions.h widgets/toolbar/ToolbarActions.cpp widgets/sidebar/Sidebar.h widgets/sidebar/Sidebar.cpp widgets/sidebar/SidebarWidget.h widgets/sidebar/SidebarWidget.cpp widgets/sidebar/NewFluidSidebar.cpp widgets/sidebar/NewFluidSidebar.h api/FluidData.h api/FluidData.cpp widgets/util/NumberInput.h widgets/util/NumberInput.cpp widgets/util/TextInput.cpp widgets/util/TextInput.h)
target_link_libraries(Slosh
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

