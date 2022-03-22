#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* ptr_next = nullptr;
};

struct Queue
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

void pushBack(Queue& list, int& data)
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.head == nullptr)
	{
		list.head = newnode;
		list.tail = newnode;
	}
	else
	{
		list.tail->ptr_next = newnode;
		list.tail = newnode;
	}
}

void polfront(Queue& list)
{
	Node* t = list.head;
	list.head = t->ptr_next;
	delete t;
}

void printQueue(Queue& list)
{
	Node* currentnode = list.head;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Queue list;
	int n;
	int k;
	double one = true;
	Node* op = nullptr;
	cout << "Введите размер очериди: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		pushBack(list, k);
	}
	printQueue(list);
	Node* cont = list.head;
	while (cont != nullptr)
	{
		if (cont->data % 2 == 0)
		{
			Node* c = list.head;
			while (c->data % 2 != 0)
			{
				pushBack(list, c->data);
				if (one == true)
				{
					op = list.tail;
					one = false;
				}
				c = c->ptr_next;
				polfront(list);
			}
			cont = c->ptr_next;
			polfront(list);
		}
		if (cont->data % 2 != 0)
		{
			cont = cont->ptr_next;
		}
	}
	Node* i = list.head;
	while (i != op)
	{
		pushBack(list, i->data);
		i = i->ptr_next;
		polfront(list);
	}
	printQueue(list);
}
