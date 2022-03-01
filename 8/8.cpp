#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

struct car
{
    string mark;
    int god_vpys;
    int cina;
    string color;
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    ofstream sportteam;
    sportteam.open("t.txt");
    int r;
    cout << "Ведите год выпуска который будет удалён" << endl;
    cin >> r;
    while (r > 2022 || r < 1)
    {
        cout << "Вы ввели недопустимое число! Введите правильно: ";
        cin >> r;
    }
    car Pajero = { "Mitsubishi",2004,730000,"серебристый" };
    car Series = { "BMW",2008,920000,"черный" };
    car X50 = { "Lifan",2017,555000,"белый" };
    car Camry = { "Toyota",2008,730000,"серый" };
    int n = 4;
    car* cars = new car[7];
    cars[0] = Pajero;
    cars[1] = Series;
    cars[2] = X50;
    cars[3] = Camry;
    car plys;
    if (!sportteam.is_open())
    {
        cout << "Ошибка открытия файла!";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            sportteam << "марка: " << cars[i].mark << endl << "год выпуска: " << cars[i].god_vpys << endl << "цена: " << cars[i].cina << endl << "цвет: " << cars[i].color << "\n\n";
        }
        sportteam << "\n";
        SetConsoleCP(1251);
        cout << "Добавьте еще одну машину" << endl;
        cin.ignore(32767, '\n');
        cout << "марка: ";
        getline(cin, plys.mark);
        cout << "год выпуска: ";
        cin >> plys.god_vpys;;
        cout << "цена: ";
        cin >> plys.cina;
        cout << "цвет: ";
        getline(cin, plys.color);
        sportteam << "марка: " << plys.mark << endl << "год выпуска: " << plys.god_vpys << endl << "цена: " << plys.cina << endl << "цвет: " << plys.color << "\n\n";
        for (int i = 0; i < n; i++)
        {
            if (cars[i].god_vpys != r)
            {
                sportteam << "марка: " << cars[i].mark << endl << "год выпуска: " << cars[i].god_vpys << endl << "цена: " << cars[i].cina << endl << "цвет: " << cars[i].color << "\n\n";
            }
        }
    }
    sportteam.close();

}