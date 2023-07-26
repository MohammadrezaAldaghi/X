QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    organisationuser.cpp \
    personaluser.cpp \
    signupPersonalUser.cpp \
    signuporganisationuser.cpp \
    startwindow.cpp \
    user.cpp

HEADERS += \
    mainwindow.h \
    organisationuser.h \
    personaluser.h \
    signupPersonalUser.h \
    signuporganisationuser.h \
    startwindow.h \
    user.h

FORMS += \
    mainwindow.ui \
    signupPersonalUser.ui \
    signuporganisationuser.ui \
    startwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
