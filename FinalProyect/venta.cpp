#include "venta.h"
#include "compra.h"
#include <iostream>
using namespace std;


string venta::getCodigo() const
{
    return codigo;
}

void venta::setCodigo(const string &value)
{
    codigo = value;
}

string venta::getFecha() const
{
    return fecha;
}

void venta::setFecha(const string &value)
{
    fecha = value;
}

string venta::getHora() const
{
    return hora;
}

void venta::setHora(const string &value)
{
    hora = value;
}

clientes *venta::getClie() const
{
    return clie;
}

void venta::setClie(clientes *value)
{
    clie = value;
}

Trabajadores *venta::getTra() const
{
    return tra;
}

void venta::setTra(Trabajadores *value)
{
    tra = value;
}

float venta::getDineroDado() const
{
    return dineroDado;
}

void venta::setDineroDado(float value)
{
    dineroDado = value;
}

float venta::getMontoTotal() const
{
    return montoTotal;
}

void venta::setMontoTotal(float value)
{
    montoTotal = value;
}

listaCompras *venta::getLCom() const
{
    return lCom;
}

void venta::setLCom(listaCompras *value)
{
    lCom = value;
}

listaProductos *venta::getLPro() const
{
    return lPro;
}

void venta::setLPro(listaProductos *value)
{
    lPro = value;
}
venta::venta()
{
    this->dineroDado = 0.0;
    this->montoTotal = 0.0;
    this->lCom = new listaCompras();
    this->lPro = new listaProductos();
}

venta::~venta()
{

}


float venta::calcularVuelto() {
    float vuelto;
    if (this->getDineroDado() >= this->getMontoTotal()) {
        vuelto = this->getDineroDado() - this->getMontoTotal();
        return vuelto;
    } else {
        // Si el dineroDado es menor al montoTotal, el cambio es 0
        return 0.0;
    }
}

void venta::boletaFinal(){
    system("cls");

    // Encabezado
    basicas::gotoxy(30, 2); cout << "-------------------------";
    basicas::gotoxy(30, 3); cout << "|    BOLETA DE VENTA    |";
    basicas::gotoxy(30, 4); cout << "-------------------------";

    //Datos de la venta
    basicas::gotoxy(30, 6); cout << "Codigo de Venta: " << this->getCodigo();
    basicas::gotoxy(30, 7); cout << "Fecha: " << this->getFecha();
    basicas::gotoxy(50, 7); cout << "Hora: " << this->getHora();
    basicas::gotoxy(30, 8); cout << "Cliente: " << this->getClie()->getNombre();
    basicas::gotoxy(30, 9); cout << "Trabajador Responsable: " << this->getTra()->getNombre();

    //Datos de las compras
    int x = 14;
    nodoCompra *aux = this->getLCom()->getCab();

    // Encabezado de la sección de productos comprados
    basicas::gotoxy(30, 10); cout << "-------------------------";
    basicas::gotoxy(30, 11); cout << "| Productos comprados   |";
    basicas::gotoxy(30, 12); cout << "-------------------------";

    // Encabezados de la tabla
    basicas::gotoxy(30, 13); cout << "Producto";
    basicas::gotoxy(45, 13); cout << "Cantidad";
    basicas::gotoxy(55, 13); cout << "Precio Unitario";

    // Detalles de la tabla
    while (aux != NULL) {
        basicas::gotoxy(30, x); cout << aux->getCom()->getProd()->getNombre();
        basicas::gotoxy(49, x); cout << aux->getCom()->getCantidad();
        basicas::gotoxy(60, x); cout << aux->getCom()->getProd()->getPrecio();
        x++;
        aux = aux->getSgnte();
    }

    // Monto total, dinero dado y vuelto
        float vuelto = calcularVuelto();
    basicas::gotoxy(30, x + 2); cout << "-------------------------";
    basicas::gotoxy(30, x + 3); cout << "| Monto Total: " << this->getMontoTotal();
    basicas::gotoxy(30, x + 4); cout << "| Dinero Dado: " << this->getDineroDado();
    basicas::gotoxy(30, x + 5); cout << "| Vuelto: " << vuelto;
    basicas::gotoxy(30, x + 6); cout << "-------------------------";

    // Línea inferior de la boleta
    basicas::gotoxy(30, x + 8); cout << "|   Gracias por su compra   |"<<endl<<endl;
    system("pause");
}

void venta::generarBoleta() {
    system("cls");
    basicas::gotoxy(30, 2);cout << "---- COMPRAS REALIZADAS ----";
    nodoCompra *aux = this->getLCom()->getCab();
    int x = 0;
    float montoTotal = 0.0;
    while (aux != NULL) {
        float subtotal = aux->getCom()->getCantidad() * aux->getCom()->getProd()->getPrecio();
        montoTotal += subtotal;
        this->setMontoTotal(montoTotal);
        basicas::gotoxy(30, 4 + x );cout << "Producto: " << aux->getCom()->getProd()->getNombre();
        basicas::gotoxy(30, 5 + x );cout << "Cantidad: " << aux->getCom()->getCantidad();
        basicas::gotoxy(30, 6 + x );cout << "Precio unitario: " << "S/. "<< aux->getCom()->getProd()->getPrecio();
        basicas::gotoxy(30, 7 + x );cout << "Subtotal: " << "S/. "<< subtotal;
        basicas::gotoxy(30, 8 + x );cout << "-----------------------------";
        x = x + 5;
        aux = aux->getSgnte();
    }
    basicas::gotoxy(30, 10 + x);cout << "MONTO TOTAL DE LA VENTA: " << "S/. "<< this->getMontoTotal();
    basicas::gotoxy(30, 11 + x);cout << "-----------------------------" << endl;
    do{
                basicas::gotoxy(30,13 + x); this->setDineroDado(basicas::leerFloat("Ingrese dinero a pagar:"));
                if (this->getDineroDado() < this->getMontoTotal()) {
                    basicas::gotoxy(30,14 + x);cout << "El monto dado es menor al monto total. Por favor, ingrese mas dinero.";
                    Sleep(1000);
                    basicas::gotoxy(30, 14 + x); cout << "                                                                    ";
                    basicas::gotoxy(30,13 + x); cout << "                                   ";
                }
            }while(this->getDineroDado() < this->getMontoTotal());
}

void venta::leerVenta(){
    system("cls");
    nodoProductos *eP = new nodoProductos();
    this->getLPro()->recuperarProductos();
    basicas::gotoxy(2,2); cout << "CLIENTE: "<<this->getClie()->getNombre();
    basicas::gotoxy(2,3); cout << "ENCARGADO: "<<this->getTra()->getNombre();
    basicas::gotoxy(60, 2); this->setCodigo(basicas::leerTexto("Codigo: "));
    basicas::gotoxy(80, 2); this->setFecha(basicas::leerTexto("Fecha: "));
    basicas::gotoxy(100, 2); this->setHora(basicas::leerTexto("Hora: "));
    string rpta;
    do{
        system("cls");
                basicas::gotoxy(60,2);cout << "Codigo: "<<this->getCodigo();
                basicas::gotoxy(80,2);cout << "Fecha: "<<this->getFecha();
                basicas::gotoxy(100,2);cout <<"Hora: "<<this->getHora();
         compra *com = new compra();
         eP = this->getLPro()->elegirProductos();
         while (!this->getLPro()->verificarStockSuficiente(eP)) {
                 basicas::gotoxy(2,21);cout << "" << endl;
                 system("pause");
                 eP = this->getLPro()->elegirProductos();
             }
         com->setProd(eP->getPro());
         com->leerCompra(eP);
         int redStock = com->getProd()->getStock() - com->getCantidad();
         com->getProd()->setStock(redStock);
         this->getLPro()->actualizarStockArchivo();
         this->getLCom()->insertarCompra(com);
         basicas::gotoxy(77,11);cout<<"Desea seguir comprando?  (S) o (N): ";
         cin >>rpta;
    }while(!(rpta == "N"));
    this->generarBoleta();
}
