#include "compra.h"
#include "basicas.h"
#include "nodoproductos.h"
#include "listaproductos.h"

int compra::getCantidad() const
{
    return cantidad;
}

void compra::setCantidad(int value)
{
    cantidad = value;
}

float compra::getSubTotal() const
{
    return subTotal;
}

void compra::setSubTotal(float value)
{
    subTotal = value;
}

productos *compra::getProd() const
{
    return prod;
}

void compra::setProd(productos *value)
{
    prod = value;
}
compra::compra()
{
    this->cantidad = 0;
    this->subTotal = 0.0;
}

compra::~compra()
{

}
void compra::leerCompra(nodoProductos *eP){
    do{

        basicas::gotoxy(77,9);this->setCantidad(basicas::leerEntero("Ingrese Cantidad:"));
        if(this->cantidad > eP->getPro()->getStock()){
            basicas::gotoxy(65,9); cout<<" NO SE ENCUENTRA STOCK SUFICIENTE";
            Sleep(2000);
            basicas::gotoxy(65, 9); cout << "                                               ";
            basicas::gotoxy(66,8); cout << "                    ";
        }
    }while(this->cantidad > eP->getPro()->getStock());
}
