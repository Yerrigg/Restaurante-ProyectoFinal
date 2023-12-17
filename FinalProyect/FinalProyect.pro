TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    restaurante.cpp \
    listatrabajadores.cpp \
    nodotrabajadores.cpp \
    trabajadores.cpp \
    basicas.cpp \
    persona.cpp \
    listaclientes.cpp \
    nodoclientes.cpp \
    clientes.cpp \
    listamesas.cpp \
    nodomesas.cpp \
    mesa.cpp \
    listaproductos.cpp \
    nodoproductos.cpp \
    productos.cpp \
    listaventas.cpp \
    nodoventa.cpp \
    venta.cpp \
    listacompras.cpp \
    nodocompra.cpp \
    compra.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    restaurante.h \
    listatrabajadores.h \
    nodotrabajadores.h \
    trabajadores.h \
    basicas.h \
    persona.h \
    listaclientes.h \
    nodoclientes.h \
    clientes.h \
    listamesas.h \
    nodomesas.h \
    mesa.h \
    listaproductos.h \
    nodoproductos.h \
    productos.h \
    listaventas.h \
    nodoventa.h \
    venta.h \
    listacompras.h \
    nodocompra.h \
    compra.h

