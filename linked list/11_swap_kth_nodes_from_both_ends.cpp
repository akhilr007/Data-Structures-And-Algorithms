// swap Kth nodes from end

/*Given a singly linked list of size N, and an integer K. You need to swap the Kth node from beginning and Kth node from the end in the linked list.
Note: You need to swap the nodes through the links and not changing the content of the nodes.

Input: 
The first line of input contains the number of testcases T. T
he first line of every test-case contains N, number of nodes in a linked list, and K, the nodes to be swapped, 
and the second line contains the elements of the linked list.

Output:  
For each test case, if the nodes are swapped correctly, the output will be 1, else 0.

User Task: 
The task is to complete the function swapkthnode(), which has arguments head, num(no of nodes), and K, and it should return a new head. 
The validation is done internally by the driver code to ensure that the swapping is done by changing references/pointers only.  
A correct code would always cause output as 1.

Expected Time Complexity: O(n)
Expected Auxillary space Complexity: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= K <= 103

Example:
Input:
3
4 1
1 2 3 4
5 3
1 2 3 4 5
4 4
1 2 3 4
Output:
1
1
1

Explanation:
Testcase 1: Here K = 1, hence after swapping the 1st node from the beginning and end the new list will be 4 2 3 1.
Testcase 2: Here k = 3, hence after swapping the 3rd node from the beginning and end the new list will be 1 2 3 4 5.
Testcase 3: Here k = 4, hence after swapping the 4th node from the beginning and end the new list will be 4 2 3 1.*/


#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;	
};

void addressStore(Node **arr, Node *head)
{
	Node *curr = head;
	int i = 0;

	while(curr)
	{
		arr[i] = curr;
		i++;
		curr = curr->next;
	}
}

// check the before and after of linked list after swapping
bool check(Node **before, Node **after, int n , int k)
{
	if(k > n) return 1;

	return(before[k-1] == after[n-k] and before[n-k] == after[k-1]);
}

// function to swap kth node from both ends of linked list
Node *swapKthNode(Node *head, int n , int k)
{
	// if k is more than number of nodes
	if (k > n)
		return head;

	// if kth node from beginning and end of linked list is same
	if(2*k-1 == n)
		return head;

	Node *x_prev = NULL;
	Node *x = head;

	Node *y_prev = NULL;
	Node *y = head;

	int count = k-1; // we want the kth node from beginning of linked list
	while(count--)
	{
		x_prev = x;
		x = x->next;
	}

	count = n-k; // we want the kth node from the end of linked list
	while(count--)
	{
		y_prev = y;
		y = y->next;

	}

	if(x_prev)
		x_prev->next = y;
	if(y_prev)
		y_prev->next = x;

	Node *temp = x->next;
	x->next = y->next;
	y->next = temp;

	if(k == 1) return y;
	if(k == n) return x;

	return head;

}


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, k;
		cin >> n >> k;

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

		Node *before[n];
		addressStore(before, head);

		head = swapKthNode(head, n, k);

		Node *after[n];
		addressStore(after, head);

		if(check(before, after, n, k)) cout << 1 << endl;

		else cout << 0 << endl;

	}
	return 0;
}