# Práctica: La Conjetura de Collatz (3n + 1)

Este repositorio contiene una solución sencilla en C++ para resolver el problema de la **Conjetura de Collatz**, implementada utilizando lógica básica y sin librerías externas (solo `iostream`), si quereis ahorrar tiempo recomiendo probar guardando valores con funciones del módulo vector.

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

## 🧠 Pseudocódigo

Aquí dejo un pequeño pseudocódigo verificado y tabulado :D

```text
INICIO
    // Declaración de variables
    DEFINIR numero ENTERO
    DEFINIR lista COMO ARRAY[1000] DE ENTEROS
    DEFINIR cantidad = 0
    DEFINIR iteraciones = 0

    // 1. Entrada y Validación
    ESCRIBIR "Introduce un número entero positivo: "
    LEER numero

    MIENTRAS numero <= 0 HACER
        ESCRIBIR "El número debe ser mayor que 0. Inténtalo de nuevo: "
        LEER numero
    FIN MIENTRAS

    // Guardar el número inicial
    lista[cantidad] = numero
    cantidad = cantidad + 1

    // 2. Cálculo de la secuencia (Bucle hasta llegar a 1)
    MIENTRAS numero != 1 HACER
        
        SI (numero MOD 2 == 0) ENTONCES
            // Es par
            numero = numero / 2
        SINO
            // Es impar
            numero = (3 * numero) + 1
        FIN SI

        // Guardar en la lista y aumentar contadores
        lista[cantidad] = numero
        cantidad = cantidad + 1
        iteraciones = iteraciones + 1
        
    FIN MIENTRAS

    // 3. Salida de datos
    ESCRIBIR "Iteraciones totales: ", iteraciones

    // Calcular desde dónde empezar a imprimir (últimos 5)
    DEFINIR inicio = cantidad - 5

    SI inicio < 0 ENTONCES
        inicio = 0
    FIN SI

    ESCRIBIR "Los últimos 5 números son: "
    PARA i DESDE inicio HASTA (cantidad - 1) HACER
        ESCRIBIR lista[i]
    FIN PARA

FIN
