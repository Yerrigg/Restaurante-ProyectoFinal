#include "trabajadores.h"
float Trabajadores::getSueldo() const
{
    return sueldo;
}

void Trabajadores::setSueldo(float value)
{
    sueldo = value;
}
string Trabajadores::getCodigo() const
{
    return codigo;
}

void Trabajadores::setCodigo(const string &value)
{
    codigo = value;
}
Trabajadores::Trabajadores()
{
this->sueldo = 0.0;
}

Trabajadores::~Trabajadores()
{

}

void Trabajadores ::leerTrabajadores(){
    basicas::imprimirPantalla2();
    basicas::gotoxy(30,5); this->setCodigo ( basicas::leerTexto("Ingrese su codigo: "));
    basicas::gotoxy(30,6); this->setNombre(basicas::leerTexto("Ingrese nombre: "));
    basicas::gotoxy(30,7); this->setDni(basicas::leerTexto("Ingrese su Dni: "));
    basicas::gotoxy(30,8); this->setSueldo(basicas::leerEntero("Ingrese su sueldo: "));
}



