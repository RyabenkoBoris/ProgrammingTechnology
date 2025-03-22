#include "CommonVector.h"
int ***Arr;
int sum[Pt];
//Функція для виділення пам'яті динамічного тривимірного масиву
void ArrayMemory(int P, int M, int N)
{
    Arr = (int***)malloc(P * sizeof(int**));
    for (int k = 0; k < P; k++)
    {
        Arr[k] = (int**)malloc(M * sizeof(int*));
        for (int i = 0; i < M; i++)
            Arr[k][i] = (int*)malloc(N * sizeof(int));
    }
}
//Функція заповняє масив, залежно від параметру type буде вибрано:
// впорядкований, невпорядкований, обернено впорядкований
void ArrayFill(int ***Arr, int P, int M, int N, int type)
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
//Функція заповняє вектор, залежно від параметру type буде вибрано:
// впорядкований, невпорядкований, обернено впорядкований
void VectorFill(int type)
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
//Функція для звільнення пам'яті динамічного тривимірного масиву
void FreeArray(int P, int M)
{
    for (int k = 0; k < P; k++)
    {
        for (int i = 0; i < M; i++)
            free(Arr[k][i]);
        free(Arr[k]);
    }
    free(Arr);
}
