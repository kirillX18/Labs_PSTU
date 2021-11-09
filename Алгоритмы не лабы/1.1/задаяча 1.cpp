

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int a, b, c;
    int max = 0;
    cout << "Ведите три числа" << endl;
    cin >> a >> b >> c;
    if(a > max)
    {
        max = a;
    }
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << max << " максимальное" << endl;
    return 0;

}
