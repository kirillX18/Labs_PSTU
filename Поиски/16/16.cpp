#include<iostream>
#include<string>
using namespace std;

int Boir(string pod, string str)
{
	int i;
	int Pos;
	int d[256]{};
	int podl = pod.size();
	int strl = str.size();

	if (podl != 0 && strl != 0)
	{
		for (int i = 0; i < 256; i++)
		{
			d[i] = podl;
		}
		for (int i = podl - 2; i >= 0; i--)
		{
			if (d[int((unsigned char)pod[i])] == podl)
			{
				d[int((unsigned char)pod[i])] = podl - i - 1;
			}
		}
		Pos = podl - 1;
		while (Pos < strl)
		{
			if (pod[podl - 1] != str[Pos])
			{
				Pos += d[int((unsigned char)str[Pos])];
			}
			else
			{
				for (i = podl - 1; i >= 0; i--)
				{
					if (pod[i] != str[Pos - podl + i + 1])
					{
						Pos += d[int((unsigned char)str[Pos - podl + i + 1])];
						break;
					}
					else if (i == 0)
						return Pos - podl + 1;
				}
			}
		}
	}
	return -1;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	string pod;
	string str;
	int y,t;
	cout << "Введите полную строку" << endl;
	cin >> str;

	cout << "Введите подстроку" << endl;
	cin >> pod;

	y = Boir(pod, str);
	if (y != -1)
	{
		t = y + pod.size() - 1;
		str.erase(t, 1);
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	else
	{
		cout << "Нет такой подстроки" << endl;
	}

}