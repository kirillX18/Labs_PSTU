#include <iostream>
using namespace std;

int b[8][8];

void setQu(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		++b[x][j];
		++b[i][x];
		int f;
		f = j - i + x;
		if (f >= 0 && f < 8)
		{
			++b[x][f];
		}
		f = j + i - x;
		if (f >= 0 && f < 8)
		{
			++b[x][f];
		}
	}
	b[i][j] = -1;
}

void resetQu(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		--b[x][j];
		--b[i][x];
		int f;
		f = j - i + x;
		if (f >= 0 && f < 8)
		{
			--b[x][f];
		}
		f = j + i - x;
		if (f >= 0 && f < 8)
		{
			--b[x][f];
		}
	}
	b[i][j] = 0;
}

bool tryQu(int i)
{
	bool res = false;
	for (int j = 0; j < 8; j++)
	{
		if (b[i][j] == 0)
		{
			setQu(i, j);
			if (i == 7)
			{
				res = true;
			}
			else
			{
				if (!(res = tryQu(i + 1)))
				{
					resetQu(i, j);
				}
			}
		}
		if (res)
		{
			break;
		}
	}
	return res;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			b[i][j] = 0;
		}
	}
	tryQu(0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == -1)
			{
				cout << " X ";
			}
			else
			{
				cout << " * ";
			}
		}
		cout << endl;
	}
	return 0;
}