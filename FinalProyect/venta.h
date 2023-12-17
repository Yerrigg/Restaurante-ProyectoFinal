#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include "trabajadores.h"
#include "clientes.h"
#include "listacompras.h"
#include "listaproductos.h"
using namespace std;

class  venta
{
protected:
    string codigo;
    string fecha;
    string hora;
    clientes *clie;
    Trabajadores *tra;
    float dineroDado;
    float montoTotal;
    listaCompras *lCom;
    listaProductos *lPro;
public:
    venta();
    ~venta();
    string getCodigo() const;
    void setCodigo(const string &value);
    string getFecha() const;
    void setFecha(const string &value);
    string getHora() const;
    void setHora(const string &value);
    clientes *getClie() const;
    void setClie(clientes *value);
    Trabajadores *getTra() const;
    void setTra(Trabajadores *value);
    float getDineroDado() const;
    void setDineroDado(float value);
    float getMontoTotal() const;
    void setMontoTotal(float value);
    listaCompras *getLCom() const;
    void setLCom(listaCompras *value);
    listaProductos *getLPro() const;
    void setLPro(listaProductos *value);
    void recuperarProductosParaVenta();
    void leerVenta();
    void generarBoleta();
    void boletaFinal();
    float calcularVuelto();
};

#endif // VENTA_H
