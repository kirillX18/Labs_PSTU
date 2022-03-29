#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Ведите длину масива" << endl;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	int mid = -8;
	int k;
	int g = -1;
	int left = 0;
	int right = n - 1;
	bool f = false;
	cout << "Ведите ключ" << endl;
	cin >> k;
	while ((left <= right) && (f != true))
	{
		mid = left + ((k - arr[left]) * (right - left)) / (arr[right] - arr[left]);
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			if (arr[mid] > k)
			{
				right = mid + 1;
			}
			else
			{
				f = true;
			}
		}
	}
	g = mid;
	int j;
	bool o = false;
	cout << "Ведите встовляемое значение" << endl;
	cin >> j;
	int* arr2 = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		//cout << i;
		if (g == i)
		{
			arr2[i] = arr[i];
			i = i + 1;
			arr2[i] = j;
			o = true;
			cout << arr2[1] << arr2[2] << endl;
		}
		else
		{
			if (o == false)
			{
				arr2[i] = arr[i];
			}
			else
			{
				arr2[i] = arr[i-1];
			}
		}	
	}
	delete[] arr;
	for (int i = 0; i < n + 1; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	delete[] arr2;
}