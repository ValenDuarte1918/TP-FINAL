#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu(){
    int opcion;
    string nombre, nombre2;
    bool modoSimulado = false;
    while(true){
        system("cls");
        if(nombre != ""){
            cout << "Hola " << nombre << endl;
        }

        cout << "1- Cargar Nombre" << endl;
        cout << "2- Jugar" << endl;
        cout << "3- Modo Simulado " << endl;
        cout << "4- Modo 2 Jugadores" << endl;
        cout << "5- Modo 2 Jugadores Simulado" << endl;
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
            jugarJuego(nombre, false);
            break;
        case 3:
                modoSimulado = true;
                jugarJuego(nombre, modoSimulado);
                break;
        case 4:
            cout << "Ingrese nombre del jugador 2: ";
            cin.ignore(); // ignora el enter del cin anterior
            getline(cin, nombre2);
            modo2jugadores(nombre, nombre2, false);
            break;
        case 5:
            cout << "Ingrese nombre del jugador 2: ";
            cin.ignore(); // ignora el enter del cin anterior
            getline(cin, nombre2);
            modoSimulado = true;
            modo2jugadores(nombre, nombre2, modoSimulado);
            break;
        case 0:
            return;
        }  
    }
}
#endif // MENU_H_INCLUDED