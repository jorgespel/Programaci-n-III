## Descripción
Este proyecto consiste en la implementación de un sistema que simula el funcionamiento de **deshacer (UNDO)** y **rehacer (REDO)** acciones, similar a un editor de texto.

El programa permite al usuario realizar acciones, deshacerlas y rehacerlas utilizando **dos pilas dinámicas**, aplicando estructuras, punteros y manejo de memoria dinámica en C++.

---

Datos del Estudiante
**Nombre:** Jorge Edaurdo Espel Melgar  
**Carné:** 9941-24-10596

---
Lógica del sistema

🔹 Cuando se realiza una acción:
  * Se guarda en la pila de acciones
  * Se limpia la pila de rehacer

🔹 Cuando se deshace (UNDO):
   * Se elimina de la pila principal
   * Se pasa a la pila de rehacer

🔹 Cuando se rehace (REDO):
  * Se elimina de la pila de rehacer
  * Se regresa a la pila principal
