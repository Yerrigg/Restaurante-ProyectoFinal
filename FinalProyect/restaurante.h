#include <iostream>
#include "basicas.h"
#include "listatrabajadores.h"
#include "listaclientes.h"
#include "listamesas.h"
#include "listaproductos.h"
#include "listaventas.h"


using namespace std;
#ifndef RESTAURANTE_H
#define RESTAURANTE_H


class restaurante
{
protected:
    string nombre;
    string direccion;
    string numTel;
    string RUC;
    listaTrabajadores *lT;
    listaClientes *lC;
    listaMesas *lMes;
    listaProductos *lPr;
    listaVentas *lVen;
public:
    restaurante();
    ~restaurante();
    string getNombre() const;
    void setNombre(const string &value);
    string getDireccion() const;
    void setDireccion(const string &value);
    string getNumTel() const;
    void setNumTel(const string &value);
    listaTrabajadores *getLT() const;
    void setLT(listaTrabajadores *value);
    listaClientes *getLC() const;
    void setLC(listaClientes *value);
    listaMesas *getLMes() const;
    listaProductos *getLPr() const;
    listaVentas *getLVen() const;
    void setLVen(listaVentas *value);
    void setLPr(listaProductos *value);
    void setLMes(listaMesas *value);

    void control();
    void gestionTrabajadores();
    void gestionClientes();
    void gestionarMesas();
    void gestionarProductos();
    void gestionarVentas();
    void registrarVenta();
    void listarVentasT();
    void gestionarReportes();
};

#endif // RESTAURANTE_H
