﻿#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int spaces = n / 2;
	int stars = 1;
	for (int i = 1; i <= (n + 1) / 2; i++)
	{
		for (int j = 1; j <= spaces; j++)
		{
			cout << "  ";
		}
		spaces--;
		for (int k = 1; k <= stars; k++)
		{
			cout << "* ";
		}
		stars += 2;
		cout << endl;
	}
}
