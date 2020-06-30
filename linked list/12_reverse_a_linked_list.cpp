// reverse a linked list

/*Given a linked list of N nodes. The task is to reverse this list.

Input:
The first line of input contains the number of test cases T. 
For each test case, the first line contains the length of the linked list and the next line contains the elements of the linked list.

Output:
For each test case, print the reversed linked list in a new line.

User Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
6
1 2 3 4 5 6
5
2 7 8 9 10
Output:
6 5 4 3 2 1
10 9 8 7 2

Explanation:
Testcase 1: After reversing the list, elements are 6->5->4->3->2->1.
Testcase 2: After reversing the list, elements are 10->9->8->7->2.
 */

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *reverseList(Node *head)
{
	Node *curr = head;
	Node *prev = NULL;

	while(curr != NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
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

		head = reverseList(head);
		printList(head);
	}

	return 0;
}