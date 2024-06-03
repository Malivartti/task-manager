#include <QCoreApplication>
#include <QTest>

#include "server.h"
// #include "tests/authservicetests.h"
// #include "tests/projectservicetests.h"
// #include "tests/taskservicetests.h"
// #include "tests/encodertests.h"

// #include <thread>
// #include <chrono>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server s;

    // freopen("testing.log", "w", stdout);
    // QTest::qExec(new AuthServiceTests, argc, argv);
    // QTest::qExec(new ProjectServiceTests, argc, argv);
    // QTest::qExec(new TaskServiceTests, argc, argv);
    // QTest::qExec(new EncoderTests, argc, argv);

    return a.exec();
}
