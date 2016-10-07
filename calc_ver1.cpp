#include <iostream>

int c;
//float g;
using namespace std;
double summary(float a, float b); // сумма двух чисел
double division(float a, float b); // деление
double multiplication(float a, float b);
double  sub(float a, float b);
double  involutioin(float a, float c);
double square_root(float a); //произведение, Разность, возведение в степень, квадратный корень

int main() {

    setlocale(LC_ALL,"rus");
    float a=1.728,b=2.418;
    int c=16;
    //float g=0.5;
    //double square_root(float a, float b)
    //{   return ()}
    std::cout<<"\nCумма равна: " << summary(a,b);
    std::cout<<"\nРазность равна: "<< sub(a,b);
    std::cout<<"\nПроизведение равно: "<< multiplication(a,b);
    std::cout<<"\nЧастное равно: "<< division(a,b);
    std::cout<<"\na в степени c равно: "<< involutioin(a,c);
    std::cout<<"\nквадратный корень из а равен: "<<square_root(c) ;


    return 0;
}


double summary(float a, float b)
{
    return  a+b;
}

double sub (float a, float b)
{
    return a-b;
}

double  multiplication (float a, float b)
{
    return a*b;
}

double division (float a, float b)
{
    return a/b;
}

double involutioin (float a, float c)
{
    double  result = a;
    for(int i = 1; i <c; i++)
    {
        result *=a;
    }

    return result;
}
double square_root(float c)
{
    float z =0;
    while (z*z < c){
        z++;
    }

    return z;
}


