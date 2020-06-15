// linked list---insert node at the end of a list 

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

Node *insertEnd(Node *head, int key)
{
	if(head == NULL)
		return new Node(key);
	Node *curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = new Node(key);
	return head;
}

void printList(Node *head)
{
	Node *curr = head;
	cout << "List is: ";
	while(curr != NULL)
	{
		cout << curr->key <<" ";
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;
	cout << "Enter how many numbers: ";
	int n;
	cin >> n;

	int x;
	for(int i = 0; i < n; i++)
	{
		cout <<"Enter a number: ";
		cin >> x;
		head = insertEnd(head, x);
		printList(head);
	}
	return 0;
}