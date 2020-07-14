// merge sort on doubly linked list

/*Given Pointer/Reference to the head of a doubly linked list of N nodes, 
the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Input:
There are be multiple test cases, for each test case function mergeSort() will be called separately. 
The only input to the function is the pointer/reference to the head of the doubly linked list.

Output:
For each test, print the sorted doubly linked list in both order i.e. in non-decreasing and non-increasing order.

Your Task:
The task is to complete the function sortDoubly() which sorts the doubly linked list. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
8
7 3 5 2 6 4 1 8
5
9 15 0 -1 0
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
-1 0 0 9 15
15 9 0 0 -1

Explanation:
Testcase 1: After sorting the given linked list in both ways, resultant matrix will be as given in the first two line of output, 
where first line is the output for non-decreasing order and next line is for non-increasing order.
Testcase 2: After sorting the given linked list in both ways, the resultant list will be -1 0 0 9 15 
in non-decreasing order and 15 9 0 0 -1 in non-increasing order.*/


#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

Node *mergeList(Node *first, Node *second)
{
	if(first == NULL) return second;

	if(second == NULL) return first;

	if(first->data <= second->data)
	{
		first->next = mergeList(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = mergeList(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

void partition(Node *head, Node **first, Node **second)
{
	Node *slow = head, *fast = head->next;

	while(fast != NULL and fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	*first = head;
	slow->next->prev = NULL;
	*second = slow->next;
	slow->next = NULL;
}

void mergeSort(Node **head)
{	
	Node *curr = *head;
	if(curr == NULL or curr->next == NULL)
		return;

	Node *first = NULL;
	Node *second = NULL;

	partition(curr, &first, &second);

	mergeSort(&first);
	mergeSort(&second);

	*head = mergeList(first, second);
}

Node *sortDoubly(Node *head)
{
	mergeSort(&head);
	return head;
}

void printList(Node *head)
{
	Node *curr = head;

	while(head)
	{
		cout << head->data << " ";
		curr = head;
		head = head->next;
	}
	cout << endl;

	while(curr)
	{
		cout << curr->data << " ";
		curr = curr->prev;
	}
	cout << endl;
}

void insert(Node **head, int data)
{
	Node *temp = new Node();
	temp->data = data;

	if(*head == NULL)
		*head = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		int x;

		while(n--)
		{
			cin >> x;
			insert(&head, x);
		}
		head = sortDoubly(head);
		printList(head);
	}
	return 0;
}