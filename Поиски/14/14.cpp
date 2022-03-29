#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Впишите даные" << endl;
    getline(cin, s);
    int t;
    t = s.size();
    for (int i = 0; i < t; i++)
    {
        if (s[i] % 2 == 0)
        {
            s.erase(i, 1);
            t--;
            i--;
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << s[i];
    }
    cout << endl; 
}