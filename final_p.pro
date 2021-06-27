QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_movie.cpp \
    admin_panel.cpp \
    delete_movie.cpp \
    edit_movie.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    movie.cpp \
    signup.cpp \
    user.cpp

HEADERS += \
    add_movie.h \
    admin_panel.h \
    delete_movie.h \
    edit_movie.h \
    login.h \
    mainwindow.h \
    menu.h \
    movie.h \
    signup.h \
    user.h

FORMS += \
    add_movie.ui \
    admin_panel.ui \
    delete_movie.ui \
    edit_movie.ui \
    login.ui \
    mainwindow.ui \
    menu.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Photos.qrc
