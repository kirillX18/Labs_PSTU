#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<double> S)
{
	int num = S.size();
	for (int i = 0; i < num; i++)
	{
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	stack<double> S;
	stack<double> S2;
	int n;
	int h = 0;
	double k;
	cout << "Впишите размер стека" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		S.push(k);
	}
	printStack(S);
	for (int i = 0; i < n; i++)
	{
		if (S.top() < 0)
		{
			S2.push(S.top());
			S.pop();
			S.push(0);
			h += 1;
		}
		S2.push(S.top());
		S.pop();
	}
	for (int i = 0; i < n+h; i++)
	{
		S.push(S2.top());
		S2.pop();
	}
	printStack(S);
}