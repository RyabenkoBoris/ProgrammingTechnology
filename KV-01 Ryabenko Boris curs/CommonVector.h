#ifndef COMMONVECTOR_H_INCLUDED
#define COMMONVECTOR_H_INCLUDED
/*module for connecting the necessary libraries, exporting functions and
memory allocation, the module also contains general data about the three-dimensional
array and vector used to calculate the algorithm time*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*The library required to use the clock() function;*/
#include <time.h>
/*Library for working with dynamic data*/
#include <malloc.h>
/*The dimensions of the 3-dimensional array used to calculate the time of the algorithms*/
#define Pt 150000//�-��� ������� ������
#define Mt 16//�-��� ����� � ������ ������ ������
#define Nt 16//�-��� ��������� � ������ ������ ������
// ����� �������, ���� ������������� ��� ��������� ���� ������ ���������
#define VectorLength 150000

//���������� ������� ��� ��������� ��� ��������� ������������ � ��������
int sum[Pt];
// ���������� ����������� ������ ��� ������������ ���� � �����������
extern int*** Arr;
// ���������� ������� ��� ������������ ���� � �����������
int Vector[VectorLength];
//������� �������� �������� ���'�� ��� ������
void array_memory(int P, int M, int N);
// ������� ��� �������� 3-������� �����
void array_fill(int ***Arr, int order, int P, int M, int N);
// ������� ��� �������� ������ .
void vector_fill(int order);
//������� ��������� ���'�� �� ���������� ������
void free_array(int P, int M);
#endif // COMMONVECTOR_H_INCLUDED
