#include "CommonVector.h"
int ***Arr;
int sum[Pt];
/*Function for allocating memory for a dynamic three-dimensional array*/
void array_memory(int P, int M, int N)
{
    Arr = (int***)malloc(P * sizeof(int**));
    for (int k = 0; k < P; k++)
    {
        Arr[k] = (int**)malloc(M * sizeof(int*));
        for (int i = 0; i < M; i++)
            Arr[k][i] = (int*)malloc(N * sizeof(int));
    }
}
/*The function fills an array, depending on the type parameter, it will be selected:
ordered, unordered, inversely ordered */
void array_fill(int ***Arr, int P, int M, int N, int type)
{
    int begin = 1, end = P*M*N;
    for (int k = 0; k < P; k++)
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
            {
                if(type == 1)
                    Arr[k][i][j] = begin++;
                if(type == 2)
                    Arr[k][i][j] = rand() % (P*M*N);
                if(type == 3)
                    Arr[k][i][j] = end--;
            }
}
/*The function fills a vector, depending on the type parameter, it will be selected:
ordered, unordered, inversely ordered*/
void vector_fill(int type)
{
    int begin = 1,end = VectorLength ;
    for (int i = 0; i < VectorLength; i++)
    {
        if(type == 1)
            Vector[i] = begin++;
        if(type == 2)
            Vector[i] = rand() % (100);
        if(type == 3)
            Vector[i] = end--;
    }
}
/*Function to free the memory of a dynamic three-dimensional array*/
void free_array(int P, int M)
{
    for (int k = 0; k < P; k++)
    {
        for (int i = 0; i < M; i++)
            free(Arr[k][i]);
        free(Arr[k]);
    }
    free(Arr);
}
