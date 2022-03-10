#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* ptr_prev = nullptr;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

void pushBack(List& list, int& data)
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
		newnode->ptr_prev = list.tail;
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

void polcot(Node* cont)
{
	cont->ptr_prev->ptr_next = cont->ptr_next;
	cont->ptr_next->ptr_prev = cont->ptr_prev;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	List list;
	int n,k;
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
		if ((cont->data) % 2 == 0)
		{
			polcot(cont);
		}
		cont = cont->ptr_next;
	}
	printList(list);

}