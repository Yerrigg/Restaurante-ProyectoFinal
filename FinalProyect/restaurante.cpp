#include "restaurante.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;


string restaurante::getNombre() const
{
    return nombre;
}

void restaurante::setNombre(const string &value)
{
    nombre = value;
}

string restaurante::getDireccion() const
{
    return direccion;
}

void restaurante::setDireccion(const string &value)
{
    direccion = value;
}

string restaurante::getNumTel() const
{
    return numTel;
}

void restaurante::setNumTel(const string &value)
{
    numTel = value;
}

listaTrabajadores *restaurante::getLT() const
{
    return lT;
}

void restaurante::setLT(listaTrabajadores *value)
{
    lT = value;
}

listaClientes *restaurante::getLC() const
{
    return lC;
}

void restaurante::setLC(listaClientes *value)
{
    lC = value;
}

listaMesas *restaurante::getLMes() const
{
    return lMes;
}

void restaurante::setLMes(listaMesas *value)
{
    lMes = value;
}

listaProductos *restaurante::getLPr() const
{
    return lPr;
}

void restaurante::setLPr(listaProductos *value)
{
    lPr = value;
}

listaVentas *restaurante::getLVen() const
{
    return lVen;
}

void restaurante::setLVen(listaVentas *value)
{
    lVen = value;
}
restaurante::restaurante()
{
    this->nombre = "PaComer";
    this->numTel = "931322946";
    this->RUC = "122536859641";
    this->direccion = "Av. Las brisas #3321";
    this->lC = new listaClientes();
    this->lT = new listaTrabajadores();
    this->lMes = new listaMesas();
    this->lPr= new listaProductos();
    this->lVen = new listaVentas();
}

restaurante::~restaurante()
{

}

//menuGestor deTrabajador
void restaurante::gestionTrabajadores(){
    unsigned short opc;
    do{
        opc = basicas::menuTrabajadores(40,10);
        switch(opc){
        case 1: this->getLT()->registrarTrabajador();break;
        case 2: this->getLT()->listarTrabajadores();break;
        }
    }while(!(opc == 3));
}

//MenuGestor de Clientes:
void restaurante::gestionClientes(){
    unsigned short opc;
    do{
        opc = basicas::menuClientes(40,10);
        switch(opc){
        case 1: this->getLC()->registrarClientes();break;
        case 2: this->getLC()->listarClientes();break;
        }
    }while(!(opc == 3));
}
//Menu Gestor de Mesas:
void restaurante::gestionarMesas(){
    unsigned short opc;
    do{
        opc = basicas::menuMesas(47,9);
        switch(opc){
        case 1:this->getLMes()->registrarMesa();break;
        case 2:this->getLMes()->listarMesas(); break;
        }
    }while(!(opc == 3));
}
//______productos
void restaurante::gestionarProductos(){
    unsigned short opc;
    do{
        opc = basicas::menuProductos(47,9);
        switch(opc){
        case 1:this->getLPr()->registrarProducto();break;
        case 2:this->getLPr()->listarProductos();break;
        }
    }while(!(opc == 3));
}
void restaurante::gestionarVentas(){
    unsigned short opc;
    do{
        opc = basicas::menuVentas(47,9);
        switch(opc){
        case 1:this->registrarVenta();break;
        case 2:this->getLVen()->imprimirBoleta(); break;
        }
    }while(!(opc == 3));
}

void restaurante::gestionarReportes(){
    unsigned short opc;
    do{
        opc = basicas::menuReportes(47,9);
        switch(opc){
        case 1:this->getLVen()->buscarVentasPorFecha();break;
        case 2:this->listarVentasT(); break;
        }
    }while(!(opc == 3));
}

//_______________________________________

void restaurante::control(){
    int opc;
    this->getLT()->recuperarTrabajadores();
    this->getLMes()->recuperarMesas();
    this->getLPr()->recuperarProductos();
    do{
        opc = basicas::menu(47,9);
        switch(opc){
        case 1: this->gestionTrabajadores(); break;
        case 2: this->gestionClientes();break;
        case 3: this->gestionarMesas();break;
        case 4: this->gestionarProductos();break;
        case 5: this->gestionarVentas();break;
        case 6: this->gestionarReportes();break;
        }
    }while(!(opc == 7));
}

//_______________________________________
void restaurante::  registrarVenta(){
    nodoClientes *eC = new nodoClientes();
    nodoMesas *eM = new nodoMesas();
    nodoTrabajadores *eT = new nodoTrabajadores();
   if(this->getLC()->getCab() == NULL){
       system("cls");
       basicas::gotoxy(30,7);cout<<"No tenemos clientes registrados, registre primero.";
       Sleep(1500);
       return;
   }
   eC = this->getLC()->elegirClientes();

   do{

       eM= this->getLMes()->elegirMesa();
       if (eM->getMes()->getOcupada() == true){
           system("cls");
                       basicas::gotoxy(25, 10);
                       cout << "ERROR__La mesa elegida esta ocupada. Por favor, elija otra mesa.";
                       Sleep(2000);
       }else if (eM->getMes()->getMaxComensales()  < eC->getClie()->getAcomp() + 1){
           system("cls");
                      basicas::gotoxy(25, 10);
                      cout << "ERROR__No se puede acceder a la mesa porque no hay suficiente espacio.";
                      Sleep(2000);
       }else {
           break;
       }
   }while(true);
   eT= this->getLT()->elegirTrabajadores();
   this->getLVen()->registrarVentas(eC,eT);
}


void restaurante::listarVentasT(){
    system("cls");
    nodoTrabajadores *temp = new nodoTrabajadores();
    nodoVenta *aux = new nodoVenta();
    int x = 0;
    bool ventasE = false;
    aux = this->getLVen()->getCab();
    if (this->getLT()->getCab() == NULL ){
        system("cls");
        basicas::gotoxy( 35, 10); cout << "No Hay Trabajadores Registrados";
        Sleep( 2000);
        return;
    }
    if(aux == NULL){
        system("cls");
        basicas::gotoxy(35, 10); cout << "No hay ventas registradas";
        Sleep(2000);
        return;
    }
    system("cls");
    temp = this->getLT()->elegirTrabajadores();
    system("cls");
    while (aux != NULL) {
        if (aux->getVen()->getTra() == temp->getTra()) {
            ventasE = true;
            basicas::gotoxy(2, 1 + x); cout << "Venta " ;
            basicas::gotoxy(2, 2 + x); cout << "-----------------";
            basicas::gotoxy(2, 3 + x); cout << "Codigo: " << aux->getVen()->getCodigo();
            basicas::gotoxy(2, 4 + x); cout << "Fecha: " << aux->getVen()->getFecha();
            basicas::gotoxy(2, 5 + x); cout << "Hora: " << aux->getVen()->getFecha();
            basicas::gotoxy(2, 6 + x); cout << "Cliente: " << aux->getVen()->getClie()->getNombre();
            basicas::gotoxy(2, 7 + x); cout << "Productos comprados: ";
            // Mostrar los productos comprados en esta venta
            nodoCompra *comAux = new nodoCompra;
            comAux = aux->getVen()->getLCom()->getCab();
            while (comAux != NULL) {
                basicas::gotoxy(2, 8 + x); cout << "- " << comAux->getCom()->getCantidad() << " x " << comAux->getCom()->getProd()->getNombre() << " (S/." << comAux->getCom()->getProd()->getPrecio() << ")";
                comAux = comAux->getSgnte();
                x++;
            }

            basicas::gotoxy(2, 8 + x); cout << "Monto Total: S/." << aux->getVen()->getMontoTotal();
            basicas::gotoxy(2, 9 + x); cout << "-----------------"<<endl;
            x += 10; // Incrementar el valor de x para dejar espacio entre ventas
        }
        aux = aux->getSgnte();
    }
    system("pause");
    if (!ventasE) {
        system("cls");
        basicas::gotoxy(35, 10); cout << "No se encontraron ventas asociadas al trabajador seleccionado";
        Sleep(2000);
    }else{
        Sleep(5000);
    }
}
