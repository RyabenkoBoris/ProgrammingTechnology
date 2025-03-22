#include "Alhorithms.h"
#include "Common_Vector.h"
#include "Measurement.h"
#include "menu.h"

void OutTable(float ordered, float random, float backordered, int flag)
{
    //˜ ˜˜˜˜˜˜ flag ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜:
    //flag = 1 - ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜2
    //flag = 2 - ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜8
    //flag = 3 - ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜1
    printf("\t\tOrdered \t Random \t BackOrdered\n");
    switch (flag)
    {
    case 1:
    {
        printf("Select2      ");
        break;
    }
    case 2:
    {
        printf("Select8      ");
        break;
    }
    case 3:
    {
        printf("Exchange1     ");
        break;
    }
    default:
    {
        break;
    }
    }
    printf("%7.2f          %7.2f         %7.2f\n", ordered, random, backordered);
}
//˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜(˜˜˜˜˜˜˜˜˜˜˜˜˜ --> ˜˜˜˜˜˜˜˜˜˜ --> ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜),
//˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜
//˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜(˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜)
void OutSortVector(clock_t(sortalh)(int* A, int N))
{
    int N=10, flag =1;//N - ˜˜˜˜˜ ˜˜˜˜˜˜˜
    //˜˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜
    //---------------------------------------------------------------------
    printf("Ordered:       ");
    FillVector(Vector, N, flag);
    for(int i=0;i<N;i++)
    {
        printf("%d ", Vector[i]);
    }
    printf("\nOrdered Sorted:");
    sortalh(Vector,N);
    for(int i=0;i<N;i++)
    {
        printf("%d ", Vector[i]);
    }
    flag++;
    printf("\n------------------------------------------------\n");
    //˜˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜
    //---------------------------------------------------------------------
    printf("Random:      ");
    FillVector(Vector, N, flag);
    for(int i=0;i<N;i++)
    {
        printf("%d ", Vector[i]);
    }
    printf("\nRandom Sorted:");
    sortalh(Vector,N);
    for(int i=0;i<N;i++)
    {
        printf("%d ", Vector[i]);
    }
    flag++;
    printf("\n--------------------------------------------------\n");
    //˜˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜
    //---------------------------------------------------------------------
    printf("BackOrdered:       ");
    FillVector(Vector, N, flag);
    for(int i=0;i<N;i++)
    {
        printf("%d ", Vector[i]);
    }
    printf("\nBackOrdered Sorted:");
    sortalh(Vector,N);
    for(int i=0;i<N;i++)
    {
        printf("%d ", Vector[i]);
    }
}
//˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜(˜˜˜˜˜˜˜˜˜˜˜˜˜ --> ˜˜˜˜˜˜˜˜˜˜ --> ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜),
//˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜
//˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜(˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜)
void OutSortArray(clock_t(*sortalh)(int***,int,int,int))
{
    int P=2,N=4,M=4,flag=1;//P,M,N- ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    //˜˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    //---------------------------------------------------------------------
    printf("\t\tOrdered\n");
    FillArray(Arr3D,P,M,N,flag);
    for(int k=0; k<P; k++)
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d ",Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("------------------------------------------");
    printf("\t\tOrdered Sorted\n");
    sortalh(Arr3D,P,M,N);
    for(int k=0; k<P; k++)
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d ",Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    flag++;

    printf("\n------------------------------------------");
    //˜˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    //---------------------------------------------------------------------
    printf("\t\tRandom\n");
    FillArray(Arr3D,P,M,N,flag);
    for(int k=0; k<P; k++)
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d ",Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("\n------------------------------------------");
    printf("\t\tRandom Sorted\n");
    sortalh(Arr3D,P,M,N);
    for(int k=0; k<P; k++)
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d ",Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    flag++;

    printf("\n------------------------------------------");
    //˜˜˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    //---------------------------------------------------------------------
    printf("\t\tBackOrdered\n");

    FillArray(Arr3D,P,M,N,flag);
    for(int k=0; k<P; k++)
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d ",Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("\n\n");
    printf("------------------------------------------");
    printf("\t\tBackOrdered Sorted\n");
    sortalh(Arr3D,P,M,N);
    for(int k=0; k<P; k++)
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d ",Arr3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("------------------------------------------");

}
void menu()
{

    int flag1=0;
    printf("Types of output\n");
    printf("1.Time\n");
    printf("2.Sorted arrays\n");
    printf("\n\nChoose one:");
    scanf("%d",&flag1);
    system("cls");
    if(flag1==1)
    {
        int flag1;
        printf("choose sorting algorithm:\n");
        printf("1.Select N2 \n");
        printf("2.Select N8 \n");
        printf("3.Exchange N1(no modifications)\n");
        printf("4.All algorithms\n");
        printf("5.Select N2 for Vector\n");
        printf("6.Select N8 for Vector\n");
        printf("7.Exchange N1 for Vector\n");
        printf("\n\n");
        printf("Enter number of algorithm:");
        scanf("%d", &flag1);
        ArrayMemory(p,m,n);
        int flag=1;
        switch(flag1)
        {
        case 1:
            ArrSortMeasurement(Select2, p, m, n, flag1);
            break;
        case 2:
            ArrSortMeasurement(Select8,p,m,n,flag1);
            break;
        case 3:
            ArrSortMeasurement(Exchange1,p,m,n,flag1);
            break;
        case 4:
            ArrSortMeasurement(Select2,p,m,n,flag);
            printf("\n\n");
            ArrSortMeasurement(Select8,p,m,n,flag+1);
            printf("\n\n");
            ArrSortMeasurement(Exchange1,p,m,n,flag+2);
            break;
        case 5:
            VectorSortMeasurement(VectorSelect2,VectorLenght,1);
            break;
        case 6:
            VectorSortMeasurement(VectorSelect8,VectorLenght,2);
            break;
        case 7:
            VectorSortMeasurement(VectorExchange1,VectorLenght,3);
        default:
            break;
        }
        FreeArrayMemory(p,m,n);
    }
    else
    {
        int P=2, M=3, N=4;
        printf("Sorting Alhorithms:\n");
        printf("1.Select N2 \n");
        printf("2.Select N8 \n");
        printf("3.Exchange N1(no modifications)\n");
        printf("4.Select N2 for Vector\n");
        printf("5.Select N8 for Vector\n");
        printf("6.Exchange N1 for Vector\n");
        printf("\n\n");
        printf("Enter number of algorithm:");
        scanf("%d", &flag1);
        ArrayMemory(p,m,n);
        switch(flag1)
        {
        case 1:
        {
            OutSortArray(Select2);
            break;
        }
        case 2:
        {
            OutSortArray(Select8);
            break;
        }
        case 3:
        {
            OutSortArray(Exchange1);
            break;
        }
        case 4:
        {
            OutSortVector(VectorSelect2);
            break;
        }
        case 5:
        {
            OutSortVector(VectorSelect8);
            break;
        }
        case 6:
        {
            OutSortVector(VectorExchange1);
            break;
        }
        default:
        {
            break;
        }
        }
        FreeArrayMemory(p,m,n);
    }
}
