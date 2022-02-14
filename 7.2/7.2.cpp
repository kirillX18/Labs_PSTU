#include <iostream>
#include <cmath>
using namespace std;

void func(int n, int t, ...)
{
    int* p = &t;
	while (n--)
	{
		int c = 0;
		int g = *p;
		int e = *p;
		int s = 0;
		int a;
		while (g != 0)
		{
			c++;
			g = g / 10;
		}
		for (int i = 0; i < c; i++)
		{
			a = e % 10;
			s = s + a * pow(8, i);
			e = e / 10;
		}
		cout << s << endl;
		p = p + 2;
		
	}
}

int main()
{
	func(4, 123,467,23,3456);
}

