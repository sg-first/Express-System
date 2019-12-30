QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    expressmail.cpp \
    expresspay.cpp \
    expressquery.cpp \
    main.cpp \
    mainwindow.cpp \
    packagecheck.cpp \
    packagein.cpp \
    packageout.cpp \
    packagequery.cpp \
    payment.cpp \
    text.cpp \
    unpaidquery.cpp

HEADERS += \
    dataOperation.h \
    date.h \
    error.h \
    express.h \
    expressmail.h \
    expresspay.h \
    expressquery.h \
    help.h \
    mainwindow.h \
    packagecheck.h \
    packagein.h \
    packageout.h \
    packagequery.h \
    payment.h \
    text.h \
    unpaidquery.h

FORMS += \
    expressmail.ui \
    expresspay.ui \
    expressquery.ui \
    mainwindow.ui \
    packagecheck.ui \
    packagein.ui \
    packageout.ui \
    packagequery.ui \
    payment.ui \
    text.ui \
    unpaidquery.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
