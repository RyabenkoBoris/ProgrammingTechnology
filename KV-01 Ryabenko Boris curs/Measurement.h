#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED
/*������ ��� ��������� �������� ����������� ������� �����*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// �������� ������� ����� ���� ������ ���������
#define measurements_number 28
// ʳ������ ��������� ���������� �����
#define rejected_number 2
// ʳ������ ��������� ����� � ��������� ����������
// ���� � ������� ������� ��������� �����
// � ������������� ����������
#define min_max_number 3
// ����� ������� ���� ������ ���������
extern clock_t Res[measurements_number];
// ������� ������� � ����������� ������� �����
// ���� ������ ���������
// ������� ���������� �������� ���� ������ ���������.
float MeasurementProcessing();
//�������, ��� ������� �������� ��� ��������� ����������� ������ �� �������� ���� �� �����
void ArrayMeasurement(clock_t (*Func)(int*** Arr, int P, int M, int N),int P, int M, int N, int type);
//�������, ��� ������� �������� ��� ��������� ������� �� �������� ���� �� �����
void VectorMeasurement(clock_t (*Func)(void), int type);
#endif // MEASUREMENT_H_INCLUDED
