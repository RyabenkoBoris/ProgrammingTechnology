#include "Measurement.h"
#include "Common_Vector.h"
#include "menu.h"
// Масив значень часу роботи алгоритма
clock_t Res[measurements_number];
float MeasurementProcessing()
{
 long int Sum;
 float AverageValue;
//-----------------------------------------------------------
/* Методика усереднення результатів виміру:
Крок 1. Відкидається rejected_number перших вимірів з індексами
від 0 до rejected_number-1.
Крок 2. Серед інших елементів знаходимо min_max_number вимірів з мінімальними значеннями та min_max_number вимірів з максимальними значеннями, і також відкидаємо їх.
Крок 3. Знаходимо середнє значення вимірів, що залишилися.
*/
//-----------------------------------------------------------
/* Крок 1. Для виконання Кроку 1 просто починаємо алгоритм з
індексу rejected_number.
*/
/* Крок 2.
Для знаходження min_max_number мінімальних і максимальних
значень вимірів виконуємо min_max_number ітерацій головного
цикла алгоритму шейкерного сортування в діапазоні індексів від
rejected_number до measurements_number-1.
В результаті, min_max_number мінімальних значень вимірів будуть знаходитись на позиціях в діапазоні індексів від
rejected_number до rejected_number+min_max_number-1, а
min_max_number максимальних значень вимірів – на позиціях в
діапазоні індексів від measurements_number-min_max_number до
measurements_number-1.
*/
 clock_t buf;
int L = rejected_number, R = measurements_number - 1;
int k = rejected_number;
for (int j=0; j < min_max_number; j++) {
for (int i = L; i < R; i++) {
if (Res[i] > Res[i + 1]) {
buf = Res[i];
Res[i] = Res[i + 1];
Res[i + 1] = buf;
k = i;
}
}
R = k;
for (int i = R - 1; i >= L; i--) {
if (Res[i] > Res[i + 1]) {
buf = Res[i];
Res[i] = Res[i + 1];
Res[i + 1] = buf;
k = i;
}
}
L = k + 1;
}

// Крок 3.
/* Знаходимо середнє значення вимірів після відкидання
rejected_number перших вимірів та min_max_number вимірів з
мінімальними значеннями і min_max_number вимірів з максимальними значеннями, тобто середнє значення вимірів в діапазоні
індексів від rejected_number + min_max_number до
measurements_number - min_max_number - 1.
*/
 Sum=0;
 for (int i = rejected_number + min_max_number; i <
measurements_number - min_max_number; i++)
 Sum = Sum + Res[i];
/* Кількість вимірів, що залишилась для обчислення середнього
значення, дорівнює
measurements_number – 2 * min_max_number - rejected_number
*/
 AverageValue = (float)Sum / (float)(measurements_number -
2*min_max_number - rejected_number);
 return AverageValue;
}

// виведення результатів роботи алгоритму сортування масиву
void ArrSortMeasurement(clock_t (*abc)(int*** Arr3D, int P, int M, int N),int P, int M, int N, int flag)
{
    float R[3];//вектор, що містить вже опрацьовані значення роботи алгоритму
    srand(time(NULL));
    for(int j=0; j<3; j++)
    {
    for (int i = 0; i < measurements_number; i++) {
        FillArray(Arr3D,P, M, N,j+1);
        Res[i] = abc(Arr3D,P,M,N);
        }
    R[j] = MeasurementProcessing();
    }
    OutTable(R[0], R[1], R[2], flag);
}
// виведення результатів роботи алгоритму сортування вектора
void VectorSortMeasurement(clock_t (*abc)(int* A, int N),int N, int flag)
{
    float R[3];//вектор, що містить вже опрацьовані значення роботи алгоритму
    srand(time(NULL));
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<measurements_number;i++)
        {
            FillVector(Vector,N,j+1);
            Res[i] = abc(Vector,N);
        }
        R[j]=MeasurementProcessing();
    }
    OutTable(R[0],R[1],R[2], flag);
}
