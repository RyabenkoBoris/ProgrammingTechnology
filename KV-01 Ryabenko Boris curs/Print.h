#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
/*Модуль з функціями для оформлення виводу результатів роботи програми
та для діалогу між програмою та користувачем*/

//Виведення таблиці з часом сортувань
void out_table(float ordered, float random, float backordered, int type);
//Виведення типу сортування та його результатів
void sort(int type);
//Виведення часу сортування
void time(int method, int type);

#endif // PRINT_H_INCLUDED
