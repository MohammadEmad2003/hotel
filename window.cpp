#include "window.h"
#include "ui_window.h"
#include <QMainWindow>
#include <QDebug>
#include <QDir>
#include <QVariant>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "qcustomplot.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Window)
{
    ui->setupUi(this);
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setEasingCurve(QEasingCurve::OutQuad);
    ui->passwordTxt->setEchoMode(QLineEdit::Password);
    ui->MainWindow->setCurrentIndex(0);

    defineBtn();
    SetServiceTable();
    displayRoom(101);
    BtnIconDisplay();
    Revenue rev;
    PlotGraph(rev);

    leftMenuAnimation = new QPropertyAnimation(ui->LeftMenuContainer, "size");
    centerMenuAnimation = new QPropertyAnimation(ui->MainMenuContainer, "size");
}

Window::~Window()
{
    delete ui;
    delete leftMenuAnimation;
    delete centerMenuAnimation;
    delete animation;
}



