QT += core network sql

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT_DEBUG_PLUGINS = 1

SOURCES += \
        base/baseserver.cpp \
        base/component.cpp \
        base/dbconnection.cpp \
        base/singleton.cpp \
        controller/authcontroller.cpp \
        controller/base/controller.cpp \
        controller/frontcontroller.cpp \
        controller/projectcontroller.cpp \
        dto/base/datatransferobject.cpp \
        dto/base/response.cpp \
        dto/request/loginrequest.cpp \
        dto/request/participationrequest.cpp \
        dto/request/projectpostrequest.cpp \
        dto/request/projectrequest.cpp \
        dto/request/projectupdaterequest.cpp \
        dto/request/registerrequest.cpp \
        dto/request/simplerequest.cpp \
        dto/response/projectresponse.cpp \
        dto/response/userresponse.cpp \
        main.cpp \
        model/base/model.cpp \
        model/project.cpp \
        model/session.cpp \
        model/user.cpp \
        model/userproject.cpp \
        repository/base/repository.cpp \
        repository/projectrepository.cpp \
        repository/sessionrepository.cpp \
        repository/userprojectrepository.cpp \
        repository/userrepository.cpp \
        server.cpp \
        service/authservice.cpp \
        service/base/service.cpp \
        service/projectservice.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    base/baseserver.h \
    base/component.h \
    base/dbconnection.h \
    base/singleton.h \
    controller/authcontroller.h \
    controller/base/controller.h \
    controller/frontcontroller.h \
    controller/projectcontroller.h \
    dto/base/datatransferobject.h \
    dto/base/response.h \
    dto/request/loginrequest.h \
    dto/request/participationrequest.h \
    dto/request/projectpostrequest.h \
    dto/request/projectrequest.h \
    dto/request/projectupdaterequest.h \
    dto/request/registerrequest.h \
    dto/request/simplerequest.h \
    dto/response/projectresponse.h \
    dto/response/userresponse.h \
    model/base/model.h \
    model/project.h \
    model/session.h \
    model/user.h \
    model/userproject.h \
    repository/base/repository.h \
    repository/projectrepository.h \
    repository/sessionrepository.h \
    repository/userprojectrepository.h \
    repository/userrepository.h \
    server.h \
    service/authservice.h \
    service/base/service.h \
    service/projectservice.h
