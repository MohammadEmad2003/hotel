/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QWidget *LeftMenuContainer;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *MenuBtn;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *HomeBtn;
    QPushButton *SettinBtn_2;
    QPushButton *InfoBtn_2;
    QPushButton *HelpBtn_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *STABtn;
    QWidget *MainMenuContainer;
    QVBoxLayout *verticalLayout;
    QWidget *HeaderContainer;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *MainMenu;
    QVBoxLayout *verticalLayout_2;
    QWidget *topContainer;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *head2;
    QPushButton *Plot;
    QWidget *page_2;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(1082, 695);
        Window->setStyleSheet(QString::fromUtf8("*{\n"
"	border: none;\n"
"	background-color: transparent;\n"
"	padding: 0;\n"
"	margin: 0;\n"
" 	color: #fff;\n"
"}\n"
"\n"
"#centralwidget{\n"
"	border-image: url(:/icons/icons/bg.jpg) 0 0 0 0;\n"
"}\n"
"#LeftMenuContainer{\n"
"	background-color: rgba(22, 25, 29, 170);\n"
"border-radius: 10px;\n"
"}\n"
"#LeftMenuContainer QPushButton{\n"
"	text-align: left;\n"
"	padding: 5px 10px;\n"
"	border-top-left-radius: 10px;\n"
"	border-bottom-left-radius: 10px;\n"
"	font-family: 'Roboto';\n"
"	font-size: 9pt;\n"
"}\n"
"#head1, #head2{\n"
"	font-family: 'Roboto';\n"
"	font-size: 12pt;\n"
"border-radius: 10px;\n"
"}\n"
"#topContainer, #buttomContainer{\n"
"	background-color: rgba(22, 25, 29, 150);\n"
"border-radius: 10px;\n"
"}\n"
"#frame, #frame_7, #HeaderContainer, #FooterContainer{\n"
"	background-color: rgba(22, 25, 29, 190);\n"
"	border-radius: 10px;\n"
"}\n"
"#InsertFile, #Plot{\n"
"background-color: rgba(22, 25, 29, 255);\n"
"	border-top-right-radius: 5px;\n"
"	border-bottom-right-radius: 5px;\n"
"	border-top-lef"
                        "t-radius: 5px;\n"
"	border-bottom-left-radius: 5px;\n"
"}"));
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setFrameShadow(QFrame::Shadow::Plain);
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        LeftMenuContainer = new QWidget(page);
        LeftMenuContainer->setObjectName("LeftMenuContainer");
        verticalLayout_4 = new QVBoxLayout(LeftMenuContainer);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(10, 0, 0, 0);
        widget_4 = new QWidget(LeftMenuContainer);
        widget_4->setObjectName("widget_4");
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        MenuBtn = new QPushButton(widget_4);
        MenuBtn->setObjectName("MenuBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/align-justify.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MenuBtn->setIcon(icon);
        MenuBtn->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(MenuBtn, 0, Qt::AlignmentFlag::AlignLeft);


        verticalLayout_4->addWidget(widget_4, 0, Qt::AlignmentFlag::AlignTop);

        widget_5 = new QWidget(LeftMenuContainer);
        widget_5->setObjectName("widget_5");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 10, 0, 10);
        HomeBtn = new QPushButton(widget_5);
        HomeBtn->setObjectName("HomeBtn");
        HomeBtn->setStyleSheet(QString::fromUtf8("Rectangle {\n"
"    id: flashingblob\n"
"    width: 75; height: 75\n"
"    color: \"blue\"\n"
"    opacity: 1.0\n"
"\n"
"    MouseArea {\n"
"        anchors.fill: parent\n"
"        onClicked: {\n"
"            animateColor.start()\n"
"            animateOpacity.start()\n"
"        }\n"
"    }\n"
"\n"
"    PropertyAnimation {id: animateColor; target: flashingblob; properties: \"color\"; to: \"green\"; duration: 100}\n"
"\n"
"    NumberAnimation {\n"
"        id: animateOpacity\n"
"        target: flashingblob\n"
"        properties: \"opacity\"\n"
"        from: 0.99\n"
"        to: 1.0\n"
"        loops: Animation.Infinite\n"
"        easing {type: Easing.OutBack; overshoot: 500}\n"
"   }\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/log-out.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HomeBtn->setIcon(icon1);
        HomeBtn->setIconSize(QSize(24, 24));

        verticalLayout_5->addWidget(HomeBtn);

        SettinBtn_2 = new QPushButton(widget_5);
        SettinBtn_2->setObjectName("SettinBtn_2");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/settings.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SettinBtn_2->setIcon(icon2);
        SettinBtn_2->setIconSize(QSize(24, 24));

        verticalLayout_5->addWidget(SettinBtn_2);

        InfoBtn_2 = new QPushButton(widget_5);
        InfoBtn_2->setObjectName("InfoBtn_2");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/info.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        InfoBtn_2->setIcon(icon3);
        InfoBtn_2->setIconSize(QSize(24, 24));

        verticalLayout_5->addWidget(InfoBtn_2);

        HelpBtn_2 = new QPushButton(widget_5);
        HelpBtn_2->setObjectName("HelpBtn_2");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/help-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HelpBtn_2->setIcon(icon4);
        HelpBtn_2->setIconSize(QSize(24, 24));

        verticalLayout_5->addWidget(HelpBtn_2);


        verticalLayout_4->addWidget(widget_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        widget_6 = new QWidget(LeftMenuContainer);
        widget_6->setObjectName("widget_6");
        verticalLayout_6 = new QVBoxLayout(widget_6);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 10, 0, 10);
        STABtn = new QPushButton(widget_6);
        STABtn->setObjectName("STABtn");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/external-link.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        STABtn->setIcon(icon5);
        STABtn->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(STABtn);


        verticalLayout_4->addWidget(widget_6, 0, Qt::AlignmentFlag::AlignBottom);


        horizontalLayout_2->addWidget(LeftMenuContainer);

        MainMenuContainer = new QWidget(page);
        MainMenuContainer->setObjectName("MainMenuContainer");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MainMenuContainer->sizePolicy().hasHeightForWidth());
        MainMenuContainer->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(MainMenuContainer);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, 0, 0);
        HeaderContainer = new QWidget(MainMenuContainer);
        HeaderContainer->setObjectName("HeaderContainer");
        horizontalLayout_5 = new QHBoxLayout(HeaderContainer);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        frame_2 = new QFrame(HeaderContainer);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_2);
        horizontalLayout_7->setSpacing(7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(40, 35));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/logo.png")));
        label_4->setScaledContents(true);

        horizontalLayout_7->addWidget(label_4);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_5->setFont(font);

        horizontalLayout_7->addWidget(label_5);


        horizontalLayout_5->addWidget(frame_2, 0, Qt::AlignmentFlag::AlignLeft);


        verticalLayout->addWidget(HeaderContainer, 0, Qt::AlignmentFlag::AlignTop);

        MainMenu = new QWidget(MainMenuContainer);
        MainMenu->setObjectName("MainMenu");
        sizePolicy1.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(MainMenu);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 11, 0, 0);
        topContainer = new QWidget(MainMenu);
        topContainer->setObjectName("topContainer");
        sizePolicy1.setHeightForWidth(topContainer->sizePolicy().hasHeightForWidth());
        topContainer->setSizePolicy(sizePolicy1);
        topContainer->setMinimumSize(QSize(200, 0));
        verticalLayout_3 = new QVBoxLayout(topContainer);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_7 = new QFrame(topContainer);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_7);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        head2 = new QLabel(frame_7);
        head2->setObjectName("head2");
        head2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(head2);


        verticalLayout_3->addWidget(frame_7, 0, Qt::AlignmentFlag::AlignTop);

        Plot = new QPushButton(topContainer);
        Plot->setObjectName("Plot");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setBold(true);
        Plot->setFont(font1);
        Plot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, \n"
"                                          stop:0 rgba(50, 150, 250, 255), \n"
"                                          stop:1 rgba(0, 100, 200, 255));\n"
"        color: white;\n"
"        border: 2px solid rgba(255, 255, 255, 0.5);\n"
"        border-radius: 15px; /* Rounded corners */\n"
"        padding: 5px 10px;\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        font-family: \"Arial\";\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, \n"
"                                          stop:0 rgba(70, 170, 255, 255), \n"
"                                          stop:1 rgba(10, 120, 220, 255));\n"
"        border: 2px solid rgba(255, 255, 255, 0.8);\n"
"        box-shadow: 0px 0px 10px rgba(0, 150, 255, 0.6); /* Glow effect */\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: rgba(0, 90, 180, 255);\n"
""
                        "        border: 2px solid rgba(255, 255, 255, 0.8);\n"
"    }"));

        verticalLayout_3->addWidget(Plot, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_2->addWidget(topContainer);


        verticalLayout->addWidget(MainMenu);


        horizontalLayout_2->addWidget(MainMenuContainer);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        Window->setCentralWidget(centralwidget);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        MenuBtn->setText(QString());
        HomeBtn->setText(QCoreApplication::translate("Window", "  Log Out", nullptr));
        SettinBtn_2->setText(QCoreApplication::translate("Window", " Settings", nullptr));
        InfoBtn_2->setText(QCoreApplication::translate("Window", " Information", nullptr));
        HelpBtn_2->setText(QCoreApplication::translate("Window", " Help", nullptr));
        STABtn->setText(QCoreApplication::translate("Window", "  Exit", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("Window", "Moder Hotel Management System", nullptr));
        head2->setText(QCoreApplication::translate("Window", "Put Your Page Name", nullptr));
        Plot->setText(QCoreApplication::translate("Window", "Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
