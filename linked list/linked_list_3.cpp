// doubly linked list implementation 

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next = NULL;
	Node *prev = NULL;
};

//function to get the new node
Node *getNewNode(Node *head,int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

Node *insertAtHead(Node *head,int data)
{
	Node *newnode = getNewNode(head,data);
	if (head == NULL)
	{
		head = newnode;
		return head;
	}

	head->prev = newnode;
	newnode->next = head;
	head = newnode;
	return head;
}

void printList(Node *head)
{
	Node *curr = head;
	cout << "forward list: ";
	while(curr != NULL)
	{
		cout << curr->data <<" ";
		curr = curr->next;
	}
	cout << endl;
}

void reversePrint(Node *head)
{
	Node *curr = head;

	if (curr == NULL) return; // empty list

	// going to last node
	while(curr->next != NULL)
		curr = curr->next;
	
	cout << "reverse list is: ";
	while(curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->prev;
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
		head = insertAtHead(head, x);
		printList(head);
		reversePrint(head);
	}
	return 0;
}