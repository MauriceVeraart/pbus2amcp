QT += core gui widgets
TEMPLATE = app
CONFIG += c++14 object_parallel_to_source

MOC_DIR = moc
UI_DIR = moc
OBJECTS_DIR = tmp

TARGET = pbus2amcp

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += ASIO_STANDALONE

HEADERS +=          \
    gui/window.hpp  \

SOURCES +=          \
    gui/window.cpp  \
    src/main.cpp    \

FORMS +=            \
    gui/window.ui   \
