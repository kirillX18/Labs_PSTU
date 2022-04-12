#include <iostream>
#include <string>
using namespace std;

class book
{
private:
	string Name;
	string Author;
	int Year;
public:
	void print()
	{
		cout << Name << endl;
		cout << Author << endl;
		cout << Year << endl;
	}
	void vod(string _Name, string _Author, int _Year)
	{
		this->Name =_Name;
		this->Author = _Author;
		this->Year = _Year;
	}
	void def()
	{
		Name = "Гиблое место";
		Author = "Антон Грановский";
		Year = 2009;
	}
	void copy(const book& a)
	{
		Name = a.Name;
		Author = a.Author;
		Year = a.Year;
	}
	~book()
	{
		cout << "Сработал Деструктор" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	book a;
	book b;
	book c;
	string _Name, _Author;
	int _Year;
	cout << "Конструктор с параметрами" << endl;
	cout << "Введите название, автора, год" << endl;
	getline(cin, _Name);
	getline(cin, _Author);
	cin >> _Year;
	a.vod(_Name, _Author, _Year);
	a.print();
	cout << "Конструктор без параметров" << endl;
	b.def();
	b.print();
	cout << "Конструктор копирования" << endl;
	c.copy(a);
	c.print();
}