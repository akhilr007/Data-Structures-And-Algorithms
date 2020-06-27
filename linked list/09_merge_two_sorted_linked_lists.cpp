// merge two sorted linked lists

/*Given two sorted linked lists consisting of N and M nodes respectively. 
The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
First line of input contains number of testcases T. 
For each testcase, first line of input contains N and M, and next two line contains N and M sorted elements in two lines for each.

Output:
For each testcase, print the merged list in sorted form.

User Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments 
and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N, M <= 104
1 <= Node's data <= 105

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 
Output:
2 3 5 10 15 20 40
1 1 2 4

Explanation:
Testcase 1: After merging the two linked lists, we have merged list as 2, 3, 5, 10, 15, 20, 40.
Testcase 2: After merging the given two linked list , we have 1, 1, 2, 4 as output.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *sortedMerge(Node *a, Node *b)
{
	if(a == NULL) return a;
	if(b == NULL) return b;

	Node *head = NULL, *tail = NULL;

	if(a->data <= b->data)
	{
		head = tail = a;
		a = a->next;
	}
	else
	{
		head = tail = b;
		b = b->next;
	}

	while(a != NULL and b != NULL)
	{
		if(a->data <= b->data)
		{
			tail->next = a;
			tail = a;
			a = a->next;
		}

		else
		{
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}

	if(a == NULL) tail->next = b;
	else tail->next = a;

	return head;
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
		int n, m; // length of first linked list
		cin >> n >> m;

		Node *head1 = NULL, *tail1 = NULL;
		int x;
		cin >> x;
		head1 = new Node();
		head1->data = x;
		tail1 = head1;

		for(int i = 0; i < n-1; i++)
		{
			cin >> x;
			tail1->next = new Node();
			tail1->next->data = x;
			tail1 = tail1->next;
		}


		Node *head2 = NULL, *tail2 = NULL;
		int y;
		cin >> y;
		head2 = new Node();
		head2->data = y;
		tail2 = head2;

		for(int i = 0; i < m-1; i++)
		{
			cin >> y;
			tail2->next = new Node();
			tail2->next->data = y;
			tail2 = tail2->next;
		}


		Node *head = sortedMerge(head1, head2);
		printList(head);
	}

	return 0;
}