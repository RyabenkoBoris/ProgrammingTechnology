#include "Measurement.h"
#include "Common_Vector.h"
#include "menu.h"
// ����� ������� ���� ������ ���������
clock_t Res[measurements_number];
float MeasurementProcessing()
{
 long int Sum;
 float AverageValue;
//-----------------------------------------------------------
/* �������� ����������� ���������� �����:
���� 1. ³��������� rejected_number ������ ����� � ���������
�� 0 �� rejected_number-1.
���� 2. ����� ����� �������� ��������� min_max_number ����� � ���������� ���������� �� min_max_number ����� � ������������� ����������, � ����� �������� ��.
���� 3. ��������� ������ �������� �����, �� ����������.
*/
//-----------------------------------------------------------
/* ���� 1. ��� ��������� ����� 1 ������ �������� �������� �
������� rejected_number.
*/
/* ���� 2.
��� ����������� min_max_number ��������� � ������������
������� ����� �������� min_max_number �������� ���������
����� ��������� ���������� ���������� � ������� ������� ��
rejected_number �� measurements_number-1.
� ���������, min_max_number ��������� ������� ����� ������ ����������� �� �������� � ������� ������� ��
rejected_number �� rejected_number+min_max_number-1, �
min_max_number ������������ ������� ����� � �� �������� �
������� ������� �� measurements_number-min_max_number ��
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

// ���� 3.
/* ��������� ������ �������� ����� ���� ���������
rejected_number ������ ����� �� min_max_number ����� �
���������� ���������� � min_max_number ����� � ������������� ����������, ����� ������ �������� ����� � �������
������� �� rejected_number + min_max_number ��
measurements_number - min_max_number - 1.
*/
 Sum=0;
 for (int i = rejected_number + min_max_number; i <
measurements_number - min_max_number; i++)
 Sum = Sum + Res[i];
/* ʳ������ �����, �� ���������� ��� ���������� ����������
��������, �������
measurements_number � 2 * min_max_number - rejected_number
*/
 AverageValue = (float)Sum / (float)(measurements_number -
2*min_max_number - rejected_number);
 return AverageValue;
}

// ��������� ���������� ������ ��������� ���������� ������
void ArrSortMeasurement(clock_t (*abc)(int*** Arr3D, int P, int M, int N),int P, int M, int N, int flag)
{
    float R[3];//������, �� ������ ��� ���������� �������� ������ ���������
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
// ��������� ���������� ������ ��������� ���������� �������
void VectorSortMeasurement(clock_t (*abc)(int* A, int N),int N, int flag)
{
    float R[3];//������, �� ������ ��� ���������� �������� ������ ���������
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
