#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include "Measurement.h"
/*a module that contains sorting algorithms
 for a three-dimensional array and vector*/

/*Sorting algorithm #2 of the direct selection method (three-dimensional array)*/
clock_t select_2(int*** Arr, int P, int M, int N);
/*Hybrid algorithm “choice #3 - exchange” (three-dimensional array)*/
clock_t select_3_exchange(int*** Arr, int P, int M, int N);
/*Algorithm #2 of the Shell sorting method (three-dimensional array)*/
clock_t shell_2(int ***Arr, int P, int M, int N);
/*Sorting algorithm #2 of the direct selection method (vector)*/
clock_t vect_select_2();
/*Hybrid algorithm “choice #3 - exchange” (vector)*/
clock_t vect_select_3_exchange();
/*Algorithm #2 of the Shell sorting method (vector)*/
clock_t vect_shell_2();

#endif // SORT_H_INCLUDED
