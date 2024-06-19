#include <iostream>
#include <ctime>
using namespace std;
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
void menu();

void menu(){
    int opcion;
    string nombre;
    
    
    while(true){
        system("cls");
        if(nombre != ""){
            cout << "Hola " << nombre << endl;
        }
        
        cout << "1- Cargar Nombre" << endl;
        cout << "2- Jugar solo " << endl;
        cout << "3- Jugar doble " << endl;
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
            jugarJuego();
            break;
        case 0:
            return;
        }  
    }
}
#endif  MENU_H_INCLUDED