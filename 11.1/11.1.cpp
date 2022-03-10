#include <iostream>

using namespace std;

struct Node
{
	double data;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

void pushBack(List& list, double& data)
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

void printList(List& list)
{
	Node* currentnode = list.head;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
	cout << endl;
}

void pus0(double& data, Node *cont)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->ptr_next = cont->ptr_next;
	cont->ptr_next = newnode;	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	List list;
	int n;
	double k;
	double t = 0;
	cout << "Введите размер списка: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		pushBack(list, k);
	}
	printList(list);
	Node* cont = list.head;
	while (cont != nullptr)
	{
		if (cont->data < 0)
		{
			pus0(t, cont);
		}
		cont = cont->ptr_next;
	}
	printList(list);
}