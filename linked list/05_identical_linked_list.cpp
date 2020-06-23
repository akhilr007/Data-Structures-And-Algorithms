// identical linked lists

/*Given two Singly Linked List of N and M nodes respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.

Input:
The first line of input contains the number of test cases T. 
For each test case, the first line of input contains the length of linked lists N and M and the next line contains elements of the linked lists.

Output:
For each test, the output will be 'Identical' if two lists are identical else 'Not identical'.

User Task:
The task is to complete the function areIdentical() which takes the head of both linked lists as arguments and returns True or False.

Constraints:
1 <= T <= 100
1 <= N <= 103

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Example:
Input:
2
6
1 2 3 4 5 6
4
99 59 42 20
5
1 2 3 4 5
5
1 2 3 4 5
Output:
Not identical
Identical

Explanation:
Testcase 1: Each element of the first linked list is not equal to each elements of the second linked list in the same order.
Testcase 2: Each element of the first linked list is equal to each elements of the second linked list in the same order.
 */

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next = NULL;
};

// function to check if two linked lists are identical are not.
bool areIdentical(Node *head1, Node *head2)
{
	if(head1 == NULL and head2 == NULL) return true;

	if(head1 == NULL or head2 == NULL) return false;

	if(head1->data != head2->data) return false;

	return areIdentical(head1->next, head2->next);
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, m, x, y, temp;

		Node *head1 = NULL, *tail1 = NULL;
		Node *head2 = NULL, *tail2 = NULL;

		cin >> n; // length of first of linked list

		cin >> x; // data value of the first node.

		head1 = new Node();
		head1->data = x;
		tail1 = head1;

		for(int i = 0; i < n-1; i++)
		{
			// inserting the value at the end of a list
			cin >> temp;
			tail1->next = new Node();
			tail1->next->data = temp;
			tail1 = tail1->next;
		}

		cin >> m; // length of second linked list
		cin >> y; // data value of first node of second linked list

		head2 = new Node();
		head2->data = y;
		tail2 = head2;

		for(int i = 0; i < m-1; i++)
		{
			cin >> temp;
			tail2->next = new Node();
			tail2->next->data = temp;
			tail2 = tail2->next;
		}

		areIdentical(head1, head2)?cout<<"Identical"<<endl:cout<<"Not identical"<<endl;

	}
	return 0;
}