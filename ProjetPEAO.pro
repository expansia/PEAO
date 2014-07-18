#-------------------------------------------------
#
# Project created by QtCreator 2014-07-17T08:57:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetPEAO
TEMPLATE = app


SOURCES += main.cpp\
        f_principale.cpp \
    f_las.cpp \
    peao.cpp \
    gestionnairefenetre.cpp \
    las.cpp

HEADERS  += f_principale.hpp \
    f_las.hpp \
    peao.hpp \
    gestionnairefenetre.hpp \
    constantes.hpp \
    las.hpp

FORMS    += f_principale.ui \
    f_las.ui
