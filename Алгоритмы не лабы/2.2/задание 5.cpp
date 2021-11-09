#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int N, S = 1;
    cout << "Введите значение N натуральных чисел!" << endl;
    cin >> N;
    while (N != 0)
    {
        S = S * N;
        N = N - 1;
    }
    cout << S << endl;
    return 0;
}