#ifndef LISTATRABAJADORES_H
#define LISTATRABAJADORES_H
#include <iostream>
#include "nodotrabajadores.h"
using namespace std;

class listaTrabajadores
{
protected:
    nodoTrabajadores *cab;
    unsigned short nlTra;
public:
    listaTrabajadores();
    ~listaTrabajadores();
    nodoTrabajadores *getCab() const;
    void setCab(nodoTrabajadores *value);
    unsigned short getNlTra() const;
    void setNlTra(unsigned short value);
    void registrarTrabajador();
    void insetarTrabajador(Trabajadores *tra);
    void listarTrabajadores();
    void encabezadoTra();
    void mostrarTra(Trabajadores *tra, int x);
    void  guardarTrabajadorArchivo(Trabajadores *tra);
    void recuperarTrabajadores( );
    nodoTrabajadores *elegirTrabajadores();
};

#endif // LISTATRABAJADORES_H
