// merge sort for linked list

/*Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
First line of input contains number of testcases T. 
For each testcase, first line of input contains number of nodes in the linked list and next line contains N elements of the linked list.

Output:
For each test, in a new line, print the sorted linked list.

Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 105

Note: Try to solve the problem in constant space.

Example:

Input:
2
5
3 5 2 4 1
3
9 15 0
Output:
1 2 3 4 5
0 9 15

Explanation:
Testcase 1: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.
Testcase 2: After sorting the given linked list , resultant will be 0->9->15.
*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *mergeList(Node *a , Node *b)
{
	Node *result = NULL;

	if(a == NULL) return b;

	else if(b == NULL) return a;

	if(a->data <= b->data)
	{
		result = a;
		result->next = mergeList(a->next, b);
	}

	else
	{
		result = b;
		result->next = mergeList(a, b->next);
	}

	return result;
}

void splitList(Node *head, Node **front, Node **back)
{
	Node *fast, *slow;

	if(head == NULL or head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}

	else
	{
		slow = head;
		fast = head->next;

		while(fast != NULL)
		{
			fast = fast->next;

			if(fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*front = head;
		*back = slow->next;
		// splitting the list
		slow->next = NULL;
	}
}

Node *mergeSort(Node *head)
{
	Node *a, *b;

	if(head == NULL or head->next == NULL)
		return head;

	splitList(head, &a, &b);

	a = mergeSort(a);
	b = mergeSort(b);

	return mergeList(a, b);
}

void push(Node **head_ref, int new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
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
	long t;
	cin >> t;

	while(t--)
	{
		Node *head = NULL;

		long n, temp;
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			push(&head, temp);
		}

		head = mergeSort(head);
		printList(head);
	}
	return 0;
}