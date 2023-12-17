#ifndef LISTAMESAS_H
#define LISTAMESAS_H
#include "nodomesas.h"

class listaMesas
{
protected:
    nodoMesas *cab;
    unsigned short nMesa;
public:
    listaMesas();
    ~listaMesas();
    nodoMesas *getCab() const;
    void setCab(nodoMesas *value);
    unsigned short getNMesa() const;
    void setNMesa(unsigned short value);
    void registrarMesa();
    void insertarMesa(mesa *mes);
    void listarMesas();
    void encabezadoMes();
    void mostrarMesas(mesa *mes, int x);
    void recuperarMesas( );
    void guardarArchivoM(mesa *mes);
    nodoMesas *elegirMesa();
    bool idExistente(int id) const;
};

#endif // LISTAMESAS_H
