#include <iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> S)
{
	int num = S.size();
	for (int i = 0; i < num; i++)
	{
		cout << S.front() << " ";
		S.pop();
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	queue<int> S;
	int n;
	int k;
	cout << "Впишите размер очередь" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		S.push(k);
	}
	printQueue(S);
	for (int i = 0; i < n; i++)
	{
		if (S.front() % 2 != 0)
		{
			S.push(S.front());
		}
		S.pop();
	}
	printQueue(S);
}