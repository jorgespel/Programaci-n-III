# Proyecto de Estructuras de Datos en C++

## Nombre: Jorge Eduardo Espel Melgar

## Carnet: 9941-24-10596

## Descripción del programa
Este programa permite ingresar números enteros y clasificarlos automáticamente según su tipo.

Los números pares positivos se almacenan en una cola, los números impares positivos en una pila, los números negativos en una lista simplemente enlazada y los ceros se rechazan como intentos inválidos.

Además, todos los datos válidos se registran en una lista doblemente enlazada como historial. También se puede construir un árbol BST usando únicamente los números positivos válidos.

## Estructuras utilizadas
- Punteros
- Memoria dinámica
- Struct
- Nodos
- Lista simplemente enlazada
- Lista doblemente enlazada
- Pila
- Cola
- Árbol BST

## Explicación de la lógica
El usuario ingresa una cantidad de números.
Cada número se evalúa de la siguiente forma:

- Si es par positivo, se guarda en la cola.
- Si es impar positivo, se guarda en la pila.
- Si es negativo, se guarda en la lista simple.
- Si es cero, no se guarda y se cuenta como rechazado.

Los números válidos también se guardan en el historial, indicando el valor, el tipo de estructura y el orden de ingreso.

El BST no se construye mientras se ingresan los datos. Se construye únicamente cuando el usuario selecciona la opción 6 del menú.
