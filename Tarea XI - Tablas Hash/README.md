## Estudiante: Jorge Eduardo Espel Melgar 
## Carnet: 9941-24-10596
## Curso: Progrmacion III Seccion: B

## Descripción
En esta tarea se realizaron dos implementaciones para almacenar estudiantes utilizando estructuras hash:

1. Implementación manual de una tabla hash en C++.
2. Implementación utilizando HashMap en Java.

Ambos programas leen estudiantes desde un archivo CSV y permiten:

- Insertar estudiantes.
- Buscar estudiantes por ID.
- Eliminar estudiantes.
- Mostrar información almacenada.
- Mostrar estadísticas.

## Funcionamiento
En ambos programas el usuario trabaja con un archivo CSV que contiene la información de los estudiantes.
Al iniciar la ejecución, el sistema lee automáticamente cada línea del archivo y registra los datos dentro de una estructura hash utilizando el student_id como clave principal.
En el programa de C++, la tabla hash fue desarrollada manualmente utilizando arreglos, punteros y listas enlazadas para manejar las colisiones entre elementos.
Por otro lado, en el programa de Java se utilizó la estructura nativa HashMap, la cual administra internamente el almacenamiento de los estudiantes y el manejo de colisiones.
Además, ambos programas incluyen validaciones para evitar el ingreso de estudiantes con IDs repetidos y permiten realizar búsquedas, eliminaciones y consultas de información desde el menú principal.

## Diferencia entre C++ y Java
La diferencia principal entre los programas desarrollados en C++ y Java está en la forma en que se implementa la estructura hash.
En el programa de C++, la tabla hash fue creada manualmente desde cero. Para ello se utilizaron arreglos, punteros y listas enlazadas, además de implementar una función hash y el manejo de colisiones mediante Separate Chaining. Esto hace que el programa tenga mayor complejidad y requiera administrar manualmente la memoria.
En cambio, en el programa de Java se utilizó la estructura nativa HashMap, que ya incluye internamente la lógica de almacenamiento y manejo de colisiones. Gracias a esto, el código es más corto, más simple y más fácil de mantener.
Otra diferencia es que en C++ se muestran estadísticas propias de la tabla hash, como el número de colisiones y el factor de carga, mientras que en Java el HashMap administra esos procesos automáticamente y no es necesario programarlos manualmente.
