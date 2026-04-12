# Clasificación dinámica de números

## Descripción
Este programa fue desarrollado en C++ utilizando estructuras dinámicas, con el objetivo de clasificar números ingresados por el usuario en diferentes estructuras de datos según su tipo.

El sistema trabaja de la siguiente manera:

- Los números **pares** se almacenan en una **cola**
- Los números **impares** se almacenan en una **pila**
- Los números **negativos** (excepto -1) se almacenan en una **lista enlazada**

El programa también incluye un menú interactivo que permite visualizar y eliminar elementos de las estructuras, además de validar entradas incorrectas y liberar la memoria utilizada al finalizar.
---

## Funcionalidades
El programa permite:

1. Ingresar números dinámicamente
2. Guardar los números según su tipo:
   - par → cola
   - impar → pila
   - negativo → lista enlazada
3. Mostrar el contenido de:
   - pila
   - cola
   - lista
4. Eliminar elementos de:
   - pila
   - cola
5. Ver el elemento superior de la pila
6. Ver el primer elemento de la cola
7. Mostrar estadísticas:
   - cantidad de pares
   - cantidad de impares
   - cantidad de negativos
8. Liberar memoria al salir
