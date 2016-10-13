#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
// программа для вычисления значения y при вводимых x
int main()
{
    long double y;
    int x=0;
    std::cout<<"Введите значение x: ";
    std::cin>>x;
    printf("y=x^2+11+sqrt((x^2+11)\n");
    y=((pow(x,2))+11)+sqrt((double(pow(x,2)+11)));
    printf("Ответ: y= %ld",y);
    getch();
    return 0;

}
