#include <QCoreApplication>
#include "server.h"

#include <thread>
#include <chrono>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    Server s;

    return a.exec();
}
