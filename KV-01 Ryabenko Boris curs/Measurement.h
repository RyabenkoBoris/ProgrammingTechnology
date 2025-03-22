#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED
/*Модуль для реалізації методики усереднення значень вимірів*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Загальна кількість вимірів часу роботи алгоритма
#define measurements_number 28
// Кількість відкинутих початкових вимірів
#define rejected_number 2
// Кількість відкинутих вимірів з мінімільними значеннями
// Вона ж дорівнює кількості відкинутих вимірів
// з максимальними значеннями
#define min_max_number 3
// Масив значень часу роботи алгоритма
extern clock_t res[measurements_number];
// Функція обробки і усереднення значень вимірів
// часу роботи алгоритма
// Повертає усереднене значення часу роботи алгоритма.
float measurement_processing();
//Функція, яка повністю оброблює час сортувань тривимірного масиву та виводить його на екран
void array_measurement(clock_t (*Func)(int*** Arr, int P, int M, int N),int P, int M, int N, int type);
//Функція, яка повністю оброблює час сортувань вектора та виводить його на екран
void vector_measurement(clock_t (*Func)(void), int type);
#endif // MEASUREMENT_H_INCLUDED
