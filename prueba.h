void jugarRonda(int& puntajeTotal, int ronda) {
    int puntajeMaxRonda = 0;
    for (int i = 0; i < 3; ++i) {
        cout << "------------------------------------------------------------------\n";
        cout << "TURNO DE MARTA | RONDA N° " << ronda + 1 << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS\n";
        cout << "------------------------------------------------------------------\n";
        cout << "LANZAMIENTO N° " << i + 1 << "\n";
        cout << "------------------------------------------------------------------\n";

        cout << "Presiona Enter para lanzar los dados en el lanzamiento " << i + 1 << "...\n";
        cin.ignore();

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
            cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!\n";
            return;
        }

        cout << "Tu puntaje en este lanzamiento: " << puntaje << endl;

        if (puntaje > puntajeMaxRonda) {
            puntajeMaxRonda = puntaje;
        }
    }
    puntajeTotal += puntajeMaxRonda;
    cout << "------------------------------------------------------------------\n";
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << puntajeMaxRonda << endl;
    cout << "PUNTAJE TOTAL ACUMULADO: " << puntajeTotal <<  endl;
    cout << "------------------------------------------------------------------\n";
}

void jugarJuego() {
    int puntajeTotal = 0;
    int rondas = 0;
    while (puntajeTotal < 100) {
        jugarRonda(puntajeTotal);
        rondas++;
    }
    cout << "¡Ganaste la partida en " << rondas << " rondas!\n";
    system("pause");
}