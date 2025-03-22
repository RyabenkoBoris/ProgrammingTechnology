#include "Print.h"
#include "Measurement.h"
#include "CommonVector.h"
#include "Sort.h"

/*Function for displaying a three-dimensional array on the screen*/
void array_print(int ***Arr, int P, int M, int N)
{
    int j, k, i;
    printf("-----------------------------");
    for (k = 0; k < P; k++) {
        printf("\n");
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                printf("%4d", Arr[k][i][j]);
            }
            printf("\n");
        }
    }
    printf("-----------------------------\n\n");
}

/*Function for displaying a table with the time of sorting of a certain algorithm*/
void out_table(float ordered, float random, float backordered, int type)
{
    if(type == 1)
        printf("\t  Select2:");
    if(type == 2)
        printf("  Select3Exchange:");
    if(type == 3)
        printf("\t  Shell_2:");
    printf("%7.2f          %7.2f         %7.2f \n", ordered, random, backordered);
}
/* The function displays a three - dimensional array before and after sorting, which was selected by the user */
void sort(int type)
{
    int P = 3, M = 2, N = 2;
    array_memory(P, M, N);
    system("cls");
    if(type == 1) {
        printf("Sorting algorithm #2 direct selection method: A[%d][%d][%d]\n\n", P, M, N);
        for(int i = 1; i <= 3; i++) {
            array_fill(Arr, P, M, N, i);
            if (i == 1) {
                printf("Ordered\n");
            }
            if (i == 2) {
                printf("Random\n");
            }
            if (i == 3) {
                printf("BackOrdered\n");
            }
            array_print(Arr, P, M, N);
            select_2(Arr, P, M, N);
            if (i == 1) {
                printf("Ordered sorted\n");
            }
            if (i == 2) {
                printf("Random sorted\n");
            }
            if (i == 3) {
                printf("BackOrdered sorted\n");
            }  

            array_print(Arr, P, M, N);
        }
    }
    if(type == 2)
    {
        printf("Hybrid algorithm 'choice #3 - exchange': A[%d][%d][%d]\n\n", P, M, N);
        for(int i = 1; i <= 3; i++)
        {
            array_fill(Arr, P, M, N, i);
            if (i == 1) {
                printf("Ordered\n");
            }
            if (i == 2) {
                printf("Random\n");
            }
            if (i == 3) {
                printf("BackOrdered\n");
            }
                
            array_print(Arr, P, M, N);
            select_3_exchange(Arr, P, M, N);
            if (i == 1) {
                printf("Ordered sorted\n");
            }
            if (i == 2) {
                printf("Random sorted\n");
            }
            if (i == 3) {
                printf("BackOrdered sorted\n");
            }
                
            array_print(Arr, P, M, N);
        }
    }
    if(type == 3)
    {
        printf("Algorithm #2 of the Shell sorting method: A[%d][%d][%d]\n\n", P, M, N);
        for(int i = 1; i <= 3; i++)
        {
            array_fill(Arr, P, M, N, i);
            if(i == 1)
                printf("Ordered\n");
            if(i == 2)
                printf("Random\n");
            if(i == 3)
                printf("BackOrdered\n");
            array_print(Arr, P, M, N);
            shell_2(Arr, P, M, N);
            if(i == 1)
                printf("Ordered sorted\n");
            if(i == 2)
                printf("Random sorted\n");
            if(i == 3)
                printf("BackOrdered sorted\n");
            array_print(Arr, P, M, N);
        }
    }
    free_array(P, M);
}
/* The function displays the sorting time of the algorithm selected by the user */
void time(int type, int view)
{
    system("cls");
    if(type == 1)
    {
        array_memory(Pt, Mt, Nt);
        printf("Arr[%d][%d][%d]\n", Pt, Mt, Nt);
        printf("\t\t   Ordered\t     Random\t   BackOrdered \n");
        if(view == 1)
            array_measurement(select_2, Pt, Mt, Nt, 1);
        if(view == 2)
            array_measurement(select_3_exchange, Pt, Mt, Nt, 2);
        if(view == 3)
            array_measurement(shell_2, Pt, Mt, Nt, 3);
        if(view == 4)
        {
            array_measurement(select_2, Pt, Mt, Nt, 1);
            array_measurement(select_3_exchange, Pt, Mt, Nt, 2);
            array_measurement(shell_2, Pt, Mt, Nt, 3);
        }
        free_array(Pt, Mt);
    }
    else if(type == 2)
    {
        printf("Vector[%d]\n", VectorLength);
        printf("\t\t   Ordered\t     Random\t   BackOrdered \n");
        if(view == 1)
            vector_measurement(vect_select_2, 1);
        if(view == 2)
            vector_measurement(vect_select_3_exchange, 2);
        if(view == 3)
            vector_measurement(vect_shell_2, 3);
        if(view == 4)
        {
            vector_measurement(vect_select_2, 1);
            vector_measurement(vect_select_3_exchange, 2);
            vector_measurement(vect_shell_2, 3);
        }
    }
}
