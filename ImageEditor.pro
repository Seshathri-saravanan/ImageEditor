QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#TARGET = OpenMP
#QMAKE_LFLAGS += -openmp
#QMAKE_CXXFLAGS+= -openmp


SOURCES += \
    clickablelabel.cpp \
    main.cpp \
    imageeditor.cpp

HEADERS += \
    clickablelabel.h \
    imageeditor.h

FORMS += \
    imageeditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
