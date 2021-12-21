#include <iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	int n = 7;
	bool flag = true;
	int a[7]{ 0, 1, 3, 8, 9, 12, 16 };
	for (int i = 6; i > 0; i--) 
	
	{
		if (a[i] < a[i - 1]) { flag = false; }
	}
	if (flag) {
		cout << "Упорядоченый Масив" << endl;
	}
	else {
		cout << "НЕ упорядоченый Мвсив" << endl;
	}
	return 0;
}