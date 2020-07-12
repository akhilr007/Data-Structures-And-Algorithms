// given a linked list of 0s, 1s and 2s and sort it

/*Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of the linked list and next line contains N elements as the data in the linked list.

Output:
For each test case, segregate the 0s, 1s, and 2s and display the linked list.

Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
8
1 2 2 1 2 0 2 2
4
2 2 0 1
Output:
0 1 1 2 2 2 2 2
0 1 2 2

Explanation:
Testcase 1: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Testcase 2: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.
*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

// function to segregate the list
Node *segregateList(Node *head)
{
	Node *curr = head;
	Node *zero_s = NULL, *zero_e = NULL, *one_s = NULL, *one_e = NULL, *two_s = NULL, *two_e = NULL;

	for(curr = head; curr != NULL; curr = curr->next)
	{
		int x = curr->data;
		if(x == 0)
		{
			if(zero_s == NULL)
				zero_s = zero_e = curr;
			else
			{
				zero_e->next = curr;
				zero_e = zero_e->next;
			}
		}

		else if(x == 1)
		{
			if(one_s == NULL)
				one_s = one_e = curr;
			else
			{	
				one_e->next = curr;
				one_e = one_e->next;
			}

		}

		else
		{
			if(two_s == NULL)
				two_s = two_e = curr;
			else
			{
				two_e->next = curr;
				two_e = two_e->next;
			}
		}
	}

	if(zero_e)
	{
		zero_e->next = one_s;
		if(one_e)
			one_e->next = two_s;
		else
			zero_e->next = two_s;

		if(two_e)
			two_e->next = NULL;
		return zero_s;
	}

	if(one_e)
	{
		one_e->next = two_s;
		if(two_e)
			two_e->next = NULL;
		return one_s;
	}

	return two_s;
}

void printList(Node *head)
{
	Node *curr = head;
	while(curr)
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

		Node *result = segregateList(head);
		printList(result);
	}
	return 0;
}