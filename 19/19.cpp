#include <iostream>
#include <string>

using namespace std;

int collis = 0;

struct Hemen
{
	Hemen()
	{
		_fylname = "Null";
		_address = "Null";
		_data_roz = "Null";
    }
    string _fylname;
    string _address;
    string _data_roz;
};

string name[20]{ "Александр","Сергей","Владимир","Елена","Татьяна","Андрей","Алексей","Ольга","Николай","Наталья","Анна","Иван","Дмитрий","Ирина","Мария","Михаил","Светлана","Екатерина","Евгений","Виктор" };
string surname[20]{ "Смирнов","Иванов","Кузнецов","Соколов","Попов","Лебедев","Козлов","Новиков","Морозов","Петров","Волков","Соловьёв","Васильев","Зайцев","Павлов","Семёнов","Голубев","Виноградов","Богданов","Воробьёв" };
string patronymic[20]{ "Герасимович","Андреевич","Евгеньевич","Валентинович","Валерьевич","Владимирович","Михайлович","Павлович","Александрович","Николаевич","Сасунович","Владиславович","Игоревич","Леванович","Леонидович","Алегов","Ахметов","Борисович","Гермонов","Олегович" };
string address[20]{ "Нейбута, 27","Адмирала Кузнецова, 52б","Анны Щетининой, 22","Громова, 12","проспект Красного Знамени, 23","Океанский проспект, 98","Крыгина, 28","Тигровая, 26","Хабаровская, 19","Луговая, 65","Ладыгина, 2","Кипарисовая, 6","Чкалова, 15","Аллилуева, 10","Невельского, 31","Светланской, 119б","Нерчинской, 27","Октябрьской, 16","проспекте Красного Знамени, 94","Героев Варяга, 12" };
string data_roz[10]{ "12.15.2004","30.6.2017","23.4.1978","11.10.2008","6.11.2010","7.9.2007","10.10.2011","2.4.1999","9.3.2003","11.10.2010" };

struct hash_table
{
	Hemen* arr;
	hash_table(int size)
	{
		arr = new Hemen[size];
	}
	void add(Hemen tmp, int size);
	void findIndex(string _fylname, int size);
};


string rand_name()
{
	return (surname[rand() % 20] + " " + name[rand() % 20] + " " + patronymic[rand() % 20]);
}
string rand_address()
{
	return address[rand() % 20];
}
string rand_data()
{
	return data_roz[rand() % 10];
}

Hemen create_human()
{
	Hemen tmp;
	tmp._fylname = rand_name();
	tmp._data_roz = rand_data();
	tmp._address = rand_address();
	return tmp;
}


void fill_human(Hemen* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = create_human();
	}
}

void show(const Hemen tmp)
{
	cout << "ФИО:          " << tmp._fylname
		<< "\nАдрес:	   " << tmp._address
		<< "\nДата:        " << tmp._data_roz << endl << endl;
}

void showTable(hash_table* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(table->arr[i]);
	}
}

void print_human(Hemen* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		show(arr[i]);
	}
}

int hash_f(string str, int size)
{
	long double a = (0.68 * stoi(str));
	double a1 = size * (a - static_cast<int>(a));
	return static_cast<int>(a1);
}

void hash_table::add(Hemen tmp, int size)
{
	int index = hash_f(tmp._data_roz, size);
	int hash = index;
	if (arr[index]._address == "Null")
	{
		arr[index] = tmp;
		return;
	}
	else
	{
		while (index < size)
		{
			if (arr[index]._address == "Null")
			{
				arr[index] = tmp;
				return;
			}
			index++;
			collis++;
		}
		if (index >= size)
		{
			index = 0;
			collis++;
			while (index < hash)
			{
				if (arr[index]._address == "Null")
				{
					arr[index] = tmp;
					return;
				}
				index++;
				collis++;
			}
		}
	}
}

void hash_table::findIndex(string _fylname, int size)
{
	int hash = hash_f(_fylname, size);
	int index = hash;
	while (arr[index]._fylname != _fylname && index < size)
	{
		index++;
	}
	if (index >= size)
	{
		index = 0;
		while (arr[index]._fylname != _fylname && index < hash)
		{
			index++;
		}
		if (index >= hash)
		{
			cout << "Такого человека нет";
		}
		else
		{
			cout << "Такой человек есть по индексу: " << index << endl << endl;
		}
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите кол-во элементов: ";
	cin >> size;
	cout << endl;
	Hemen* arr = new Hemen[size];
	hash_table table(size);
	fill_human(arr, size);
	for (int i = 0; i < size; i++)
	{
		table.add(arr[i], size);
	}
	showTable(&table, size);
	table.findIndex("346356", size);
	cout << endl << endl;
	cout << "Кол-во коллизий для " << size << " записей: " << collis << endl;
	delete[] arr;
	return 0;
}