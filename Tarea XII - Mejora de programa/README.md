## Estudiante: Jorge Eduardo Espel Melgar
## Carnet: 9941-24-10596
## Curso: Progrmacion III Seccion: B

## Descripción

El programa proporcionado genera millones de registros de clientes y posteriormente los procesa para agruparlos en campañas comerciales.

La versión original presenta problemas de diseño relacionados con el consumo de memoria y el uso de estructuras de datos poco eficientes.

---

# Problemas identificados

## 1. Carga completa de clientes en memoria

El programa almacena todos los clientes en un ArrayList antes de iniciar el procesamiento.

Esto provoca:

- Mayor consumo de memoria.
- Riesgo de OutOfMemoryError.
- Menor escalabilidad.

---

## 2. Uso de búsqueda lineal

La clase ProcesadorIneficiente utiliza listas para buscar campañas.

Para cada cliente se recorre completamente la lista de campañas existentes.

Esto aumenta el tiempo total de procesamiento.

---

# Solución implementada

Se creó una nueva clase:

```java
ProcesadorOptimizado.java
```

La nueva versión utiliza:

```java
HashMap<String, List<Cliente>>
```

para almacenar las campañas.

De esta manera:

- La búsqueda es más rápida.
- El rendimiento mejora.
- La complejidad disminuye.

---

# Comparación

## Versión original

- Usa ArrayList para campañas.
- Realiza búsqueda lineal.
- Menor eficiencia.

## Versión optimizada

- Usa HashMap.
- Acceso directo mediante clave.
- Mejor rendimiento.

---

# Conclusión

Durante esta práctica aprendí que la elección de las estructuras de datos tiene un impacto importante en el rendimiento de una aplicación.

La versión original funciona correctamente, pero utiliza búsquedas lineales que aumentan el tiempo de procesamiento cuando la cantidad de registros es muy grande.

Al implementar HashMap se obtiene una solución más eficiente y escalable, permitiendo agrupar campañas de manera más rápida y organizada.
