#include "productos.h"
#include "basicas.h"

string productos::getNombre() const
{
    return nombre;
}

void productos::setNombre(const string &value)
{
    nombre = value;
}

string productos::getCategoria() const
{
    return categoria;
}

void productos::setCategoria(const string &value)
{
    categoria = value;
}

float productos::getPrecio() const
{
    return precio;
}

void productos::setPrecio(float value)
{
    precio = value;
}

int productos::getStock() const
{
    return stock;
}

void productos::setStock(int value)
{
    stock = value;
}
productos::productos()
{
    this->precio= 0.0;
    this->stock= 0;
}

productos::~productos()
{

}

void productos::leerProducto(){
    basicas::imprimirPantalla2();
    basicas::gotoxy(30,5); this->nombre = basicas::leerTexto("Ingrese nombre plato: ");
    basicas::gotoxy(30,6); this->categoria = basicas::leerTexto("Ingrese el categoria plato: ");
    basicas::gotoxy(30,7); this->precio = basicas::leerFloat("Ingrese precio: ");
    basicas::gotoxy(30,8); this->stock = basicas::leerEntero("Ingrese stock: ");
}
