#include <iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	int max, min;
	int a[10];
	max =-10000;
	min = 200000;
	for (int i = 0; i < 10; i++) 
	{
				cin >> a[i];
	}
	for (int i = 0; i < 10; i++) 
	{
		if (a[i] > max) 
		{
			max = a[i];
		}
		else if (a[i] < min) 
		{
			min = a[i];
		}
	}
	cout << "Максимальный элемент: " << max << endl;
	cout << "Минимальный элемент: " << min << endl;
	return 0;
}