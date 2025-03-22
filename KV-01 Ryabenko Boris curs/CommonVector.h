#ifndef COMMONVECTOR_H_INCLUDED
#define COMMONVECTOR_H_INCLUDED
/*module for connecting the necessary libraries, exporting functions and
memory allocation, the module also contains general data about the three-dimensional
array and vector used to calculate the algorithm time*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*The library required to use the clock() function;*/
#include <time.h>
/*Library for working with dynamic data*/
#include <malloc.h>
/*The dimensions of the 3-dimensional array used to calculate the time of the algorithms*/
#define Pt 150000//К-сть перерізів масиву
#define Mt 16//К-сть рядків у одному перерізі масива
#define Nt 16//К-сть стовбчиків у одному перерізі масива
// Розмір вектора, який використовуємо для підрахунку часу роботи алгоритмів
#define VectorLength 150000

//Оголошення вектора сум стовбчиків для зручнішого використання у функціях
int sum[Pt];
// Оголошення тривимірного масиву для використання його в сортуваннях
extern int*** Arr;
// Оголошення вектора для використання його в сортуваннях
int Vector[VectorLength];
//Функція виділення динамічної пам'яті для масиву
void array_memory(int P, int M, int N);
// Функція яка заповнює 3-вимірний масив
void array_fill(int ***Arr, int order, int P, int M, int N);
// Функція яка заповнює вектор .
void vector_fill(int order);
//Функція звільнення пам'яті від динамічного масиву
void free_array(int P, int M);
#endif // COMMONVECTOR_H_INCLUDED
