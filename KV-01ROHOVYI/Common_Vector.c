#include "Common_Vector.h"
int ***Arr3D;
void ArrayMemory(int P, int M, int N)//˜˜˜˜˜˜˜˜ ˜˜˜'˜˜ ˜˜˜ ˜˜˜˜˜˜
{
    Arr3D = (int***) malloc(P*sizeof(int**));
    for (int k=0; k<P; k++)
    {
        Arr3D[k] = (int**) malloc(M*sizeof(int*));
        for (int i=0; i<M; i++)
            Arr3D[k][i] = (int*) malloc(N*sizeof(int));
    }
}
void FreeArrayMemory(int P, int M, int N)//˜˜˜˜˜˜˜˜˜ ˜˜˜'˜˜ ˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜
{
    for (int k=0; k<P; k++)
    {
        for (int i=0; i<M; i++)
            free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);
}
void FillArray(int ***Arr3D,int P, int M, int N, int flag)//˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
{
    // flag = 1 - ˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜
    // flag = 2 - ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜
    // flag = 3 - ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜
    switch(flag)
    {
    case 1:
    {
        int number=0;
        for(int k=0; k<P; k++)
        {
            for(int j=0; j<N; j++)
            {
                for(int i=0; i<M; i++)
                {
                    Arr3D[k][i][j]=number++;
                }
            }
        }
        break;
    }
    case 2:
    {
        for(int k=0; k<P; k++)
        {
            for(int j=0; j<N; j++)
            {
                for(int i=0; i<M; i++)
                {
                    Arr3D[k][i][j]=rand()%(P*M*N);
                }
            }
        }
        break;
    }
    case 3:
    {
        int number = P*M*N-1;
        for(int k=0; k<P; k++)
        {
            for(int j=0; j<N; j++)
            {
                for(int i=0; i<M; i++)
                {
                    Arr3D[k][i][j]=number--;
                }
            }
        }
        break;
    }
    default:
        break;
    }
}

void FillVector (int *A, int N, int flag) // ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜
{
    // flag = 1 - ˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    // flag = 2 - ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    // flag = 3 - ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
switch(flag)
{
    case 1: 
    {
        for(int i=0; i<N; i++) A[i] = i;
        break;
    }
    case 2:
    {
        for(int i=0; i<N; i++) A[i] = rand()%N;
        break;
    }
    case 3:
    {
        for(int i=0; i<N; i++) A[i] = N-i;
        break;
    }
    default:
        break;
}
}
