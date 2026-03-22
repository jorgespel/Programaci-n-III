### **Título**
**Evidencia de implementación de pila dinámica en C++**

### **Datos del estudiante**
**Nombre:** Jorge Espel  
**Curso:** Programación 3  
**Fecha:** 22/03/2026  

### **Descripción del trabajo**
En esta práctica se desarrolló un programa en C++ para implementar una pila dinámica de números enteros utilizando nodos, punteros y memoria dinámica.

El programa permite al usuario interactuar con una pila mediante un menú repetitivo, ejecutando diferentes operaciones como insertar elementos, eliminar el tope, mostrar el contenido, contar elementos, buscar valores y vaciar la pila.

### **Estructura utilizada**
Para resolver el ejercicio se utilizó una estructura tipo nodo (`struct Nodo`) con los siguientes campos:
- un dato entero
- un puntero al siguiente nodo

La memoria se administra dinámicamente con `new` para crear nodos y `delete` para liberarlos.
