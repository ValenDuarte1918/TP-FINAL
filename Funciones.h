#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef FUNCIONES_H_INCLUDED

using namespace std;

// Función para lanzar dados y contar los valores obtenidos
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

// Función para introducir manualmente los valores de los dados y contarlos
void introducirDados(int dados[7]) {
    // Inicializa el array a cero
    for (int i = 0; i < 7; ++i) {
        dados[i] = 0;
    }
    // Introduce los valores manualmente y cuenta los valores
    cout << "Introduce los valores de los dados (6 valores): ";
    for (int i = 0; i < 6; i++) {
        int valor;
        cin >> valor;
        if (valor >= 1 && valor <= 6) {
            dados[valor]++;
        } else {
            cout << "Valor invalido. Introduce un valor entre 1 y 6.\n";
            --i;  // Permite reintroducir el valor
        }
    }
}

// Función para verificar si los dados forman una escalera
bool esEscalera(int dados[7]) {
    for (int i = 1; i <= 6; ++i) {
        if (dados[i] != 1) return false;
    }
    return true;
}

// Función para verificar si todos los dados son 6
bool esSexteto6(int dados[7]) {
    return dados[6] == 6;
}

// Función para verificar si todos los dados son iguales y calcular el puntaje correspondiente
int esSexteto(int dados[7]) {
    for (int i = 1; i <= 6; ++i) {
        if (dados[i] == 6) return i * 10;
    }
    return 0;
}

// Función para calcular el puntaje de una ronda
int calcularPuntaje(int dados[7]) {
    if (esEscalera(dados)) {
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

// Función para jugar una ronda del juego
int jugarRonda(int puntajeTotal, int ronda, string nombre, bool modoSimulado) {
    system("cls");
    int puntajeMaxRonda = 0;
    for (int i = 0; i < 3; ++i) {
        cout << "------------------------------------------------------------------\n";
        cout << "TURNO DE: " << nombre <<  " | RONDA N " << ronda + 1 << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS\n";
        cout << "------------------------------------------------------------------\n";
        cout << "LANZAMIENTO N " << i + 1 << "\n";
        cout << "MAXIMO PUNTAJE DE LA RONDA: " << puntajeMaxRonda << endl;
        cout << "------------------------------------------------------------------\n";

        int dados[7] = {0};  // Array para contar la cantidad de cada valor de dado
        if (modoSimulado) {
            introducirDados(dados);
        } else {
            lanzarDados(dados);
        }
        cout << "TUS LANZAMIENTOS: ";
        for (int j = 1; j <= 6; ++j) { 
            for (int k = 0; k < dados[j]; ++k) { 
                cout << j << " ";
            }
        }
        cout << endl;

        int puntaje = calcularPuntaje(dados);
        if (puntaje == -1) {  // Escalera
            cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!\n";
            return 100;  
        } else if (puntaje == 0) { // Sexteto de 6
            return puntajeTotal = 0;
        } 
        
        cout << "TU PUNTAJE EN ESTE LANZAMIENTO: " << puntaje << endl;

    // Actualiza el puntaje máximo de la ronda
        if (puntaje > puntajeMaxRonda) { // Si el puntaje actual es mayor al máximo de la ronda
            puntajeMaxRonda = puntaje;
        }

        // Pausa antes de continuar con el próximo lanzamiento
        cout << "Presiona Enter para lanzar...\n";
        cin.ignore();
        cin.get();
  
    }
    puntajeTotal += puntajeMaxRonda;
    cout << "------------------------------------------------------------------\n";
    cout << "PUNTAJE TOTAL ACUMULADO: " << puntajeTotal <<  endl;
    cout << "------------------------------------------------------------------\n";
    cout << "Presiona Enter para continuar a la siguiente ronda...\n";
    cin.ignore();
    cin.get();
    return puntajeTotal;
}



void jugarJuego(string nombre, bool modoSimulado) {
    int puntajeTotal = 0;
    int rondas = 0;
    while (puntajeTotal < 100) {
        puntajeTotal= jugarRonda(puntajeTotal, rondas, nombre, modoSimulado);
        rondas++;
    }
    cout << "¡Ganaste la partida en " << rondas << " rondas!\n";
    system("pause");
}
void modo2jugadores(string nombre1, string nombre2, bool modoSimulado) {
    int puntajeTotal1 = 0, puntajeTotal2 = 0;
    int rondas = 0;

    while (puntajeTotal1 < 100 && puntajeTotal2 < 100) {
        puntajeTotal1 = jugarRonda(puntajeTotal1, rondas, nombre1, modoSimulado);
        if (puntajeTotal1 >= 100) {
            cout << "¡" << nombre1 << " ganó la partida en " << rondas + 1 << " rondas!\n";
            break;
        }

        puntajeTotal2 = jugarRonda(puntajeTotal2, rondas, nombre2, modoSimulado);
        if (puntajeTotal2 >= 100) {
            cout << "¡" << nombre2 << " ganó la partida en " << rondas + 1 << " rondas!\n";
            break;
        }

        rondas++;
    }

    // Omitir system("pause") para mejorar la portabilidad y seguridad
    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
}

#endif // FUNCIONES_H_INCLUDED