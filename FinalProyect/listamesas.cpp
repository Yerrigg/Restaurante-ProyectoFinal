#include "listamesas.h"
#include "basicas.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
using namespace std;
const string nombreArchivoMesa = "..\\Mesas.txt";
const char limite = '_';
nodoMesas *listaMesas::getCab() const
{
    return cab;
}

void listaMesas::setCab(nodoMesas *value)
{
    cab = value;
}

unsigned short listaMesas::getNMesa() const
{
    return nMesa;
}

void listaMesas::setNMesa(unsigned short value)
{
    nMesa = value;
}
listaMesas::listaMesas()
{
    this->cab = NULL;
    this->nMesa = 0;
}

listaMesas::~listaMesas()
{

}

void listaMesas::registrarMesa(){
    system("cls");
    mesa *mes = new mesa();
    do {
        mes->leerMesa();
        if (idExistente(mes->getId())) {
            basicas::gotoxy(25, 14);
            cout << "Error: La ID ya esta registrada. ";
            basicas::gotoxy(25, 15);
            cout<< "Ingrese una ID diferente.\n";
            system("pause");
        }
    } while (idExistente(mes->getId()));

    this->insertarMesa(mes);
    this->guardarArchivoM(mes);

    basicas::gotoxy(25, 14);
    cout << "La mesa se ha registrado correctamente.\n";
    Sleep(1000);
}
void listaMesas::insertarMesa(mesa *mes){
    nodoMesas *aux = new nodoMesas();
    nodoMesas*temp = new nodoMesas();
    temp->setMes(mes);
    temp->setSgnte(NULL);
    if(this->cab == NULL){
        this->setCab( temp);
    }else{
        aux = this->cab;
        while(aux->getSgnte() != NULL){
            aux = aux->getSgnte();
        }
        aux->setSgnte(temp);
    }
    this->nMesa++;
}
void listaMesas::mostrarMesas(mesa *mes, int x){
    basicas::gotoxy(30, 5+x); cout << mes->getId();
    basicas::gotoxy(45, 5 + x); cout << mes->getMaxComensales();
    basicas::gotoxy(65, 5+x);
    if(mes->getOcupada())
        cout << "OCUPADO";
    else
        cout << "DESOCUPADO";
}

void listaMesas::encabezadoMes(){
    basicas::gotoxy(30, 3); cout << "ID MESA";
    basicas::gotoxy(45, 3); cout << "COMENSALES MAX";
    basicas::gotoxy(65, 3); cout << "ESTADO";


    basicas::gotoxy(30, 4); cout << "===========================================";
}

void listaMesas::listarMesas(){
    system("cls");
    if ( this->nMesa == 0) {
        system("cls");
        basicas::gotoxy(40, 10); cout << "No hay mesas registradas!";
        cin.ignore().get();
        return;
    }

    nodoMesas *aux = new nodoMesas;
    int x = 1;
    aux = this->cab;
    encabezadoMes();
    while (aux != NULL) {
        mostrarMesas( aux->getMes(), x);
        x++;
        aux = aux->getSgnte();
    }
    cout<<endl;
    cin.ignore().get();
}
bool listaMesas::idExistente(int id) const {
    nodoMesas *aux = cab;
    while (aux != NULL) {
        if (aux->getMes()->getId() == id) {
            return true;
        }
        aux = aux->getSgnte();
    }
    return false;
}
void listaMesas::recuperarMesas(){
    string linea;
    string id, ocupada , maxComensales;
    ifstream archivo(nombreArchivoMesa.c_str(), ios_base::in);
    while(getline(archivo,linea)){
        mesa *mes = new mesa();
         stringstream input_stringstream(linea);
         getline (input_stringstream, id, limite);
         int idInt;
         istringstream(id) >> idInt;
         getline (input_stringstream, maxComensales, limite);
          int maxComensalesInt;
          istringstream(maxComensales) >> maxComensalesInt;
         getline(input_stringstream, ocupada, limite);
          bool ocupadaBool = (ocupada == "Ocupado");
          if (ocupada != "Desocupado" && ocupada != "Ocupado") {
                      ocupadaBool = true;
                  }
         mes->setId(idInt);
         mes->setMaxComensales(maxComensalesInt);
         mes->setOcupada(ocupadaBool);
         this->insertarMesa(mes);
    }
    archivo.close();
}
void listaMesas::guardarArchivoM(mesa *mes) {
    ofstream archivo;
    archivo.open(nombreArchivoMesa.c_str(), ios_base::app | ios_base::out);
    if (archivo.is_open()) {
        archivo << mes->getId() << limite
                << mes->getMaxComensales() << limite;
        if (mes->getOcupada()) {
            archivo << "Ocupado" << endl;
        } else {
            archivo << "Desocupado" << endl;
        }
        archivo.close();
    }
}
nodoMesas *listaMesas::elegirMesa()
{
    system("cls");
    if (this->getCab() == NULL) {
        basicas::gotoxy(30, 6);
        cout << "No hay mesas en la lista";
        Sleep(1500);
        return NULL;
    }
    nodoMesas* aux = this->getCab();
    int x = 1;
    while(aux != NULL){
        basicas::gotoxy(2,1);cout <<"|| SELECCIONAR MESA ||";

        basicas::gotoxy(2,2); cout << "-----------------------------------------------" << endl;
        basicas::gotoxy(2,4 + x);
        cout << "Id " << aux->getMes()->getId()
             << " - Capacidad  " << aux->getMes()->getMaxComensales()
             << " - Estado " << (aux->getMes()->getOcupada() ? "Ocupado" : "Desocupado");
        x++;
        aux = aux->getSgnte();
    }
    int opcion;
    do {
        basicas::gotoxy(2, 6 + x);
        cout << "Elige un mesa: ";
        cin >> opcion;
    } while (opcion < 1 || opcion >= x);
    aux = this->getCab();
    for (int i = 1; i < opcion; i++) {
        aux = aux->getSgnte();
    }
    return aux;
}



