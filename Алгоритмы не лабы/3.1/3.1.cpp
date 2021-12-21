#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
    int n = 20;
    int arr[20];
    int key;
    int r, range_min, range_max;
    range_min = 2;
    range_max = 412;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int j = 1; j < n; j++)
    {
        key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}