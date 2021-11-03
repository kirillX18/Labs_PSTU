#include <iostream>

using namespace std;

int main()
{
    int i = 1; //Обевляем i типа даных int
    int a;//Обевляем a типа даных int
    a = ++i * i++; //Считаем пример ++i=2 и i++=2 2*2=4
    cout << a << endl; //Используя оператор вывода, выводим ответ
    return 0;
}