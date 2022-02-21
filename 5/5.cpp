#include <iostream>
using namespace std;

void sum(int n, int p,int **a)
{
	int c = 0;
	int s = 0;
	int max = 0;
	for (int i = 0; i < p-1; i++)
	{
		s = 0;
		c += 1;
		for (int j = 0; j < n-c; j++)
		{
			s = s + a[j][i];
		}
		if (s > max)
		{
			max = s;
		}
		cout << s << endl;
	}
	cout << "Максималная сума" << " " << max << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n = 4;
	int p = 3;
	
	int **a = new int*[n];
	for (int l = 0; l < n; l++)
	{
		a[l] = new int[p]{5,2,8};
	}
	
	sum(n, p, a);
	
	for (int k = 0; k < n; k++)
	{
		delete[] a[k];
	}
	
	delete[] a;
}