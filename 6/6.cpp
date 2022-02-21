#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	bool Byk = false;
	bool Chr = false;
	int c = 0;
	int t = 0;
	string s;
	cout << "Ведите слова строчными латинскими буквами и цифрами" << endl;
	getline(cin, s);
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] != ' ' && s[i] != '.')
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				Byk = true;
			}
			if (s[i] >= '0' && s[i] <= '9')
			{
				Chr = true;
			}
			t++;
		}
		else
		{
			if (Byk == true && Chr == true)
			{
				Byk = false;
				Chr = false;
				c = i + 1;
				t = 0;
			}
			else
			{
				Byk = false;
				Chr = false;
				s.erase(c, t +1);
				i = -1;
				n = s.length();
				c = 0;
				t = 0;
			}
		}
	}
	cout << s << "." << endl;
}