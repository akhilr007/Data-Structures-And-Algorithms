// delete without head pointer

/*You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains the data of the linked list. The last line contains the node to be deleted.

Output:
For each testcase, in a newline, print the linked list after deleting the given node.

Your Task:
This is a function problem. You only need to complete the function deleteNode that takes reference to the node that needs to be deleted. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
1 2
1
4
10 20 4 30
20
Output:
2
10 4 30

Explanation:
Testcase 1: After deleting 1 from the linked list, we have remaining nodes as 2.
Testcase 2: After deleting 20 from the linked list, we have remaining nodes as 10, 4 and 30.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};


//function to search for the node which needs to be deleted
Node *findNode(Node *head, int search_for)
{
	Node *curr = head;

	while(curr != NULL)
	{
		if(curr-> data == search_for)
			break;
		curr = curr->next;
	}

	return curr;
}

// function to delete the node

void deleteNode(Node *node)
{

	/*node->data = node->next->data;
	node->next = node->next->next;*/

	// it may cause memory leak

	if(!node->next)
		return;// if its a last node it cant get deleted

	Node *del = node->next;

	node->data = del->data;
	node->next = del->next;

	free(del);

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
		head = new Node();

		int x;
		cin >> x;
		head->data = x;
		tail = head;

		for(int i = 0; i < n-1; i++)
		{
			cin >> x;
			tail->next = new Node();
			tail->next->data = x;
			tail = tail->next;
		}

		int delNode;
		cin >> delNode;
		Node *del = findNode(head, delNode);

		if(del != NULL and del->next != NULL)
			deleteNode(del);

		printList(head);

	}
	return 0;
}