﻿#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS"); //Локализацыя на русском
    char a, b, c, d, f; //Обевляем a,b,c,d,f типа даных char
    cout << "Ведите пять символов" << endl; //Задаём вопрос пользователю используя оператор вывода
    cin >> a >> b >> c >> d >> f; //Используя оператор вода, водим пять символов  
    cout << f << " " << d  << " " << c << " " << b << " " << a << " " << endl; //Используя оператор вывода, выводим пять символов в обратном порядке
    return 0;   
}

