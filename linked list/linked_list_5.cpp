// detect loop using floyd's cycle detection

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void loopIsHere(Node *head, Node *tail, int pos)
{
    if(pos == 0) 
    	return;

	Node* curr = head;

	for(int i = 1; i < pos; i++)
		curr = curr->next;
	tail->next = curr;
}

bool detectLoop(Node *head)
{
	//we are using two pointers because if a loop exists in a linked list 
	// then two pointers will be equal at some stage.

	// so we intialise the two pointers fast and slow with head
	Node *fast = head, *slow = head;

	// and then we increase slow with one step while increasing the fast pointer with two step
	// meanwhile if two pointers are equal at some stage then we return true and if not then return false.
	while(fast != NULL and fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			return true;
	}
	return false;
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

		int pos;
		cin >> pos;

		loopIsHere(head, tail, pos);

		if(detectLoop(head))
			cout <<"True"<<endl;
		else
			cout <<"False" << endl;
	}
	return 0;
}
