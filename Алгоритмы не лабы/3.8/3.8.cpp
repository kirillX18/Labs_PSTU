#include <iostream>

using namespace std;

int main()
{
int  n,tmp;
n = 11;
int arr[11] = { 41,42,66,87,86,38,77,84,45,35,22 };
for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
cout << endl;
for (int i = 0; i < n / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
cout << endl;
return = 0
}