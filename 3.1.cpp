﻿#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS"); //Локализацыя на русском
    int a, b, p; //Обевляем a,b типа даных int
    cout << "Ведите первый множитель" << endl; //Задаём вопрос пользователю используя оператор вывода
    cin >> a; //Используя оператор вода, водим первый множитель 
    cout << "Ведите второй множитель" << endl; //Задаём вопрос пользователю используя оператор вывода
    cin >> b; //Используя оператор вода, водим первый множитель
    p = a * b; //Находим произведение
    cout << "Произведение равно " << p << endl; //Используя оператор вывода, выводим произведение
    return 0;
}