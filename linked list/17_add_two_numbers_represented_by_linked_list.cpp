// add two numbers represented by linked list

/*Given two numbers represented by two linked lists of size N and M. 
The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Input:
The first line of input contains the number of test cases T. 
For each test case, the first line of input contains the length of the first linked list and next line contains N elements of the linked list. 
Again, the next line contains M, and the following line contains M elements of the linked list.

Output:
Output the resultant linked list.

User Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= T <= 100
1 <= N, M <= 5000

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7
Output:
3 9 0  
7 0

Explanation:
Testcase 1: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

Testcase 2: For the given two linked list (6 3) and (7), after adding the two linked list resultant linked list will be (7 0).*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

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

// function to reverse the linked list
Node *rev(Node *head)
{
	Node *curr = head;
	Node *prev = NULL, *next;

	for(curr = head; curr != NULL; curr = next)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
	}
	return prev;
}

// function to add the two linked list
Node *addTwoLists(Node *first, Node *second)
{
	Node *a = rev(first);
	Node *b = rev(second);

	Node *result = NULL, *prev = NULL, *temp;
	int carry = 0, sum;

	while(a != NULL or b != NULL)
	{
		sum = carry + (a ? a->data : 0) + (b ? b->data : 0);  ///3 4 5 + 4 5----> 3 9 0

		// decide the carry
		carry = (sum >= 10)? 1:0;

		// take unit place digit from sum
		sum = sum % 10;

		// create a new node for saving sum
		temp = new Node();
		temp->data = sum;

		// mark the head node for the resultant linked list
		if(result == NULL)
			result = temp;
		else
			// connect current node with the rest of the list
			prev->next = temp;

		// mark current node as previous
		prev = temp;

		// if list not null go forward 
		if(a)
			a = a->next;
		if(b)
			b = b->next;
	}

	// save the carry in new node
	if(carry > 0) 
	{
		temp->next = new Node();
		temp->next->data = carry;
	}	

	result = rev(result);
	return result;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

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

		int m;
		cin >> m;

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

		Node *result = addTwoLists(head1, head2);
		printList(result);
	}
	return 0;
}