#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

void lanzarDados(int dados[7]) {
    // Inicializa el array a cero
    for (int i = 0; i < 7; ++i) {
        dados[i] = 0;
    }
    // Lanza los dados y cuenta los valores
    for (int i = 0; i < 6; ++i) {
        int valor = rand() % 6 + 1;
        dados[valor]++;
    }
}

bool esEscalera(int dados[7]) {
    for (int i = 1; i <= 6; ++i) {
        if (dados[i] != 1) return false;
    }
    return true;
}

bool esSexteto6(int dados[7]) {
    return dados[6] == 6;
}

int esSexteto(int dados[7]) {
    for (int i = 1; i <= 6; ++i) {
        if (dados[i] == 6) return i * 10;
    }
    return 0;
}

int calcularPuntaje(int dados[7]) {
    if (esEscalera(dados)) {
        cout << "¡Escalera! Ganas la partida.\n";
        return -1;  // Indicador de que se ganó la partida
    }
    if (esSexteto6(dados)) {
        cout << "¡Sexteto de 6! Puntaje total reseteado a 0.\n";
        return 0;
    }
    int sextetoPuntos = esSexteto(dados);
    if (sextetoPuntos) {
        return sextetoPuntos;
    }
    int suma = 0;
    for (int i = 1; i <= 6; ++i) {
        suma += i * dados[i];
    }
    return suma;
}

void jugarRonda(int& puntajeTotal) {
    int puntajeMaxRonda = 0;
    for (int i = 0; i < 3; ++i) {
        cout << "Presiona Enter para lanzar los dados en el lanzamiento " << i + 1 << "...\n";
        cin.ignore(); // Limpiar el buffer de entrada
        int dados[7] = {0};  // Array para contar la cantidad de cada valor de dado
        lanzarDados(dados);
        cout << "Tus lanzamientos: ";
        for (int j = 1; j <= 6; ++j) {
            for (int k = 0; k < dados[j]; ++k) {
                cout << j << " ";
            }
        }
        cout << endl;

        int puntaje = calcularPuntaje(dados);
        if (puntaje == -1) {
            puntajeTotal = 100;  // Indicador de que se ganó la partida
            return;
        }

        cout << "Tu puntaje en este lanzamiento: " << puntaje << endl;

        if (puntaje > puntajeMaxRonda) {
            puntajeMaxRonda = puntaje;
        }
    }
    puntajeTotal += puntajeMaxRonda;
    cout << "Puntaje máximo de la ronda: " << puntajeMaxRonda << endl;
    cout << "Puntaje total acumulado: " << puntajeTotal << endl;
}
void jugarJuego(){
    int puntajeTotal = 0;
    int rondas = 0;
    while (puntajeTotal < 100) {
        cout << "Ronda " << rondas + 1 << ":\n";
        jugarRonda(puntajeTotal);
        rondas++;
    }
    cout << "¡Ganaste la partida en " << rondas << " rondas!\n";
    system("pause");
}

#endif FUNCIONES_H_INCLUDED