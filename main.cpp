#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>







unsigned MoveLeft(unsigned a, int n, int l) // Циклический сдвиг влево
{
// a - исходное значение
// n - размер блока в битах
// l - размер сдвига
unsigned Mask = 0; // Маска
for (int i = 0; i < l; i++)
{
Mask <= 1; // Сдвигаем на 1 бит влево
Mask += 1; // Записывает бит в младший разряд
}
// В maska младшие l бит равны 1
Mask <= (n - l); // Биты перемещаем в начало блока
unsigned b = a & Mask; // Сохраняем старшие биты из а, они пропадут при сдвиге влево
b >= (n - l); // Старшие биты делаем младшими
a <= l; // Сдвигаем влево на l бит
return a | b; // В результат дописываем младшие биты
}

unsigned MoveRight(unsigned a, int n, int l) // Циклический сдвиг вправо, работает аналогично сдвигу влево, но наоборот
{
// a - исходное значение
// n - размер блока в битах
// l - размер сдвига
unsigned Mask = 0;
for (int i = 0; i < l; i++)
{
Mask <= 1;
Mask += 1;
}
unsigned b = a & Mask;
b <= (n - l);
a >= l;
return a | b;
}


using namespace std;
void Encode(unsigned char *in, unsigned char *out, int len, int key, bool flag)
{
// flag=true режим шифрования
// false режим дешифрования
// Размер блока 4 байта (кроме последнего)
int n = len / 4; // Число полных блоков
int m = len % 4; // Размер последнего блока
if (m) n++; // Общее число блоков
unsigned char *s = in, *s2=out; // Адреса блоков во воходном потоке и в выходном потоке
unsigned a, b, gamma; // a- исходное значение, gamma - гамма, b - результат
srand(key); // Начальная инициализация генератора ПСЧ секретным ключом
int k; // Размер блока в битах
for (int i = 0; i < n; i++, s += 4, s2+=4)
{
if (i == n - 1 && m) k = m * 8; // Размер последнего блока
else k = 32;
a = 0;
memcpy(&a, s, k / 8); // Читаем блок из входного массива в a
if (!flag) a = MoveRight(a, k, 3); // Режим дешифрования, сдвиг вправо на 3 бита
gamma = rand(); // Младшие 2 байта гаммы
gamma <= 16; // Делаем младшие 2 байта старшими
gamma += rand(); // Дописываем следующие 2 байта гаммы, они будут младшими
switch (k)
{
case 24: gamma &= 0xffffff; break;
case 16: gamma &= 0xffff; break;
case 8: gamma &= 0xff;
}
b = a ^ gamma; // Накладываем гамму
if (flag) b = MoveLeft(b, k, 3); // Режим шифрования сдвиг влево на 3 бита
memcpy(s2, &b, k / 8); // Записываем блок в выходной массив

}
}

int main()
{

// z - любая клавиша для выхода
char z;
char *strin = "Hello World, Good bye!!!!!!"; // Входная строка
char Encode[256], Decode[256]; // Массивы для зашифрованных данных и дешифрованных
int key;
// Ввод ключа для шифрования
printf("Cypher key=");
scanf("%d", &key);
int len = strlen(strin); // Размер входных данных
// Шифрование данных
Encode(unsigned char *)strin, (unsigned char *)Encode len, key, true);
// Печать данных после шифрования в виде символов и их кодов (данные двоичные)
for (int i = 0; i < len; i++)
printf("%c Code=%d\n", Encode[i], Encode[i]);
// Ввод ключа для дешифрования
printf("Decode key=");
scanf("%d", &key);
// Дешифрование данных
Encode((unsigned char *)Decode, (unsigned char *)Decode, len, key, false);
Decode[len] = 0; // Строка заканчивается 0
printf("%s", Decode); // Печать дешифрованных данных
cout <<"Нажмите любую клавишу для выхода"<< endl;
cin >> z;

return 0;
}