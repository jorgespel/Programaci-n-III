# Módulo de Ranking Académico con Árbol AVL

## Estudiante: Jorge Eduardo Espel Melgar 
## Carnet: 9941-24-10596
## Curso: Progrmacion III Seccion: B


## Descripción

Este programa implementa un módulo de ranking académico usando un Árbol AVL.

El árbol almacena estudiantes completos y los ordena por `skill_score`.  
Si dos estudiantes tienen el mismo `skill_score`, se desempata usando el `student_id`.

## ¿Por qué un AVL es mejor que un BST normal para ranking académico?

Un Árbol AVL es mejor que un BST normal porque se mantiene balanceado automáticamente.

En un BST normal, si los datos se insertan de forma ordenada, el árbol puede quedar desbalanceado y las búsquedas pueden volverse lentas.

En cambio, el AVL realiza rotaciones para mantener el equilibrio del árbol, permitiendo inserciones y búsquedas más eficientes.

## Estructura del proyecto

```txt
/semana-avl
  /src
    main.cpp
    AVL.h
    AVL.cpp
    Student.h
  README.md

