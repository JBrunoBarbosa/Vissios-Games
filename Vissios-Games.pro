QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/sources/databasemanager.cpp \
    src/sources/gameimpl.cpp \
    src/sources/gamemanagementwindow.cpp \
    src/sources/gamemanagerimpl.cpp \
    src/sources/gameregistrationwindow.cpp \
    src/sources/main.cpp \
    src/sources/mainwindow.cpp

HEADERS += \
    src/headers/databasemanager.h \
    src/headers/game.h \
    src/headers/gameimpl.h \
    src/headers/gamemanagementwindow.h \
    src/headers/gamemanager.h \
    src/headers/gamemanagerimpl.h \
    src/headers/gameregistrationwindow.h \
    src/headers/mainwindow.h

FORMS += \
    src/ui/gamemanagementwindow.ui \
    src/ui/gameregistrationwindow.ui \
    src/ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
