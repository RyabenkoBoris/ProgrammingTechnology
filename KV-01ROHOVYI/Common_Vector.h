//модуль, що містить ініціалізацію масива та вектора, виділення та звільнення
//пам'яті для масиву та їх заповнення
#ifndef __CommonVector_H__
#define __CommonVector_H__
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#define p 2    //кількість перерізів
#define n 64   //кількість рядків
#define m 64  //кількість стовпців
#define VectorLenght 100000 //розмір вектора для порівняння часу роботи
extern int*** Arr3D;
int Vector[VectorLenght];//оголошення вектора
void FillVector(int *A, int N, int flag);//заповнення вектора
void ArrayMemory(int P, int M, int N);//виділення пам'яті під масив
void FreeArrayMemory(int P, int M, int N);//звільнення пам'яті виділеної під масив
void FillArray(int ***Arr3D, int P, int M, int N, int flag);//заповнення масиву значеннями
#endif
