#include <iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	int n;
	int max = 0;
	int min = 999999999;
	int k = 0;
	cout << "Введите длину последовательности" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cout << "Введите число:" << endl;
		cin >> k;
		if (k > max) 
		{
			max = k;
		}
		if (k < min) 
		{
			min = k;
		}
	}
	cout << "Сумма равна: " << (max + min);
}