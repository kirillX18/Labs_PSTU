#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	int max = 0;
	int num;
	cout << "Введите длину последовательности:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cout << "Введите число:" << endl;
		cin >> num;
		if (num > max) 
		{
			max = num;
		}
	}
	cout << "Max элемент: " << max;
}