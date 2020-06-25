// remove duplicates element from sorted linked list

/*Given a singly linked list consisting of N nodes. 
The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Input:
First line of input contains number of testcases T. 
For each testcase, first line of input contains length of linked list and next line contains the linked list data.

Output:
For each testcase, there will be a single line of output which contains linked list with no duplicates.

User Task:
The task is to complete the function removeDuplicates() which should remove the duplicates from linked list. 
The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
4
2 2 4 5
5
2 2 2 2 2
Output:
2 4 5
2

Explanation:
Testcase 1: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.
Testcase 2: In the given linked list 2 ->2 ->2 ->2 ->2, 2 is the only element and is repeated 5 times.
 
*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *removeDuplicates(Node *head)
{
	Node *curr = head;
	Node *temp;

	while(curr != NULL and curr->next != NULL)
	{
		if(curr->data == curr->next->data)
		{
			temp = curr->next->next;
			free(curr->next);
			curr->next = temp;
		}
		else
			curr = curr->next;
	}

	return head;
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

		Node *result = removeDuplicates(head);
		printList(result); 
	}
	return 0;
}