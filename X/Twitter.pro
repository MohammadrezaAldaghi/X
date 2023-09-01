QT       += core gui
QT       += network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anonymoususer.cpp \
    checkaccountexist.cpp \
    followersclasses.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    mentionclasses.cpp \
    organisationuser.cpp \
    personalaccount.cpp \
    personaluser.cpp \
    signupPersonalUser.cpp \
    signupanonymoususer.cpp \
    signuporganisationuser.cpp \
    startwindow.cpp \
    tweet.cpp \
    tweetform.cpp \
    user.cpp

HEADERS += \
    anonymoususer.h \
    checkaccountexist.h \
    followersclasses.h \
    loginform.h \
    mainwindow.h \
    mentionclasses.h \
    organisationuser.h \
    personalaccount.h \
    personaluser.h \
    signupPersonalUser.h \
    signupanonymoususer.h \
    signuporganisationuser.h \
    startwindow.h \
    tweet.h \
    tweetform.h \
    user.h

FORMS += \
    loginform.ui \
    mainwindow.ui \
    personalaccount.ui \
    signupPersonalUser.ui \
    signupanonymoususer.ui \
    signuporganisationuser.ui \
    startwindow.ui \
    tweetform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



