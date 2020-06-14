// implementation of linked list----insertion of node at beginning of list

#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *next;
	Node(int x)
	{
		key = x;
		next = NULL;
	}
};

Node *insertBegin(Node *head, int key)
{
	Node *temp = new Node(key);
	temp->next = head;
	return temp;
}

void printList(Node *head)
{
	Node *curr = head;
	cout << "List is : ";
	while(curr != NULL)
	{
		cout << curr->key << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;
	cout << "Enter how many numbers : ";
	int n;
	cin >> n;

	int x;
	for(int i = 0; i < n; i++)
	{
		cout <<"Enter the number : ";
		cin >> x;
		head = insertBegin(head, x);
		printList(head);
	}
	return 0;
}