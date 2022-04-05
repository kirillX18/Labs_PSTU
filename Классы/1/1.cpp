#include <iostream>
#include <cmath>
using namespace std;

class aj
{
private:
    float first;
    int second;
public:
    void make(float first, int second)
    {
        this->first = first;
        this->second = second;
    }
    
    void element(int j)
    {
        float a_j = first * pow(second, j);
        cout << a_j << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    aj Aj;
    int j, second;
    float first;
    cout << "Введите начальное" << endl;
    cin >> first;
    cout << "Введите константу r" << endl;
    cin >> second;
    if (second > 0)
    {
        Aj.make(first, second);
        cout << "Введите какой элемент ишем" << endl;
        cin >> j;
        Aj.element(j);
    }
    else
    {
        cout << "Недопусимые значения" << endl;
    }
}