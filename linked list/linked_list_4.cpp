//  reverse a linked list using recursion

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *reverseList(Node *curr, Node *prev)
{	// base condition for the recursion to terminate
	if(curr == NULL)
		return prev;

	Node *next = curr->next;
	curr->next = prev;
	return reverseList(next, curr);
}

void printList(Node *head)
{
	Node *curr = head;
	while(curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		Node *head = NULL, *tail = NULL;
		int x;
		cin >> x;

		head = new Node();
		head->data = x;
		tail = head;

		for(int i = 0; i < n-1; i++)
		{
			cin >> x;
			tail->next = new Node();
			tail->next->data = x;
			tail = tail->next;
		}

		Node *prev = NULL;
		head = reverseList(head, prev);
		printList(head);
	}
	return 0;
}