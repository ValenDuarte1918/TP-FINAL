#include <iostream>
#include <ctime>
using namespace std;
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu(){
    int opcion;
    string nombre;
    bool modoSimulado = false;
    
    while(true){
        system("cls");
        if(nombre != ""){
            cout << "Hola " << nombre << endl;
        }
        
        cout << "1- Cargar Nombre" << endl;
        cout << "2- Jugar solo " << endl;
        cout << "3- Modo Simulado " << endl;
        cout << "0- Salir" << endl;
        cout << "----------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion){
        case 1:
            cout << "Ingrese nombre: ";
            cin.ignore(); /// ignora el enter del cin anterior
            getline(cin, nombre);
            break;
        case 2:
            jugarJuego(nombre, modoSimulado);
            break;
        case 3:
                modoSimulado = true;
                jugarJuego(nombre, modoSimulado);
                break;
        case 0:
            return;
        }  
    }
}
#endif // MENU_H_INCLUDED