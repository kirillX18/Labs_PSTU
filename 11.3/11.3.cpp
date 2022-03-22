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

void push(List& list, double& data)
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
        newnode->ptr_next = list.head;
        list.head = newnode;
    }
}

void y(List& list2, Node* currentnode)
{
    Node* newnode = new Node;
    newnode->data = currentnode->data;
    if (list2.head == nullptr)
    {
        list2.head = newnode;
        list2.tail = newnode;
    }
    else
    {
        newnode->ptr_next = list2.head;
        list2.head = newnode;
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

void push0(Node* cont, List& list, int i)
{
    List list2;
    double u = 0;
    for (int t =1; t <= i; t++)
    {
        Node* currentnode = list.head;
        y(list2, currentnode);
        list.head = currentnode->ptr_next;
    }
    push(list, u);
    for (int t =1; t <= i; t++)
    {
        Node* currentnode = list2.head;
        y(list, currentnode);
        list2.head = currentnode->ptr_next;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    List list;
    int n;
    double k;
    int i = 0;
    cout << "Ведите размер стека" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        push(list, k);
    }
    printList(list);
    Node* cont = list.head;
    while (cont != nullptr)
    {
        i++;
        if (cont->data < 0)
        {
            push0(cont, list,i);
        }
        cont = cont->ptr_next;
    }
    printList(list);
}