QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../model/model.cc \
    ../model/cave/cave.cc \
    ../model/maze/maze.cc \
    ../model/maze/maze_cell.cc \
    ../controller/controller.cc \
    ../model/parser.cc \
    main.cc \
    main_window.cc \
    paintcavewidget.cc \
    paintmazewidget.cc

HEADERS += \
    ../model/model.h \
    ../model/cave/cave.h \
    ../model/maze/maze.h \
    ../model/maze/maze_cell.h \
    ../controller/controller.h \
    ../model/parser.h \
    main_window.h \
    paintcavewidget.h \
    paintmazewidget.h

FORMS += \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
