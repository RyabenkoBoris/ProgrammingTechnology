//������, �� ������ ����������� ������ �� �������, �������� �� ���������
//���'�� ��� ������ �� �� ����������
#ifndef __CommonVector_H__
#define __CommonVector_H__
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#define p 2    //������� �������
#define n 64   //������� �����
#define m 64  //������� ��������
#define VectorLenght 100000 //����� ������� ��� ��������� ���� ������
extern int*** Arr3D;
int Vector[VectorLenght];//���������� �������
void FillVector(int *A, int N, int flag);//���������� �������
void ArrayMemory(int P, int M, int N);//�������� ���'�� �� �����
void FreeArrayMemory(int P, int M, int N);//��������� ���'�� ������� �� �����
void FillArray(int ***Arr3D, int P, int M, int N, int flag);//���������� ������ ����������
#endif
