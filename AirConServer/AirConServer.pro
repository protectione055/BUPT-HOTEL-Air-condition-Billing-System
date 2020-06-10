QT       += \
            core gui\
            network\
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

UI_DIR = ./UI
RC_FILE = logo.rc
CONFIG += C++11
msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admincontroller.cpp \
    dialogcheckin.cpp \
    dialogcheckout.cpp \
    main.cpp \
    scheduleobject.cpp \
    serverobject.cpp \
    waitingobject.cpp

HEADERS += \
    admincontroller.h \
    aircondata.h \
    dialogcheckin.h \
    dialogcheckout.h \
    scheduleobject.h \
    serverobject.h \
    waitingobject.h

FORMS += \
    admincontroller.ui \
    dialogcheckin.ui \
    dialogcheckout.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
