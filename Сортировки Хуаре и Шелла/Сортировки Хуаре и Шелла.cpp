#include <iostream>
#include<ctime>
#include<cmath>
using namespace std;

void Shell1(int arr[], int n)
{
	int d = n / 2;

	while (d > 0)
	{
		for (int i = 0; i < n - d; i++)
		{
			int j = i;
			while (j >= 0 && arr[j] > arr[j + d])
			{
				int temp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = temp;

				j--;
			}
		}
		d = d / 2;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Shell1_vod()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Ведиите количество элиментов" << endl;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		arr[i] = rand() % 20 + 1;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	Shell1(arr, n);



	delete[] arr;
}

void swap(int arr[], int pos1, int pos2) {
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else {
			swap(arr, i, j);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}
void quickSort_vod()
{
	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";

	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int g;
	cout << "1 - Сартировка Хуаре 2 - Сортировка Шелла" << endl;
	cin >> g;
	switch (g)
	{
	case 1:
		quickSort_vod();
		break;
	case 2:
		Shell1_vod();
		break;
	}

}