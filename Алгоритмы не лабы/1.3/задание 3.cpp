﻿#include <iostream>

using namespace std;

int main()
{
    float a;
    cin >> a;
    if (a < 5)
    {
        cout << a * 3 << endl;
    }
    if ((a >= 5) and (a <= 7))
    {
        cout << a / 10 << endl;
    }
    if (a > 7)
    {
        cout << a + 3 << endl;
    }
    return 0;
}