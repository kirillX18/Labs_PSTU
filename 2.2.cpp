﻿#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS"); //Локализацыя на русском
    int H, m, c, H1, m1, c1, P; //Обевляем H,m,c,H1,m1,c1 типа даных int
    cout << "Введите часы, минуты, секунды начала промежутка" << endl; //Задаём вопрос пользователю используя оператор вывода
    cin >> H >> m >> c; //Используя оператор вода, водим начало промежутка 
    cout << "Введите часы, минуты, секунды конца промежутка" << endl; //Задаём вопрос пользователю используя оператор вывода
    cin >> H1 >> m1 >> c1; //Используя оператор вода, водим конец промежутка
    P = a(H1 - H) * 3600 + (m1 - m) * 60 + (c1 - c); //Находим вё время промежутка в секундах
    H = abs(P / 3600); //Находим количество чесов
    m = abs((P % 3600) / 60); //Находим количество минут
    c = abs(((P % 3600) % 60)); //Находим количество секунд
    cout << H << " часов " << m << " минут " << c << " секунд" << " Продолжительность промежутка"; //Используя оператор вывода, выводим Продолжительность промежутка
    return 0;
}

