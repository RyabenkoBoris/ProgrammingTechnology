#include "Measurement.h"
#include "CommonVector.h"
#include "Print.h"
// Масив значень часу роботи алгоритма
clock_t Res[measurements_number];
// Функція обробки і усереднення значень вимірів часу роботи алгоритма
float MeasurementProcessing()
{
    long int Sum;
    float AverageValue;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1, k = rejected_number;
    for (int j = 0; j < min_max_number; j++)
    {
        for (int i = L; i < R; i++)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }

    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
        Sum = Sum + Res[i];
    AverageValue = (float)Sum / (float)(measurements_number - 2*min_max_number - rejected_number);
    return AverageValue;
}
//Функція, яка повністю оброблює час сортувань масиву
//при різних видах заповнення та виводить його на екран
void ArrayMeasurement(clock_t (*Func)(int*** Arr, int P, int M, int N),int P, int M, int N, int type)
{
    float Sorting_time[3];
    srand(time(NULL));
    for(int j = 0; j < 3; j++)
    {
        for (int i = 0; i < measurements_number; i++)
        {
            ArrayFill(Arr, P, M, N, j+1);
            Res[i] = Func(Arr, P, M, N);
        }
        Sorting_time[j] = MeasurementProcessing();
    }
    //Вивід таблиці часу на екран
    OutTable(Sorting_time[0], Sorting_time[1], Sorting_time[2], type);
}
//Функція, яка повністю оброблює час сортувань вектора
//при різних видах заповнення та виводить його на екран
void VectorMeasurement(clock_t (*Func)(void), int type)
{
    float Sorting_time[3];
    srand(time(NULL));
    for(int j = 0; j < 3; j++)
    {
        for (int i = 0; i < measurements_number; i++)
        {
            VectorFill(j+1);
            Res[i] = Func();
        }
        Sorting_time[j] = MeasurementProcessing();
    }
    //Вивід таблиці часу на екран
    OutTable(Sorting_time[0], Sorting_time[1], Sorting_time[2], type);
}
