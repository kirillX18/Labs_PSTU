#include <iostream>

using namespace std;

int main()
{
    int n;
    int t, som = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        t = 1;
        for(int j = i;j <= i * 2;j++)
        {
            t *= j;
        }
        som += t;
    }
cout << som << endl;
}


