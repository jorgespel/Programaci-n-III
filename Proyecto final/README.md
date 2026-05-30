# Nombre: Jorge Eduardo Espel Melgar
# Carnet: 9941-24-10596

## Proyecto Final - Red Social Académica Universitaria

## Descripción:

Este proyecto consiste en el desarrollo de una Red Social Académica Universitaria utilizando estructuras de datos avanzadas implementadas manualmente en C++.

El sistema permite administrar estudiantes, conexiones académicas, proyectos y rankings utilizando diferentes estructuras de datos, además de incluir un benchmark comparativo desarrollado en Java para analizar el rendimiento entre implementaciones manuales y estructuras nativas del framework.
---
## Estructuras de Datos Implementadas

### 1. Tabla Hash

Utilizada para almacenar e indexar estudiantes mediante el campo student_id.

Características:

* Inserción
* Búsqueda
* Eliminación
* Manejo de colisiones mediante Separate Chaining
* Cálculo del factor de carga

---

### 2. Árbol AVL

Utilizado para mantener un ranking académico basado en el campo skill_score.

Características:

* Inserción balanceada
* Recorrido InOrder
* Ranking académico
* Cálculo de altura

---

### 3. Grafo No Dirigido

Representa las conexiones entre estudiantes.

Características:

* Conectar estudiantes
* Mostrar conexiones
* BFS
* DFS

---

### 4. Lista Enlazada

Cada estudiante posee una lista de proyectos académicos.

Información almacenada:

* project_id
* title
* description
* completion_year

Operaciones:

* Agregar proyecto
* Mostrar proyectos

---

### 5. Pila

Utilizada para almacenar historial de acciones realizadas dentro del sistema.

---

## Benchmark en C++

El sistema genera automáticamente el archivo:

cpp_results.csv

Formato:

```csv
language,operation,structure,records,time_ms
C++,insert,HashTable,10000,3.25
C++,search,HashTable,10000,1.10
C++,insert,AVL,10000,8.40
C++,traversal,AVL,10000,2.30
C++,bfs,Graph,10000,4.70
C++,dfs,Graph,10000,4.20
```

---

## Benchmark en Java

Se utilizan estructuras nativas:

* HashMap
* TreeMap

El sistema genera automáticamente:

java_results.csv


---

## Conclusiones

La implementación permitió comprender el funcionamiento interno de estructuras de datos fundamentales como tablas hash, árboles AVL, grafos, listas enlazadas y pilas.

Además, la comparación con las estructuras nativas de Java permitió observar diferencias importantes en rendimiento, facilidad de implementación y nivel de abstracción entre ambos lenguajes.

