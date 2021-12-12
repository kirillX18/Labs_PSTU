#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, v;
	bool flag = true;
	cin >> n;
	while (n != 0)
	{
		v = n;
		cin >> n;
		if ((n != 0) && (n < v))
		{
			flag = false;
		}
	}
	if (flag == true)
	{
		cout << "в порядке возрастания" << endl;
	}
	else
	{
		cout << "в не порядке возрастания" << endl;
	}
}