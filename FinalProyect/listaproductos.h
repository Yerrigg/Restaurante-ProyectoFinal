#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H
#include "nodoproductos.h"

class listaProductos
{
protected:
    int nPro;
    nodoProductos *cab;
public:
    listaProductos();
    ~listaProductos();
    int getNPro() const;
    void setNPro(int value);
    nodoProductos *getCab() const;
    void setCab(nodoProductos *value);
    void registrarProducto();
    void insertarProducto(productos *pro);
    void listarProductos();
    void encabezadoPro();
    void mostrarProductos(productos *pro, int x);
    void recuperarProductos();
    void guardarProductosArchivo(productos *pro);
    void actualizarStockArchivo();
    nodoProductos *elegirProductos();
    bool verificarStockSuficiente(nodoProductos *pro);
};

#endif // LISTAPRODUCTOS_H
