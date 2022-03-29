#include<iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	string pod;
	string str;
	int pos;
	cout << "Введите полную строку" << endl;
	cin >> str;

	cout << "Введите подстроку" << endl;
	cin >> pod;

	int i, j, strlen, templlen; int k = 0;

	strlen = pod.size();
	templlen = str.size();
	int* d = new int[templlen];

	i = 0; 
	j = -1;
	d[0] = -1;

	while (i < strlen - 1)
	{
		while (j >= 0 && pod[j] != pod[i])
		{
			j = d[j];
		}
		++i; ++j;
		if (pod[i] == pod[j])
		{
			d[i] = d[j];
		}
		else
		{
			d[i] = j;
		}
	}

	i = 0;
	j = 0;
	for (i = 0, j = 0; (i <= templlen - 1) && (j <= strlen - 1); i++, j++)
	{
		while ((j >= 0) && (pod[j] != str[i]))
		{
			j = d[j];
		}
	}
	delete[]d;
	pos = i - j;
	if ((str[pos] == pod[0]) && (str[pos + 1] == pod[1]))
	{
		str.erase(pos, pod.size());
		str.insert(0, pod);
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	else
	{
		cout << "Нет такой подсроки" << endl;
	}
}