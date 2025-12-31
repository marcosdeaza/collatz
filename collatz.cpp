//Tarea 2, 11/12/25, cjtra Collatz

#include <iostream>
using namespace std;

int main() {
    int numero;

    // 1. Pedir numero
    cout << "Introduce un numero entero positivo: ";
    cin >> numero;

    while (numero <= 0) {
        cout << "Te he dicho positivo (>0): ";
        cin >> numero;
    }

    // Usamos un array estático grande.
    // Suponemos que la secuencia no tendrá más de 1000 pasos
    int lista[1000]; 
    int cantidad = 0; // Cantidad de iteraciones

    // Guardamos el primero
    lista[cantidad] = numero;
    cantidad++; 
    
    int iteraciones = 0;

    // 2. El bucle while para calcular la secuencia
    while (numero != 1) {
        // Comprobamos si nos hemos pasado del tamaño del array para que no pete
        if (cantidad >= 1000) {
            cout << "La secuencia es demasiado larga para mi array :(" << endl;
            break;
        }

        if (numero % 2 == 0) {
            numero = numero / 2;
        } else {
            numero = 3 * numero + 1;
        }

        // Guardamos en la siguiente posición y movemos el contador
        lista[cantidad] = numero;
        cantidad++;
        
        iteraciones++;
    }

    // 3. Resultados
    cout << "Iteraciones totales: " << iteraciones << endl;
    cout << "Los ultimos 5 numeros: ";

    // Calculamos desde dónde empezar a imprimir.
    // 'cantidad' es el total de números guardados.
    // Queremos empezar en (total - 5).
    int inicio = cantidad - 5;

    // Si hay menos de 5 números (ej: se le pone un 2), empezamos desde el 0 para no romperlo
    if (inicio < 0) {
        inicio = 0;
    }

    // Imprimimos desde 'inicio' hasta 'cantidad'
    for (int i = inicio; i < cantidad; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;

}
