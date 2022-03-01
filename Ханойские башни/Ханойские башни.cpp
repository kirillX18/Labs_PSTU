#include <iostream>

using namespace std;

int Hanoi(int n, int k, int f, int t)
{
	if (n > 0)
	{
		Hanoi(n - 1, k, t, f);
		cout << k << " => " << f << endl;
		Hanoi(n - 1, t, f, k);
	}
	return 0;
}

int main()
{
	int n; 
	cin >> n;
	Hanoi(n, 1, 2, 3);
	return 0;
}