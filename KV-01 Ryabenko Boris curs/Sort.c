#include "Sort.h"
#include "CommonVector.h"
#include "Measurement.h"
//Алгоритм сортування №2 методу прямого вибору
//та підрахунок часу сортування цього алгоритму (тривимірний масив)
clock_t Select2(int*** Arr, int P, int M, int N)
{
    int imin, tmp,i,j,k;
    clock_t time_start, time_stop;
    time_start = clock();
    for (k = 0; k < P; k++)
    {
        sum[k] = 0;
        for (i=0; i < M; i++)
        {
            for (j=0; j < N; j++)
            {
                sum[k] += Arr[k][i][j];
            }
        }

    }
    for(int s = 0; s < P-1; s++)
    {
        imin = s;
        for(i = s+1; i < P; i++)
            if (sum[i] < sum[imin])
                imin = i;
        tmp = sum[imin];
        sum[imin] = sum[s];
        sum[s] = tmp;
        for(i=0; i < M; i++)
        {
            for(j=0; j < N; j++)
            {
                tmp = Arr[imin][i][j];
                Arr[imin][i][j] = Arr[s][i][j];
                Arr[s][i][j] = tmp;
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
//Гібридний алгоритм "вибір№3 – обмін"
//та підрахунок часу сортування цього алгоритму (тривимірний масив)
clock_t Select3Exchange(int*** Arr, int P, int M, int N)
{
    int Min, Max, tmp,i,j,k;
    int L, R;
    clock_t time_start, time_stop;
    time_start = clock();
    for (k = 0; k < P; k++)
    {
        sum[k] = 0;
        for (i=0; i < M; i++)
        {
            for (j=0; j < N; j++)
            {
                sum[k] += Arr[k][i][j];
            }
        }
    }
    L=0;
    R=P-1;
    while (L<R)
    {
        if (sum[L] > sum[R])
        {
            tmp=sum[L];
            sum[L]=sum[R];
            sum[R]=tmp;
            for(int i1=0; i1<M; i1++)
            {
                for(int j1=0; j1<N; j1++)
                {
                    tmp = Arr[L][i1][j1];
                    Arr[L][i1][j1] = Arr[R][i1][j1];
                    Arr[R][i1][j1] = tmp;
                }
            }
        }
        Min=sum[L];
        Max=sum[R];
        for(int i=L+1; i<R+1; i++)
        {
            if (sum[i] < Min)
            {
                Min=sum[i];
                sum[i]=sum[L];
                sum[L]=Min;
                for(int i1=0; i1<M; i1++)
                {
                    for(int j1=0; j1<N; j1++)
                    {
                        tmp = Arr[i][i1][j1];
                        Arr[i][i1][j1] = Arr[L][i1][j1];
                        Arr[L][i1][j1] = tmp;
                    }
                }
            }
            else if (sum[i] > Max)
            {
                Max=sum[i];
                sum[i]=sum[R];
                sum[R]=Max;
                for(int i1=0; i1<M; i1++)
                {
                    for(int j1=0; j1<N; j1++)
                    {
                        tmp = Arr[i][i1][j1];
                        Arr[i][i1][j1] = Arr[R][i1][j1];
                        Arr[R][i1][j1] = tmp;
                    }
                }
            }
        }
        L=L+1;
        R=R-1;
    }
    time_stop = clock();
    return time_stop - time_start;
}
//Алгоритм №2 методу сортування Шелла
//та підрахунок часу сортування цього алгоритму (тривимірний масив)
clock_t Shell_2(int*** Arr, int P, int M, int N)
{
    int tmp, t, j, k,T=(int)log2f((float)P)-1,Stages[T];
    clock_t time_start, time_stop;
    time_start = clock();
    for (k = 0; k < P; k++)
    {
        sum[k] = 0;
        for (int i=0; i < M; i++)
        {
            for (int j=0; j < N; j++)
            {
                sum[k] += Arr[k][i][j];
            }
        }
    }
    if (P<4)
        t=1;
    else
        t=(int)log2f((float)P)-1;
    Stages[t-1]=1;
    for (int i=t-2; i>=0; i--)
        Stages[i]=2*Stages[i+1]+1;
    for (int p=0; p<t; p++)
    {
        k=Stages[p];
        for (int i=k; i<P; i++)
        {
            j=i;
            while (j>=k && sum[j]<sum[j-k])
            {
                tmp=sum[j];
                sum[j]=sum[j-k];
                sum[j-k]=tmp;
                for(int i1=0; i1<M; i1++)
                {
                    for(int j1=0; j1<N; j1++)
                    {
                        tmp = Arr[j][i1][j1];
                        Arr[j][i1][j1] = Arr[j-k][i1][j1];
                        Arr[j-k][i1][j1] = tmp;
                    }
                }
                j=j-k;
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
//Алгоритм сортування №2 методу прямого вибору
//та підрахунок часу сортування цього алгоритму (вектор)
clock_t Vect_Select2()
{
    int imin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int s=0; s<VectorLength-1; s++)
    {
        imin=s;
        for(int i=s+1; i<VectorLength; i++)
            if (Vector[i]<Vector[imin])
                imin=i;
        tmp=Vector[imin];
        Vector[imin]=Vector[s];
        Vector[s]=tmp;
    }
    time_stop = clock();
    return time_stop - time_start;
}
//Гібридний алгоритм "вибір№3 – обмін" (вектор)
//та підрахунок часу сортування цього алгоритму (вектор)
clock_t Vect_Select3Exchange()
{
    int Min, Max, tmp;
    int L, R;
    clock_t time_start, time_stop;
    time_start = clock();
    L=0;
    R=VectorLength-1;
    while (L<R)
    {
        if (Vector[L] > Vector[R])
        {
            tmp=Vector[L];
            Vector[L]=Vector[R];
            Vector[R]=tmp;
        }
        Min=Vector[L];
        Max=Vector[R];
        for(int i=L+1; i<R+1; i++)
        {
            if (Vector[i] < Min)
            {
                Min=Vector[i];
                Vector[i]=Vector[L];
                Vector[L]=Min;
            }
            else if (Vector[i] > Max)
            {
                Max=Vector[i];
                Vector[i]=Vector[R];
                Vector[R]=Max;
            }
        }
        L=L+1;
        R=R-1;
    }
    time_stop = clock();
    return time_stop - time_start;
}
//Алгоритм №2 методу сортування Шелла (вектор)
//та підрахунок часу сортування цього алгоритму (вектор)
clock_t Vect_Shell_2()
{
    int tmp, t, j, k,T=(int)log2f((float)VectorLength)-1,Stages[T];
    clock_t time_start, time_stop;
    time_start = clock();
    if (VectorLength<4)
        t=1;
    else
        t=(int)log2f((float)VectorLength)-1;
    Stages[t-1]=1;
    for (int i=t-2; i>=0; i--)
        Stages[i]=2*Stages[i+1]+1;
    for (int p=0; p<t; p++)
    {
        k=Stages[p];
        for (int i=k; i<VectorLength; i++)
        {
            j=i;
            while (j>=k && Vector[j]<Vector[j-k])
            {
                tmp=Vector[j];
                Vector[j]=Vector[j-k];
                Vector[j-k]=tmp;
                j=j-k;
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
