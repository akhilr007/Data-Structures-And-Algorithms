// Nth node from end of linked list 

/*Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Input:
The first line of input contains the number of testcase T. 
For each testcase, the first line of input contains the number of nodes in the linked list and the number N. 
The next line contains L nodes of the linked list.

Output:
For each testcase, output the data of node which is at Nth distance from the end or -1 in case node doesn't exist.

User Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N and you need to return Nth from the end.

Note:
Try to solve in single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 200
1 <= L <= 103
1 <= N <= 103

Example:
Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
10 5 100 5
Output:
8
-1

Explanation:
Testcase 1: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end. 2nd node from end os 8.  
Testcase 2: In the second example, there are 4 nodes in the linked list and we need to find 5th from the end. 
Since 'n' is more than the number of nodes in the linked list, the output is -1.
 */

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

// function to get the nth node from the end of linked list
int getNthFromLast(Node *head, int N)
{

	// if list is empty
	if(head == NULL) return -1;

	// we will be using two pointers for this,i.e. first which will be initialised with nth list from head
	// and second which will start from head
	// and then we will be incrementing both pointers until first becomes null and the position at which second
	// finishes is the desired result.

	Node *first = head;
	for(int i = 0; i < N; i++)
	{
		if (first == NULL) return -1; // it means linked list is shorter than the mentioned position

		first = first->next;  // incrementing the first pointer to the nth node from start.
	}

	Node *second = head;
	while(first != NULL)
	{
		first = first->next;
		second = second->next;
	}

	return second->data;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int L, N;
		cin >> L >> N; // L is length of linked list and N is nth node from end of linked list

		Node *head = NULL, *tail = NULL;
		int x;
		cin >> x;
		head = new Node();
		head->data = x;
		tail = head;

		for(int i = 0; i < L-1; i++)
		{
			cin >> x;
			tail->next = new Node();
			tail->next->data = x;
			tail = tail->next;
		}

		cout << getNthFromLast(head, N) << endl;

	}
	return 0;
}

