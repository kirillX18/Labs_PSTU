#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RUS");
    float n, p, a;
    int i = 1;
    bool flag = false;
    cin >> n >> p;
    while (i <= n && !flag) 
    {
        a = sin(n + i / n);
        if (a == p) 
        {
            flag = true;
        }
        else 
        {
            i++;
        }
    }
    if (flag) 
    {
        cout << "Элемент " << p << " Его номер: " << i << endl;
    }
    else 
    {
        cout << "Элемент не найден" << endl;
    }
    return 0;
}