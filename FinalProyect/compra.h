#ifndef COMPRA_H
#define COMPRA_H

#include "productos.h"
#include "nodoproductos.h"
class compra
{
 protected:
    int cantidad;
    float subTotal;
    productos *prod;
public:
    compra();
    ~compra();
    int getCantidad() const;
    void setCantidad(int value);
    float getSubTotal() const;
    void setSubTotal(float value);
    productos *getProd() const;
    void setProd(productos *value);
    void leerCompra(nodoProductos *eP);
};

#endif // COMPRA_H
