cmake_minimum_required(VERSION 3.16)

project(MainClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup()

qt_add_executable(appMainClient
    main.cpp
)

qt_add_qml_module(appMainClient
    URI MainClient
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES page/MainPage.qml
        QML_FILES widget/Sidebar.qml
        QML_FILES widget/SidebarButton.qml
        QML_FILES widget/SidebarProjectButton.qml
        QML_FILES widget/Navbar.qml
        QML_FILES page/BacklogPage.qml
        QML_FILES page/HomePage.qml
        SOURCES page/mainpage.h page/mainpage.cpp
        SOURCES controller.h controller.cpp
        SOURCES handler.h handler.cpp
        SOURCES basepage.h basepage.cpp
        SOURCES page/authpage.h page/authpage.cpp
        QML_FILES page/AuthPage.qml
        SOURCES dto/response.h dto/response.cpp
        SOURCES dto/base/datatransferobject.h dto/base/datatransferobject.cpp
        SOURCES dto/loginrequest.h dto/loginrequest.cpp
        SOURCES model/user.h model/user.cpp
        SOURCES model/project.h model/project.cpp
        SOURCES dto/simplerequest.h dto/simplerequest.cpp
        SOURCES page/backlogpage.h page/backlogpage.cpp
        SOURCES model/task.h model/task.cpp
        SOURCES security/encoder.h security/encoder.cpp
        SOURCES security/rsaencryption.h security/rsaencryption.cpp
        SOURCES security/bigint/bigint.h security/bigint/bigint.cpp
        SOURCES security/bigint/minigmp_global.h security/bigint/mini-gmp.h
        SOURCES security/bigint/mini-gmp.cpp
        SOURCES security/aesencryption.h security/aesencryption.cpp
        QML_FILES page/CorePage.qml
        QML_FILES widget/BreadCrumbs.qml
        QML_FILES page/BoardPage.qml
        QML_FILES page/ProfilePage.qml
        SOURCES page/homepage.h page/homepage.cpp
        QML_FILES widget/ProjectButton.qml
        QML_FILES widget/TaskButton.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMainClient PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMainClient
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMainClient
    PRIVATE Qt6::Quick
    PRIVATE Qt6::QuickControls2
)

include(GNUInstallDirs)
install(TARGETS appMainClient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
