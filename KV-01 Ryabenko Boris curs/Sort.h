#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include "Measurement.h"
/*������ � ����� �������� ��������� ����������
 ��� ����������� ������ �� �������*/

//�������� ���������� �2 ������ ������� ������ (���������� �����)
clock_t Select2(int*** Arr, int P, int M, int N);
//ó������� �������� "����3 � ����" (���������� �����)
clock_t Select3Exchange(int*** Arr, int P, int M, int N);
//�������� �2 ������ ���������� �����(���������� �����)
clock_t Shell_2(int ***Arr, int P, int M, int N);
//�������� ���������� �2 ������ ������� ������ (������)
clock_t Vect_Select2();
//ó������� �������� "����3 � ����" (������)
clock_t Vect_Select3Exchange();
//�������� �2 ������ ���������� ����� (������)
clock_t Vect_Shell_2();

#endif // SORT_H_INCLUDED
