// rotate a linked list

/*Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.

Input:
The first line of input contains the number of testcases T. 
For each test case, the first line of input contains the length of a linked list and 
the next line contains linked list elements and the last line contains k, by which linked list is to be rotated.

Output:
For each test case, print the rotated linked list.

User Task:
The task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument. 
The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= k <= 103

Example:
Input:
2
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3
Output:
5 6 7 8 1 2 3 4
8 9 2 4 7

Explanation:
Testcase 1: After rotating the linked list by 4 elements (anti-clockwise), 
we reached to node 5, which is (k+1)th node from beginning, now becomes head and tail of the linked list is joined to the previous head.

Testcase 2: After rotating the linked list by 3 elements (anti-clockwise), we will get the resulting linked list as 8 9 2 4 7.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

// function to rotate the linked list from position k
Node *rotateList(Node *head, int k)
{
	Node *curr = head;

	// first we go to the last node to the list
	while(curr->next != NULL)
		curr = curr->next;

	// then connect it to the head node
	curr->next = head;

	// then move the curr pointer to the kth position 
	// from where we have to rotate the array
	while(k--)
	{
		curr = head;
		head = head->next;
	}

	// after getting to the position make the curr->next to null.
	curr->next = NULL;
	// return the head node which will be the next to the curr pointer
	return head;
}

// function to print the linked list
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
		int k;
		cin >> k;

		head = rotateList(head, k);
		printList(head);
	}
	return 0;
}