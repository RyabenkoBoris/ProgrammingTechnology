//Модуль, що містить всі задані алгоритми реалізовані для вектора та масива
#ifndef __ALHORITHMS_H__
#define __ALHORITHMS_H__
#include "Common_Vector.h"
//Алгортми сортування методом прямого вибору №2 для
clock_t Select2(int ***Arr3D, int P, int M, int N);//масиву
clock_t VectorSelect2(int *A, int N);//вектора
//-----------------------------------------------------------
//Алгортми сортування методом прямого вибору №8 для
clock_t Select8(int ***Arr3D, int P, int M, int N);//масиву
clock_t VectorSelect8(int *A, int N);//вектора
//-----------------------------------------------------------
//Алгортми сортування методом прямого обміну №1 для
clock_t Exchange1(int ***Arr3D, int P, int M, int N);//масиву
clock_t VectorExchange1(int *A, int N);//вектора
#endif // __ALHORITHMS_H__
