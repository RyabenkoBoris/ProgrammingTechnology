#include "Menu.h"
#include <stdlib.h>
#include <stdio.h>
void menu()
{
    int a;
    while(1)
    {
        //Вибір показу сортування або часу сортування
        printf("\n1. Sorting\n");
        printf("\n2. Time measurement\n");
        printf("\n\nEnter a number to select (press '0' to exit):");
        scanf(" %d", &a);
        switch(a)
        {
        case(1):
            system("cls");
            //Вибір методу сортування тривимірного масиву
            printf("\n1. Sorting algorithm #2 direct selection method\n");
            printf("\n2. Hybrid algorithm 'choice #3 - exchange'\n");
            printf("\n3. Algorithm #2 of the Shell sorting method\n");
            printf("\n\nEnter a number to select (press '0' to exit):");
            scanf(" %d", &a);
            switch(a)
            {
            case(1):
                Sort(1);
                break;
            case(2):
                Sort(2);
                break;
            case(3):
                Sort(3);
                break;
            case(0):
                exit(1);
            }
            break;
        case(2):
            system("cls");
            //Вибір виведення часу сортування тривимірного масиву або вектора
            printf("\n1. Sorting algorithm #2 direct selection method (array)\n");
            printf("\n2. Hybrid algorithm 'choice #3 - exchange' (array)\n");
            printf("\n3. Algorithm #2 of the Shell sorting method (array)\n");
            printf("\n4. All methods for array \n");
            printf("\n5. Sorting algorithm #2 direct selection method (vector)\n");
            printf("\n6. Hybrid algorithm 'choice #3 - exchange' (vector)\n");
            printf("\n7. Algorithm #2 of the Shell sorting method (vector)\n");
            printf("\n8. All methods for vector \n");
            printf("\n\nEnter a number to select (press '0' to exit):");
            scanf(" %d", &a);
            switch(a)
            {
            case(1):
                Time(1, 1);
                break;
            case(2):
                Time(1, 2);
                break;
            case(3):
                Time(1, 3);
                break;
            case(4):
                Time(1, 4);
                break;
            case(5):
                Time(2, 1);
                break;
            case(6):
                Time(2, 2);
                break;
            case(7):
                Time(2, 3);
                break;
            case(8):
                Time(2, 4);
                break;
            case(0):
                exit(1);
            }
            break;
        case(0):
            exit(1);
        }
    }
}
