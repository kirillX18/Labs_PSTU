#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
	int k = 0;
	int n = 1;
	while (n > k)
	{
		cout << "Введите нижнюю границу: ";
		cin >> n;
		cout << "Введите верхнюю границу: ";
		cin >> k;
		if (n > k)
		{
			cout << "Нижняя граница больше верхней! ОШИБКА!";
		}
	}
	ifstream F1;
	ofstream F2;
	F1.open("F1.txt");
	F2.open("F2.txt");
	string line = "";
	char letter = 'a';
	int cnt = 1;
	int x;
	while (getline(F1, line))
	{
		x = line.length();
		bool f = line[x-1] == letter || line[x-1] == toupper(letter) || line[x-1] == tolower(letter);
		if (f && (cnt > n && cnt < k))
		{
			F2 << line << '\n';
		}
		cnt++;
	}
	F1.close();
	F2.close();
	F1.open("F1.txt");
	cnt = 1;
	int sa;
	int str = 0;
	int max = 0;
	int s;
	while (getline(F1, line))
	{
		x = line.length();
		bool f = line[x - 1] == letter || line[x - 1] == toupper(letter) || line[x - 1] == tolower(letter);
		if (f && (cnt > n && cnt < k))
		{
			str++;
			sa = 0;
			for (int i = 0; i < x; i++)
			{
				if (line[i] == 'A')
				{
					sa++;
				}
			}
			if (sa > max)
			{
				max = sa;
				s = str;
			}
		}
		cnt++;
	}
	F1.close();
	cout << "больше всего букв «А» в строке под номером: " << s << endl;
}