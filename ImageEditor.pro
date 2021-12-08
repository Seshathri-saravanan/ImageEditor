QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#TARGET = OpenMP
#CONFIG += c++11
#QMAKE_CXXFLAGS +=-Xclang
#QMAKE_CXXFLAGS+=-fopenmp
#QMAKE_LFLAGS += -libomp
#CONFIG += console
#LIBS += -lomp
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#LIBS +=-L"/opt/homebrew/opt/llvm/lib"
#QMAKE_LFLAGS =-L"/opt/homebrew/opt/llvm/lib"
#QMAKE_CXXFLAGS+=-Xclang
#QMAKE_CXXFLAGS=-fopenmp
#QMAKE_LIBDIR+=/opt/homebrew/opt/llvm/lib
#QMAKE_CXXFLAGS+=-L/opt/homebrew/opt/llvm/lib
#QMAKE_CXXFLAGS+=-I/opt/homebrew/opt/llvm/include
#QMAKE_CXXFLAGS += -Xclangsfsf
#QMAKE_CXXFLAGS += -fopenmp
#QMAKE_CXXFLAGS += -v
#QMAKE_LFLAGS += -L/opt/homebrew/opt/llvm/lib
#QMAKE_LFLAGS += -fopenmp

LIBS += -L/opt/homebrew/opt/llvm/lib
LIBS += -fopenmp
#QMAKE_CXXFLAGS += -lomp
#QMAKE_LFLAGS += -lomp
QMAKE_LINK = /opt/homebrew/opt/llvm/bin/clang++
QMAKE_CC = /opt/homebrew/opt/llvm/bin/clang
QMAKE_CXX = /opt/homebrew/opt/llvm/bin/clang++
QMAKE_LFLAGS += -fopenmp
QMAKE_CXXFLAGS += -fopenmp
#LIBS += -fopenmp


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
