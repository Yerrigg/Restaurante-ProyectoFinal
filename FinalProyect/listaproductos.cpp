#include "listaproductos.h"
#include "basicas.h"
#include <sstream>
#include <fstream>
#include <string.h>
const string nombreArchivoPro = "..\\Productos.txt";
const char limite = '_';

int listaProductos::getNPro() const
{
    return nPro;
}

void listaProductos::setNPro(int value)
{
    nPro = value;
}

nodoProductos *listaProductos::getCab() const
{
    return cab;
}

void listaProductos::setCab(nodoProductos *value)
{
    cab = value;
}
listaProductos::listaProductos()
{
    this->cab = NULL;
    this->nPro = 0;
}

listaProductos::~listaProductos()
{

}
void listaProductos::registrarProducto(){
    system("cls");
    productos *pro = new productos();
    pro->leerProducto();
    this->insertarProducto(pro);
    this->guardarProductosArchivo(pro);
    basicas::gotoxy(35,14); cout<<"El producto se ha registrado correctamente \n.";
    Sleep(1000);
}
void listaProductos::insertarProducto(productos *pro){
    nodoProductos *aux = new nodoProductos();
    nodoProductos *temp = new nodoProductos();
    temp->setPro(pro);
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
    this->nPro++;
}
void listaProductos::mostrarProductos(productos *pro, int x){
    basicas::gotoxy(5, 5+x); cout << pro->getNombre();
    basicas::gotoxy(35, 5 + x); cout << pro->getCategoria();
    basicas::gotoxy(50, 5+x); cout << pro->getPrecio();
    basicas::gotoxy(65, 5+x); cout << pro->getStock();
}

void listaProductos::encabezadoPro(){
    basicas::gotoxy(5, 4); cout << "PLATO";
    basicas::gotoxy(35, 4); cout << "CATEGORIA";
    basicas::gotoxy(50, 4); cout << "PRECIO";
    basicas::gotoxy(65, 4); cout << "STOCK";
    basicas::gotoxy(5, 5); cout << "==================================================================";
}

void listaProductos::listarProductos(){
    system("cls");
    if ( this->nPro == 0) {
        system("cls");
        basicas::gotoxy(40, 10); cout << "No hay productos registradas!";
        cin.ignore().get();
        return;
    }

    nodoProductos *aux = new nodoProductos;
    int x = 1;
    aux = this->cab;
    encabezadoPro();
    while (aux != NULL) {
        mostrarProductos( aux->getPro(), x);
        x++;
        aux = aux->getSgnte();
    }
    cout<<endl;
    cin.ignore().get();

}


void listaProductos::recuperarProductos() {
    string linea;
    string nombre, categoria, precio, stock;
    ifstream archivo(nombreArchivoPro.c_str(), ios_base::in);
    while(getline(archivo,linea)){
        productos *pro = new productos();
         stringstream input_stringstream(linea);
         getline (input_stringstream, nombre, limite);
         getline (input_stringstream, categoria, limite);
         getline (input_stringstream, precio, limite);
         getline (input_stringstream, stock, limite);
         int stockint;
         istringstream(stock) >> stockint;
        pro->setNombre(nombre);
        pro->setCategoria(categoria);
        pro->setPrecio(strtof(precio.c_str(),NULL));
        pro->setStock(stockint);
         this->insertarProducto(pro);
    }
    archivo.close();
}
void listaProductos:: guardarProductosArchivo(productos *pro){
    ofstream archivo;
    archivo.open(nombreArchivoPro.c_str(), ios_base :: app | ios_base::out);
    if (archivo.is_open()){
        archivo <<pro->getNombre()<< limite
                    <<pro->getCategoria()<< limite
                    <<pro->getPrecio()<< limite
                    <<pro->getStock()<< endl;
        archivo.close();
    }
}

void listaProductos::actualizarStockArchivo() {
    ofstream archivo(nombreArchivoPro.c_str(), ios_base::trunc);
    if (archivo.is_open()) {
        nodoProductos *aux = cab;
        while (aux != NULL) {
            archivo << aux->getPro()->getNombre() << limite
                    << aux->getPro()->getCategoria() << limite
                    << aux->getPro()->getPrecio() << limite
                    << aux->getPro()->getStock() << limite << endl;
            aux = aux->getSgnte();
        }
        archivo.close();
        archivo.open(nombreArchivoPro.c_str(), ios_base::app | ios_base::out);
    }
}

nodoProductos *listaProductos::elegirProductos(){   
    if (this->getCab() == NULL) {
        basicas::gotoxy(30, 6);
        cout << "No hay Productos en la lista";
        Sleep(1500);
        return NULL;
    }
    nodoProductos* aux = this->getCab();
    int x = 1;
    while(aux != NULL){
        basicas::gotoxy(2,1);cout << "PRODUCTOS DEL DIA "<<endl;
        cout<<"__________________________________________-";
        encabezadoPro();
        basicas::gotoxy(5, 5+x); cout << x << " > "<<aux->getPro()->getNombre();
        basicas::gotoxy(35, 5 + x); cout << aux->getPro()->getCategoria();
        basicas::gotoxy(50, 5+x); cout << "S/. " << aux->getPro()->getPrecio();
        basicas::gotoxy(65, 5+x); cout << aux->getPro()->getStock();
        //basicas::gotoxy(2,3 + x);cout << x << " > "<<aux->getPro()->getCategoria()<<" //"<<aux->getPro()->getNombre()<<"// Precio: "<<aux->getPro()->getPrecio()<<" Stock: "<<aux->getPro()->getStock();
        x++;
        aux = aux->getSgnte();
    }
    int opcion;
    do {
        basicas::gotoxy(2, 9 + x);
        cout << "Elige un producto: ";
        cin >> opcion;
    } while (opcion < 1 || opcion >= x);
    aux = this->getCab();
    for (int i = 1; i < opcion; i++) {
        aux = aux->getSgnte();
    }
    return aux;
}

bool listaProductos::verificarStockSuficiente(nodoProductos *producto) {
    if (producto != NULL) {
        if (producto->getPro()->getStock() > 0) {
            return true;
        } else {
            basicas::gotoxy(2,20);cout << "No hay suficiente stock para el producto seleccionado." << endl;
            return false;
        }
    }
    return false;
}

