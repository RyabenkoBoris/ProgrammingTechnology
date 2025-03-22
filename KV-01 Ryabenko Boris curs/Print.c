#include "Measurement.h"
#include "Print.h"
#include "CommonVector.h"
#include "Sort.h"

//Функція для виведення тривимірного масиву на екран
void ArrayPrint(int ***Arr, int P, int M, int N)
{
    int j, k, i;
    printf("-----------------------------");
    for (k = 0; k < P; k++)
    {
        printf("\n");
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%4d", Arr[k][i][j]);
            }
            printf("\n");
        }
    }
    printf("-----------------------------\n\n");
}

//Функція для виведення таблиці з часом сортувань певного алгоритму
void OutTable(float ordered, float random, float backordered, int type)
{
    if(type == 1)
        printf("\t  Select2:");
    if(type == 2)
        printf("  Select3Exchange:");
    if(type == 3)
        printf("\t  Shell_2:");
    printf("%7.2f          %7.2f         %7.2f \n", ordered, random, backordered);
}
//Функція виводить тривимірний масив до та після сортування, який був обраний користувачем
void Sort(int type)
{
    int P = 3, M = 2, N = 2;
    ArrayMemory(P, M, N);
    system("cls");
    if(type == 1)
    {
        printf("Sorting algorithm #2 direct selection method: A[%d][%d][%d]\n\n", P, M, N);
        for(int i = 1; i <= 3; i++)
        {
            ArrayFill(Arr, P, M, N, i);
            if(i == 1)
                printf("Ordered\n");
            if(i == 2)
                printf("Random\n");
            if(i == 3)
                printf("BackOrdered\n");
            ArrayPrint(Arr, P, M, N);
            Select2(Arr, P, M, N);
            if(i == 1)
                printf("Ordered sorted\n");
            if(i == 2)
                printf("Random sorted\n");
            if(i == 3)
                printf("BackOrdered sorted\n");
            ArrayPrint(Arr, P, M, N);
        }
    }
    if(type == 2)
    {
        printf("Hybrid algorithm 'choice #3 - exchange': A[%d][%d][%d]\n\n", P, M, N);
        for(int i = 1; i <= 3; i++)
        {
            ArrayFill(Arr, P, M, N, i);
            if(i == 1)
                printf("Ordered\n");
            if(i == 2)
                printf("Random\n");
            if(i == 3)
                printf("BackOrdered\n");
            ArrayPrint(Arr, P, M, N);
            Select3Exchange(Arr, P, M, N);
            if(i == 1)
                printf("Ordered sorted\n");
            if(i == 2)
                printf("Random sorted\n");
            if(i == 3)
                printf("BackOrdered sorted\n");
            ArrayPrint(Arr, P, M, N);
        }
    }
    if(type == 3)
    {
        printf("Algorithm #2 of the Shell sorting method: A[%d][%d][%d]\n\n", P, M, N);
        for(int i = 1; i <= 3; i++)
        {
            ArrayFill(Arr, P, M, N, i);
            if(i == 1)
                printf("Ordered\n");
            if(i == 2)
                printf("Random\n");
            if(i == 3)
                printf("BackOrdered\n");
            ArrayPrint(Arr, P, M, N);
            Shell_2(Arr, P, M, N);
            if(i == 1)
                printf("Ordered sorted\n");
            if(i == 2)
                printf("Random sorted\n");
            if(i == 3)
                printf("BackOrdered sorted\n");
            ArrayPrint(Arr, P, M, N);
        }
    }
    FreeArray(P, M);
}
//Функція виводить час сортування алгоритму, який був обраний користувачем
void Time(int type, int view)
{
    system("cls");
    if(type == 1)
    {
        ArrayMemory(Pt, Mt, Nt);
        printf("Arr[%d][%d][%d]\n", Pt, Mt, Nt);
        printf("\t\t   Ordered\t     Random\t   BackOrdered \n");
        if(view == 1)
            ArrayMeasurement(Select2, Pt, Mt, Nt, 1);
        if(view == 2)
            ArrayMeasurement(Select3Exchange, Pt, Mt, Nt, 2);
        if(view == 3)
            ArrayMeasurement(Shell_2, Pt, Mt, Nt, 3);
        if(view == 4)
        {
            ArrayMeasurement(Select2, Pt, Mt, Nt, 1);
            ArrayMeasurement(Select3Exchange, Pt, Mt, Nt, 2);
            ArrayMeasurement(Shell_2, Pt, Mt, Nt, 3);
        }
        FreeArray(Pt, Mt);
    }
    else if(type == 2)
    {
        printf("Vector[%d]\n", VectorLength);
        printf("\t\t   Ordered\t     Random\t   BackOrdered \n");
        if(view == 1)
            VectorMeasurement(Vect_Select2, 1);
        if(view == 2)
            VectorMeasurement(Vect_Select3Exchange, 2);
        if(view == 3)
            VectorMeasurement(Vect_Shell_2, 3);
        if(view == 4)
        {
            VectorMeasurement(Vect_Select2, 1);
            VectorMeasurement(Vect_Select3Exchange, 2);
            VectorMeasurement(Vect_Shell_2, 3);
        }
    }
}
