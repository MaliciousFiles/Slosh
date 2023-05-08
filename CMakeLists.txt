cmake_minimum_required(VERSION 3.25)
project(Slosh)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# need this on Windows for some reason
list(APPEND CMAKE_PREFIX_PATH "C:\\Qt\\6.5.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Slosh main.cpp icons/icons.qrc widgets/Window.h widgets/Window.cpp widgets/toolbar/Toolbar.h widgets/toolbar/Toolbar.cpp widgets/toolbar/ToolbarButton.h widgets/toolbar/ToolbarButton.cpp widgets/canvas/Canvas.h widgets/canvas/Canvas.cpp widgets/toolbar/ToolbarActions.h widgets/toolbar/ToolbarActions.cpp widgets/sidebar/Sidebar.h widgets/sidebar/Sidebar.cpp widgets/sidebar/SidebarWidget.h widgets/sidebar/SidebarWidget.cpp widgets/sidebar/NewFluidSidebar.cpp widgets/sidebar/NewFluidSidebar.h api/MaterialData.h api/MaterialData.cpp widgets/util/NumberInput.h widgets/util/NumberInput.cpp widgets/util/TextInput.cpp widgets/util/TextInput.h api/Container.h api/Container.h api/Substance.h api/Substance.cpp api/Container.cpp util/ChemistryHelper.h util/ChemistryHelper.cpp util/TooltipRichTextFilter.cpp util/TooltipRichTextFilter.h widgets/sidebar/NewContainerSidebar.cpp widgets/sidebar/NewContainerSidebar.h util/GlobalClickHandler.cpp util/GlobalClickHandler.h api/ChemicalEquation.h api/ChemicalEquation.cpp widgets/canvas/Container.cpp widgets/canvas/Container.h)
target_link_libraries(Slosh
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    add_custom_command(TARGET Slosh POST_BUILD COMMAND C:\\Qt\\6.5.0\\mingw_64\\bin\\windeployqt --no-translations Slosh.exe)
endif (WIN32)
