//������, �� ������ �� ����� ��������� ��������� ��� ������� �� ������
#ifndef __ALHORITHMS_H__
#define __ALHORITHMS_H__
#include "Common_Vector.h"
//�������� ���������� ������� ������� ������ �2 ���
clock_t Select2(int ***Arr3D, int P, int M, int N);//������
clock_t VectorSelect2(int *A, int N);//�������
//-----------------------------------------------------------
//�������� ���������� ������� ������� ������ �8 ���
clock_t Select8(int ***Arr3D, int P, int M, int N);//������
clock_t VectorSelect8(int *A, int N);//�������
//-----------------------------------------------------------
//�������� ���������� ������� ������� ����� �1 ���
clock_t Exchange1(int ***Arr3D, int P, int M, int N);//������
clock_t VectorExchange1(int *A, int N);//�������
#endif // __ALHORITHMS_H__
