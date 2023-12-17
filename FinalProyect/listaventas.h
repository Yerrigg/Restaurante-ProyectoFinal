#ifndef LISTAVENTAS_H
#define LISTAVENTAS_H
#include "nodoventa.h"
#include "nodoclientes.h"
#include "nodotrabajadores.h"
class listaVentas
{
protected:
    nodoVenta *cab;
    unsigned short nVen;
public:
    listaVentas();
    ~listaVentas();
    nodoVenta *getCab() const;
    void setCab(nodoVenta *value);
    unsigned short getNVen() const;
    void setNVen(unsigned short value);
    void registrarVentas(nodoClientes *eC, nodoTrabajadores *eT);
    void insertarVenta(venta *ven);
    void imprimirBoleta();
    void buscarVentasPorFecha();
    void listarVentasT();
    nodoVenta *elegirVenta();
};

#endif // LISTAVENTAS_H
