cmake_minimum_required(VERSION 3.14)

project(Server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Network)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(Server
  main.cpp
  base/component.h base/component.cpp
  base/dbconnection.h base/dbconnection.cpp
  base/singleton.h base/singleton.cpp
  controller/authcontroller.h controller/authcontroller.cpp
  controller/base/controller.h controller/base/controller.cpp
  controller/frontcontroller.h controller/frontcontroller.cpp
  controller/projectcontroller.h controller/projectcontroller.cpp
  dto/base/datatransferobject.h dto/base/datatransferobject.cpp
  dto/base/response.h dto/base/response.cpp
  dto/request/loginrequest.h dto/request/loginrequest.cpp
  dto/request/participationrequest.h dto/request/participationrequest.cpp
  dto/request/projectpostrequest.h dto/request/projectpostrequest.cpp
  dto/request/projectrequest.h dto/request/projectrequest.cpp
  dto/request/projectupdaterequest.h dto/request/projectupdaterequest.cpp
  dto/request/registerrequest.h dto/request/registerrequest.cpp
  dto/request/simplerequest.h dto/request/simplerequest.cpp
  dto/response/projectresponse.h dto/response/projectresponse.cpp
  dto/response/userresponse.h dto/response/userresponse.cpp
  model/base/model.h model/base/model.cpp
  model/project.h model/project.cpp
  model/session.h model/session.cpp
  model/user.h model/user.cpp
  model/userproject.h model/userproject.cpp
  repository/base/repository.h repository/base/repository.cpp
  repository/projectrepository.h repository/projectrepository.cpp
  repository/sessionrepository.h repository/sessionrepository.cpp
  repository/userprojectrepository.h repository/userprojectrepository.cpp
  repository/userrepository.h repository/userrepository.cpp
  server.h server.cpp
  service/authservice.h service/authservice.cpp
  service/base/service.h service/base/service.cpp
  service/projectservice.h service/projectservice.cpp
  base/baseserver.h base/baseserver.cpp
  service/userservice.h service/userservice.cpp
  dto/request/userrequest.h dto/request/userrequest.cpp
  model/task.h model/task.cpp
  model/usertask.h model/usertask.cpp
  repository/taskrepository.h repository/taskrepository.cpp
  repository/usertaskrepository.h repository/usertaskrepository.cpp
  service/taskservice.h service/taskservice.cpp
  dto/response/taskresponse.h dto/response/taskresponse.cpp
  dto/request/taskpostrequest.h dto/request/taskpostrequest.cpp
  dto/request/taskupdaterequest.h dto/request/taskupdaterequest.cpp
  security/encoder.h security/encoder.cpp
  security/rsaencryption.h security/rsaencryption.cpp
  security/bigint/bigint.h security/bigint/bigint.cpp
  security/bigint/minigmp_global.h security/bigint/mini-gmp.h
  security/bigint/mini-gmp.cpp
  security/aesencryption.h security/aesencryption.cpp
  tests/authservicetests.h tests/authservicetests.cpp
  tests/projectservicetests.h tests/projectservicetests.cpp
  tests/taskservicetests.h tests/taskservicetests.cpp
  tests/encodertests.h tests/encodertests.cpp
)

target_link_libraries(Server PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt6::Sql Qt6::Network Qt6::Test)

include(GNUInstallDirs)
install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
