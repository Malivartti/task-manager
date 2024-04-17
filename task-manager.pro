QT += quick

SOURCES += \
        main.cpp \
        pages/authorization/authorizationpage.cpp \
        pages/registration/registrationpage.cpp \
        pages/main/mainpage.cpp

resources.files = main.qml \
                  pages/registration/RegistrationPage.qml \
                  pages/authorization/AuthorizationPage.qml \
                  pages/main/MainPage.qml \
                  pages/home/HomePage.qml \
                  pages/projects/ProjectsPage.qml \
                  pages/account/AccountPage.qml \
                  pages/project/ProjectPage.qml \
                  pages/backlog/BacklogPage.qml \
                  pages/board/BoardPage.qml \
                  pages/tasks/TasksPage.qml \
                  pages/settings/SettingsPage.qml \
                  pages/datails/DetailsPage.qml \
                  pages/access/AccessPage.qml \
                  pages/taskTypes/TaskTypesPage.qml \
                  widgets/header/Header.qml \
                  widgets/projectSidebar/ProjectSidebar.qml \
                  widgets/settingsSidebar/SettingsSidebar.qml
resources.prefix = /$${TARGET}
RESOURCES += resources \
             qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    pages/authorization/authorizationpage.h \
    pages/registration/registrationpage.h \
    pages/main/mainpage.h


