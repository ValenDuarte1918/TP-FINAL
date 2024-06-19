#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#include "./Funciones.h"
#include "./menu.h"

int main() {
    menu();
    srand(time(0));  // Inicializar el generador de números aleatorios
    int puntajeTotal = 0;
    int rondas = 0;
    while (puntajeTotal < 100) {
        cout << "Ronda " << rondas + 1 << ":\n";
        jugarRonda(puntajeTotal);
        rondas++;
    }
    cout << "¡Ganaste la partida en " << rondas << " rondas!\n";
system("pause");
    return 0;
}