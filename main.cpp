#include "window.cpp"
#include <QApplication>
#include <QCoreApplication>
#include <QIcon>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/icons/logo.png"));
    Window w;
    w.show();

    return a.exec();
}

