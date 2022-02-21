#include <iostream>
using namespace std;

void del(int*& mas, int& n)
{
    int* NEW = new int[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        NEW[i - 1] = mas[i];
    }
    n = n - 2; 
    delete[] mas;
    mas = NEW;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    int k;
    cout << "Ведите длину масива" << endl;
    cin >> n;
    int* mas = new int[n];
    cout << "Ведите значения" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }
    cout << "Ведите откуда начать" << endl;
    cin >> k;
    for (int j = k - 1; j < n; j++)
    {
        cout << mas[j] << " ";
    }
    for (int y = 0; y < k-1; y++)
    {
        cout << mas[y] << " ";
    }
    cout << endl;

    del(mas, n);

    for (int l = k - 1; l >= 0; l--)
    {
        cout << mas[l] << " ";
    }
    for (int t = n-1; t > k - 1; t--)
    {
        cout << mas[t] << " ";
    }
    cout << endl;

    delete[] mas;
}