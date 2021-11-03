#include <iostream>

using namespace std;

int main()
{
    const int i = 10; //Обевляем константы i типа даных int = 10 
    int a; //Обевляем a типа даных int
    a = i * 2; //Присвоение перемене a значение i * 2
    cout << i << endl; //Используя оператор вывода, выводим i
    cout << a << endl; //Используя оператор вывода, выводим a
    cout << --a << endl; //Используя оператор вывода, выводим декримент a
    return 0;
}