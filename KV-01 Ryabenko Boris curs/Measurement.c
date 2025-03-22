#include "Measurement.h"
#include "CommonVector.h"
#include "Print.h"
/* An array of values for the algorithm's operation time */
clock_t res[measurements_number];
/*Function of processing and averaging the values of measurements of the algorithm operating time*/
float measurement_processing()
{
    long int sum;
    float average_value;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1, k = rejected_number;
    for (int j = 0; j < min_max_number; j++) {
        for (int i = L; i < R; i++) {
            if (res[i] > res[i + 1]) {
                buf = res[i];
                res[i] = res[i + 1];
                res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--) {
            if (res[i] > res[i + 1]) {
                buf = res[i];
                res[i] = res[i + 1];
                res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }

    sum = 0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++) {
        sum = sum + res[i];
    }
    average_value = (float)sum / (float)(measurements_number - 2 * min_max_number - rejected_number);
    return average_value;
}
/*A function that fully processes the time of array sorts
with different types of filling and displays it on the screen*/
void array_measurement(clock_t (*Func)(int*** Arr, int P, int M, int N), int P, int M, int N, int type)
{
    float sorting_time[3];
    srand(time(NULL));
    for(int j = 0; j < 3; j++)
    {
        for (int i = 0; i < measurements_number; i++)
        {
            ArrayFill(Arr, P, M, N, j+1);
            res[i] = Func(Arr, P, M, N);
        }
        sorting_time[j] = measurement_processing();
    }
    /*Display the time table on the screen*/
    OutTable(sorting_time[0], sorting_time[1], sorting_time[2], type);
}
/*A function that fully handles the time of vector sorts
with different types of filling and displays it on the screen*/
void vector_measurement(clock_t (*Func)(void), int type)
{
    float sorting_time[3];
    srand(time(NULL));
    for(int j = 0; j < 3; j++)
    {
        for (int i = 0; i < measurements_number; i++)
        {
            VectorFill(j+1);
            res[i] = Func();
        }
        sorting_time[j] = measurement_processing();
    }
    /*Display the time table on the screen*/
    OutTable(sorting_time[0], sorting_time[1], sorting_time[2], type);
}
