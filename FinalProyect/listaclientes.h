#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H

#include "nodoclientes.h"

class listaClientes
{
protected:
    nodoClientes *cab;
    unsigned short nClie;
public:
    listaClientes();
    ~listaClientes();
    nodoClientes *getCab() const;
    void setCab(nodoClientes *value);
    unsigned short getNClie() const;
    void setNClie(unsigned short value);
    void registrarClientes();
    void insertarClientes(clientes *clie);
    void listarClientes();
    void encabezadoClien();
    void encabezadoElejir();
    void mostrarClie(clientes *clie, int x);
    nodoClientes *elegirClientes();
    bool idExistente(int id) const;
    //void eliminarCliente(nodoClientes* clienteEliminar);

};

#endif // LISTACLIENTES_H
