#include "mainwindow.h"
#include "ui_mainwindow.h"

class SimpleRequest
{
public:
    int id;

    SimpleRequest() {}
    SimpleRequest(unsigned int id) : id(id) {}

    QJsonDocument toJson() {
        return QJsonDocument(
            QJsonObject{
                {"id", id}
            }
            );
    }
};

class LoginRequest
{
public:
    QString login;
    QString password;

    LoginRequest() {}
    LoginRequest(QString login, QString password) : login(login), password(password) {}

    QJsonDocument toJson() {
        return QJsonDocument(
            QJsonObject{
                {"login", login},
                {"password", password}
            }
        );
    }
};

class RegisterRequest
{
public:
    QString email;
    QString username;
    QString password;

    RegisterRequest() {}
    RegisterRequest(QString email, QString username, QString password) : email(email), username(username), password(password) {}

    QJsonDocument toJson() {
        return QJsonDocument(
            QJsonObject{
                {"email", email},
                {"username", username},
                {"password", password}
            }
            );
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(111);

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &QTcpSocket::deleteLater);

    socket->connectToHost("127.0.0.1", 23232);
    qDebug() << "Connected";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotReadyRead() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_7);
    if (in.status() != QDataStream::Ok) {
        qDebug() << "QDataStream Error";
    }
    else {
        qDebug() << "Reading...";
        quint16 nextBlockSize{};
        for (;;) {
            if (nextBlockSize == 0) {
                if (socket->bytesAvailable() < 2) {
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize) {
                qDebug() << "Invalid stream";
                break;
            }
            quint16 key;
            QJsonDocument json;
            in >> key >> json;

            ui->textBrowser->append(json.toJson());

            break;
        }
    }
}

enum class KEY {LOGIN=1, REG};

void MainWindow::sendToServer(const quint16 key, const QJsonDocument& json) {
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    out << quint16(0) << key << json;
    out.device()->seek(0);
    out << quint16(data.size()-sizeof(quint16));

    socket->write(data);
}

void MainWindow::on_pushButton_clicked()
{
    sendToServer(1, LoginRequest("MDxR", "12345").toJson());
}

void MainWindow::on_pushButton_2_clicked()
{
    sendToServer(2, RegisterRequest("d1m1triy@mdx3r.com", "D1m1tr1y", "12345").toJson());
}


void MainWindow::on_pushButton_3_clicked()
{
    sendToServer(3, SimpleRequest(0).toJson());
}


void MainWindow::on_pushButton_4_clicked()
{
    sendToServer(104, SimpleRequest(1).toJson());
}

void MainWindow::on_pushButton_5_clicked()
{
    sendToServer(103, SimpleRequest(5).toJson());
}

