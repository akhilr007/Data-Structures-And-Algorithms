// doubly linked insertion at given position

/*Given a doubly-linked list, a position p, and an integer x. 
The task is to add a new node with value x at the position just after pth node in the doubly linked list.

Input:
The first line of input contains the number of test cases T. 
For each test case, the first line of input contains the number of nodes in the linked list, and next line contains two integers p and x.

Output:
For each testcase, there will be a single line of output which prints the modified linked list.

User Task:
The task is to complete the function addNode() which head reference, position and data to be inserted as the arguments, with no return type.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 200
1 <= N <= 104
0 <= p < N

Example:
Input:
2
3
2 4 5
2 6
4
1 2 3 4
0 44
Output:
2 4 5 6
1 44 2 3 4

Explanation:
Testcase 1: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 3 (0-based indexing).
Testcase 2: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 1 (0-based indexing).*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next = NULL;
	Node *prev = NULL;
};

Node *getNewNode(Node *head, int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

Node *insertAtEnd(Node *head, int data)
{
	Node *newnode = getNewNode(head,data);
	if (head == NULL)
	{
		head = newnode;
		return head;
	}

    Node *curr = head;
	while(curr->next != NULL)
	    curr= curr->next;

    curr->next = newnode;
    newnode->prev= curr->next;
    return head;
}

void addNode(Node *head, int pos, int data)
{
	Node *newnode = getNewNode(head, data);

	Node *temp = head;

	int index = 0;

	while(index < pos)
	{
		temp = temp->next;
		index++;
	}

	if(temp->next == NULL)
	{
		temp->next = newnode;
		newnode->prev = temp;
	}

	else
	{
		newnode->next = temp->next;
		temp->next->prev = newnode;
		temp->next = newnode;
		newnode->prev = temp;
	}

}

void printList(Node *head)
{
	Node *curr = head;
	while(curr != NULL)
	{
		cout << curr->data <<" ";
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
		Node *head = NULL;

		int n;
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			head = insertAtEnd(head, x);
		}

		int pos, x;
		cin >> pos >> x;

		addNode(head, pos, x);
		printList(head);
	}
	return 0;
}