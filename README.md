# Práctica: La Conjetura de Collatz (3n + 1)

Este repositorio contiene una solución sencilla en C++ para resolver el problema de la **Conjetura de Collatz**, implementada utilizando lógica básica y sin librerías externas (solo `iostream`).

## 📝 Enunciado del Problema

El programa debe cumplir los siguientes requisitos:

1.  **Pedir un número:** Solicitar al usuario un número entero positivo por pantalla.
2.  **Validación:** Si el usuario introduce un número negativo o 0, debe volver a pedirlo hasta que sea positivo.
3.  **Aplicar la función:**
    Dada la siguiente función matemática:

    ```text
             /  n / 2      si n es par
    f(n) =  <
             \  3n + 1     si n es impar
    ```

4.  **Condición de parada:** Aplicar la función al número introducido repetidamente hasta llegar al patrón bucle `(4, 2, 1, 4, 2, 1...)`.
5.  **Salida:** Mostrar por pantalla cuántas iteraciones se han realizado y cuáles son los **últimos 5 números** de la secuencia calculada (vector/array).

## 🚀 Ejemplo de Funcionamiento

Si introducimos el número `3`, la secuencia generada es:
`3` → `10` → `5` → `16` → `8` → `4` → `2` → `1`

* **Iteraciones:** 7 (pasos realizados).
* **Últimos 5 números:** 16, 8, 4, 2, 1.

## 💻 Código Fuente (Solución)

El código ha sido escrito en C++ estándar, utilizando arrays estáticos para simular el comportamiento de un vector de forma sencilla.

```cpp
#include <iostream>
using namespace std;

int main() {
    int numero;

    // 1. Pedir el número al usuario y validar que sea positivo
    cout << "Introduce un numero entero positivo: ";
    cin >> numero;

    // Si es negativo o 0, seguimos pidiendo hasta que sea válido
    while (numero <= 0) {
        cout << "El numero debe ser mayor que 0. Intentalo de nuevo: ";
        cin >> numero;
    }

    // Usamos un array estático para guardar el historial
    // Suponemos un tamaño máximo de 1000 iteraciones para este ejercicio básico
    int lista[1000]; 
    int cantidad = 0; // Índice para saber cuántos números llevamos

    // Guardamos el número inicial en la lista
    lista[cantidad] = numero;
    cantidad++; 

    int iteraciones = 0;

    // 2. Aplicar la lógica de la Conjetura de Collatz
    // El bucle para cuando llegamos a 1 (inicio del patrón 4, 2, 1)
    while (numero != 1) {
        // Control de seguridad para no desbordar el array
        if (cantidad >= 1000) {
            cout << "La secuencia es demasiado larga." << endl;
            break;
        }

        if (numero % 2 == 0) {
            // Si es par
            numero = numero / 2;
        } else {
            // Si es impar
            numero = 3 * numero + 1;
        }

        // Guardamos el nuevo resultado
        lista[cantidad] = numero;
        cantidad++;
        iteraciones++;
    }

    // 3. Mostrar resultados
    cout << "\n--- Resultados ---" << endl;
    cout << "Iteraciones totales: " << iteraciones << endl;

    cout << "Los ultimos 5 numeros (vector): ";
    
    // Calculamos el índice de inicio para mostrar solo los últimos 5
    int inicio = cantidad - 5;
    
    // Si la secuencia es muy corta (ej: entrada 2), evitamos índices negativos
    if (inicio < 0) {
        inicio = 0;
    }

    // Imprimimos el array desde la posición calculada
    for (int i = inicio; i < cantidad; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;
}
