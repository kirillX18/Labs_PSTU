#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RUS");
    int a[5];
    int count = 1;
    int max = -10000;
    for (int i = 0; i < 5; i++) 
    {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++) 
    {
        if (a[i] > max) 
        {
            max = a[i];
            count = 1;
        }
        else if (a[i] == max) 
        {
            count++;
        }
    }
    cout << "Максимальный элемент: " << max << endl;
    cout << "Количество элементов с этим значением: " << count << endl;
    return 0;
}