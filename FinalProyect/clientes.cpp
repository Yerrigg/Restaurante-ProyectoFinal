#include "clientes.h"
#include "basicas.h"

int clientes::getAcomp() const
{
    return acomp;
}

void clientes::setAcomp(int value)
{
    acomp = value;
}

int clientes::getId() const
{
    return id;
}

void clientes::setId(int value)
{
    id = value;
}
clientes::clientes()
{
    this->acomp = 0;
    this->id =  0;
}

clientes::~clientes()
{

}

void clientes::leerClientes(){
    basicas::imprimirPantalla2();
    basicas::gotoxy(30,6); this->setId( basicas::leerEntero("Identificador de Cliente: "));
    basicas::gotoxy(30,7); this->setAcomp ( basicas::leerEntero("Ingrese numero de acompanantes: "));
    basicas::gotoxy(30,8); this->setNombre(basicas::leerTexto("Ingrese nombre: "));
    basicas::gotoxy(30,9); this->setDni(basicas::leerTexto("Ingrese su Dni: "));
}



