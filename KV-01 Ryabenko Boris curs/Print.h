#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
/*������ � ��������� ��� ���������� ������ ���������� ������ ��������
�� ��� ������ �� ��������� �� ������������*/

//��������� ������� � ����� ���������
void out_table(float ordered, float random, float backordered, int type);
//��������� ���� ���������� �� ���� ����������
void sort(int type);
//��������� ���� ����������
void time(int method, int type);

#endif // PRINT_H_INCLUDED
