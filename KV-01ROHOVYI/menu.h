//������ ��� ���������� � ������������ �� ��������� �� ����� �������� ����������
#ifndef __MENU_H__
#define __MENU_H__
void menu();//������� ����, � ����� ����� �������� ���������� ������ ����-�����
    //� ���������, ��� ��������� �� ����� ����������� ������ ��� ���������
void OutTable(float ordered, float random, float backordered, int flag);
//��������� ������� ���������� ������ ���������
void OutSortArray(clock_t(*sortalh)(int***,int,int,int));
//��������� ���������� ���������� ���������� ������ ��� �������� �����������
//������ �������� ���������(��������� ����������)
void OutSortArray(clock_t(*sortalh)(int***,int,int,int));
//��������� ���������� ���������� ���������� ������� ��� �������� �����������
//������ �������� ���������(��������� ����������)
#endif // __MENU_H__
