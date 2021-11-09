

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    float a,b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "На 0 делить нельзя";
    }
    else
    {
        cout << a / b << endl;
    }
    return 0;
}