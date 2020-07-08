// pairwise swap of nodes in linked list

/*Given a linked list of N positive integers. You need to swap elements pairwise. Your task is to complete the function pairwise_swap().

Input:
The input line contains T, denoting the number of testcases. 
Each testcase contains two lines, the first line contains N(size of linked list). 
The second line contains N elements of linked list separately.

Output:
For each testcase, in new line, print the modified linked list.

User Task:
Since this is a functional problem you don't have to worry about input and output, you just have to complete the function pairwise_swap(). 
The printing is done automatically by the driver code.

Constraint:
1 <= T <= 100
1 <= N <= 100
1 <= Node values <= 1000

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Example:
Input:
2
7
1 2 3 4 5 6 7
6
1 2 3 4 5 6
Output:
2 1 4 3 6 5 7
2 1 4 3 6 5

Explanation:
Testcase 1: The linked list after swapping becomes: 1 2 3 4 5 6 7 -> 2 1 4 3 6 5 7.
Testcase 2: The linked list after swapping becomes: 1 2 3 4 5 6 -> 2 1 4 3 6 5.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

// function to print the linked list
void printList(Node *head)
{
	Node *curr = head;
	while(curr)
	{
		cout << curr->data <<" ";
		curr = curr->next;
	}
	cout << endl;
}

// function to swap the nodes pairwise
Node *pairwise_swap(Node *head)
{
	// if no or only one node is presente
	if (head == NULL or head->next == NULL)
		return head;

	// for eg :- 1 2 3 4 5 ---->resultant list 2 1 4 3 5
	//initialise the prev and curr pointers
	Node *prev = head;  // 1
	Node *curr = head->next;  // 2

	// mark the head node 
	head = curr;

	while(true)
	{
		Node *next = curr->next; // 3-->after 1st iteration next = 5
		// linking the curr node to the previous node
		curr->next = prev; // 2->1 ----> after 1st iteration 2->1->4->3

		// if next or next->next node is null then mark prev->next as next and exit from the loop
		if(next == NULL or next->next == NULL)
		{
			prev->next = next; // 2->1->4->3->5->null
			break;
		}

		// otherwise link prev->next to next->next node
		prev->next = next->next;// 2->1->4

		// updata prev and curr pointers
		prev = next; // 3
		curr = prev->next; // 4
	}

	return head;
}

// driver main function
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

		head = pairwise_swap(head);
		printList(head);
	}
	return 0;
}