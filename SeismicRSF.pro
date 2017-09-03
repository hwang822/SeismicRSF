TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    codes/segy/Msegyread.c \
    codes/segy/segy.c

HEADERS += \
    seismicrsf.h

unix:!macx: LIBS += -L$$PWD/lib/ -lrsf

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix:!macx: PRE_TARGETDEPS += $$PWD/lib/librsf.a

DISTFILES += \
    qtbin/Makefile \
    bin/segy/sfsegyread.par
