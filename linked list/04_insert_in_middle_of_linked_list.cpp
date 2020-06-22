// insert in middle of linked list

/*Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

Input:
The first line of input contains the number of test cases T. 
For each test case, the first line contains the length of linked list N and the next line contains N elements to be inserted into the linked list 
and the last line contains the element to be inserted to the middle.

Output:
For each test case, there will be a single line of output containing the element of the modified linked list.

User Task:
The task is to complete the function insertInMiddle() which takes head reference and element to be inserted as the arguments. 
The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
3
1 2 4
3
4
10 20 40 50
30
Output:
1 2 3 4
10 20 30 40 50

Explanation:
Testcase 1: The new element is inserted after the current middle element in the linked list.
Testcase 2: The new element is inserted after the current middle element in the linked list and Hence, the output is 10 20 30 40 50.
 */

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next = NULL;
};


//function to insert in the middle of linked list
Node *insertInMiddle(Node *head, int data)
{
	//we create a new node
	Node *newnode = new Node();
	newnode->data = data;
	newnode->next = NULL;

	// we use two pointers slow and first starting with head
	// slow will be incrementing with one step while fast with two step at a time.
	// so when the first->next and first->next->next reaches null of linked list 
	// slow position is said to be the middle of linked list
	Node *slow = head;
	Node *first = head;

	while(first->next != NULL and first->next->next != NULL)
	{
		slow = slow->next;
		first = first->next->next;
	}

	// after getting the middle we link the new node with respective nodes
	// i.e, slow->next and slow->next with newnode.... 10 20 40 50 .....20 30 40..
	newnode->next = slow->next;
	slow->next = newnode;
	return head;
}

// function to display the linked list
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
		int n, x;
		cin >> n >> x;

		Node *head = new Node();
		head->data = x;

		Node *tail = head;

		for(int i = 0; i < n-1; i++)
		{
			cin >> x;
			tail->next = new Node();
			tail->next->data = x;
			tail = tail->next;
		}

		cin >> x;
		head = insertInMiddle(head, x);
		printList(head);
	}
	return 0;
}