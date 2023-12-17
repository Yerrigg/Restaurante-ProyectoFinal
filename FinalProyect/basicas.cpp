#include "basicas.h"
#include "basicas.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
basicas::basicas()
{

}

basicas::~basicas()
{

}
void basicas::imprimirPantalla(){
    system("cls");
    gotoxy(25, 3); cout << (char)201;
    for(int i =0 ; i <=60; i++){
        cout << (char)205;
    }
    cout << (char)187 << "\n";
    gotoxy(51, 4); cout << ". . .-. .-. ";
    gotoxy(51, 5); cout << "| | `-. `-. ";
    gotoxy(51, 6); cout << "`-' `-' `-' ";
    gotoxy(35, 7); cout << "|R E S T A U R A N T E - P A C O M E R|";
    for(int i = 3; i <= 18; i++){
        cout << "\n";
        if (i==7){
            gotoxy(0,i+1);
            gotoxy(25,8);cout << (char)204;
            for(int j = 0; j <= 60; j++){
               cout << (char)205;
            }
            cout << (char)185;
            continue;
        }
        gotoxy(25,i+1); cout << (char)186;
        gotoxy(87,i+1); cout << (char)186;
    }
    cout << "\n";
    gotoxy(25,20);cout << (char)200;
    for(int i =0; i <=60; i++){
       cout << (char)205;
    }
    cout << (char)188 << "\n";
}

void basicas::imprimirPantalla2(){
    system("cls");
    cout << (char)201;
    for(int i = 0; i <= 78; i++){
        cout << (char)205;
    }
    cout << (char)187 << "\n";
    for(int i = 0; i <= 18; i++){
        cout << "\n";
        if (i==1){
            gotoxy(0,i+1);
            cout << (char)204;
            for(int j = 0; j <= 78; j++){
                if (j==19) {cout << (char)203; continue;}
                cout << (char)205;
            }
            cout << (char)185;
            continue;
        }
        gotoxy(0,i+1); cout << (char)186;
        if (i>=2){gotoxy(20,i+1); cout << (char)186;}
        gotoxy(80,i+1); cout << (char)186;
    }
    cout << "\n";
    cout << (char)200;
    for(int i = 0; i <= 78; i++){
        if (i==19) {cout << (char)202; continue;}
        cout << (char)205;
    }
    cout << (char)188 << "\n";
}


//SUBMENUTRABAJADOR
int basicas::menuTrabajadores(int posX, int posY){
    int opc;
    system("cls");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "MENU TRABAJADORES";
    gotoxy(posX,posY++); cout << "1. Registrar trabajador";
    gotoxy(posX,posY++); cout << "2. Listar Trabajadores";
    gotoxy(posX,posY++); cout << "3. Regresar";
    do{
        gotoxy(posX,posY++) ; cout << "Elija una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <4));
    return opc;
}
//submenu Clientes
int basicas::menuClientes(int posX, int posY){
    int opc;
    system("cls");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "MENU CLIENTE";
    gotoxy(posX,posY++); cout << "1. Registrar Cliente";
    gotoxy(posX,posY++); cout << "2. Listar Clientes";
    gotoxy(posX,posY++); cout << "3. Regresar";
    do{
        gotoxy(posX,posY++) ; cout << "Elija una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <4));
    return opc;
}
//submenu mesas
int basicas::menuMesas(int posX, int posY){
    int opc;
    system("cls");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "MENU MESAS";
    gotoxy(posX,posY++); cout << "1. Registrar mesa";
    gotoxy(posX,posY++); cout << "2. Listar mesas";
    gotoxy(posX,posY++); cout << "3. Regresar";
    do{
        gotoxy(posX,posY++) ; cout << "Elija una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <4));
    return opc;
}
//________Productos
int basicas::menuProductos(int posX, int posY){
    int opc;
    system("cls");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "MENU PRODUCTOS";
    gotoxy(posX,posY++); cout << "1. Regristrar menu comida";
    gotoxy(posX,posY++); cout << "2. Listar menu comida";
    gotoxy(posX,posY++); cout << "3. Regresar";
    do{
        gotoxy(posX,posY++) ; cout << "Elija una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <4));
    return opc;
}
int basicas::menuVentas(int posX, int posY){
    int opc;
    system("cls");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "MENU VENTAS";
    gotoxy(posX,posY++); cout << "1. Registrar Venta";
    gotoxy(posX,posY++); cout << "2. Boleta";
    gotoxy(posX,posY++); cout << "3. Regresar";
    do{
        gotoxy(posX,posY++) ; cout << "Elija una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <4));
    return opc;
}

int basicas::menuReportes(int posX, int posY){
    int opc;
    system("cls");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "MENU REPORTES";
    gotoxy(posX,posY++); cout << "1. Ganancias de venta - fecha";
    gotoxy(posX,posY++); cout << "2. Listar Ventas";
    gotoxy(posX,posY++); cout << "3. Reporte de Ventas por Trabajador";
    gotoxy(posX,posY++); cout << "4. Stock de Productos";
    do{
        gotoxy(posX,posY++) ; cout << "Elija una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <5));
    return opc;
}

//__________________________________________---
//MenuPrincipal
int basicas::menu(int posX, int posY){
    int opc;
    system("cls");
    system("color F0");
    system("title PAF: APP RESTAURANTE");
    imprimirPantalla();
    gotoxy(posX,posY++); cout << "INICIO PRINCIPAL";
    gotoxy(posX,posY++); cout << "1. Gestion de trabajadores";
    gotoxy(posX,posY++); cout << "2. Registrar Cliente";
    gotoxy(posX,posY++); cout << "3. Gestion de mesas";
    gotoxy(posX,posY++); cout << "4. Productos del dia";
    gotoxy(posX,posY++); cout << "5. Proceso Venta";
    gotoxy(posX,posY++); cout << "6. Reportes";
    gotoxy(posX,posY++); cout << "7. Salir";
    do{
         gotoxy(posX,posY++) ; cout << "Eliga una opcion: ";
        cin >> opc;
    }while(!(opc>0 && opc <8));
    return opc;
}
//___________________
//LeerDatos
int basicas::leerEntero(string mensaje){
    int valor;
    do{
        cout << mensaje;
        cin >> valor;
    } while (!(valor < 10000));
    return valor;
}

string basicas::leerTexto(string mensaje){
    string valor;
    cout << mensaje;
    fflush(stdin);
    getline(cin,valor);
    return valor;
}
float basicas::leerFloat( string mensaje ){
    float valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor > 0 && valor < 100000 ));
    return valor;
}
bool basicas::leerEstado(string mensaje){
    string valor;
    do{
        cout << mensaje;
        fflush(stdin);
        getline(cin, valor);
    }while(!(valor =="O" || valor == "D"));
    if(valor == "O")
        return true;
    else
        return false;
}

//_____________--
//GOTOXY
void basicas::gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}
