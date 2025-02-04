QT += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17
CONFIG += release
CONFIG -= debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -Wa,-mbig-obj

SOURCES += \
    Buttons.cpp \
    SQLite.cpp \
    cost.cpp \
    main.cpp \
    qcustomplot.cpp \
    revenue.cpp \
    room.cpp \
    services.cpp \
    structs.cpp \
    tools.cpp \
    window.cpp

HEADERS += \
    qcustomplot.h \
    window.h

FORMS += \
    window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    icons/home A.png \
    icons/home d.png
