#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
// программа для вычисления значения y при вводимых x
int main()
{
    long double y;
    int x;
    std::cout<<"Введите значение x: ";
    std::cin>>x;
    std::printf("y=x^2+11+sqrt((x^2+11)\n");
    y=((pow(x,2))+11)+sqrt((double(pow(x,2)+11)));
    std::printf("Ответ: y= %ld",y);
    return 0;

}