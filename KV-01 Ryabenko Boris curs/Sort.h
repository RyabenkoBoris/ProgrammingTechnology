#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include "Measurement.h"
/*модуль в якому містяться алгоритми сортування
 для тривимірного масиву та вектора*/

//Алгоритм сортування №2 методу прямого вибору (тривимірний масив)
clock_t Select2(int*** Arr, int P, int M, int N);
//Гібридний алгоритм "вибір№3 – обмін" (тривимірний масив)
clock_t Select3Exchange(int*** Arr, int P, int M, int N);
//Алгоритм №2 методу сортування Шелла(тривимірний масив)
clock_t Shell_2(int ***Arr, int P, int M, int N);
//Алгоритм сортування №2 методу прямого вибору (вектор)
clock_t Vect_Select2();
//Гібридний алгоритм "вибір№3 – обмін" (вектор)
clock_t Vect_Select3Exchange();
//Алгоритм №2 методу сортування Шелла (вектор)
clock_t Vect_Shell_2();

#endif // SORT_H_INCLUDED
