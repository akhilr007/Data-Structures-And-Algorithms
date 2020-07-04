// count nodes in a loop 

/*Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not 
and if the loop is present then return the count of nodes in a loop or else return 0.



Input:
The first line of input contains the number of testcases T. 
For each test case, the first line of input contains the length of a linked list and next line contains data of the linked list, 
and the third line contains the position of the node from the beginning (1 based indexing) to which the last node will be connected to form a loop.
Note: If the input of the third line is zero then there is no loop.

Output:
For each test case, there will be a single line of output containing the length of the loop in a linked list, 
else print 0, if the loop is not present in the linked list.

User Task:
The task is to complete the function countNodesinLoop() which contains the only argument as reference to head of linked list.

Challenge : Try to solve the problem with constant Auxilliary space and Linear Time Complexity.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 500
0 <= C <= N-1

Example:
Input:
2
10
25 14 19 33 10 21 39 90 58 45
4
2
1 0
1
Output:
7
2

Explanation:
Testcase 1: The loop is 45->33. So length of loop is 33->10->21->39->90->58->45 = 7. 
The number 33 is connected to the last node to form the loop because according to the input the 4th node 
from the beginning(1 based index) will be connected to the last node for the loop.

Testcase2:  The length of the loop is 2.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void loopIsHere(Node* head, Node* tail, int pos)
{
	if(pos == 0) return;

	Node *curr = head;
	for(int i = 1; i < pos; i++)
		curr = curr->next;
	tail->next = curr;
}

// function to count nodes in a linked list which contains loop within.
int countNodesInLoop(Node *head)
{
	// at first we will be detecting the loop using floyd's detection algorithm
	Node *fast = head, *slow = head;

	while(fast != NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		// as soon we encounter loop if fast is equal to slow at any point of time
		// we will break the loop
		if(slow == fast)
			break;
	}

	// if slow is not equal to fast it means there is no loop present.
	if(slow != fast)
		return 0;

	// if present, we increase fast by one step till we again coincide with curr
	// and also incrementing the count such that counting the nodes of nodes in a loop
	int count = 1;
	fast = fast->next;

	while(fast != slow)
	{
		fast = fast->next;
		count++;
	}

	return count;
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

		int pos;
		cin >> pos;

		loopIsHere(head, tail, pos);

		cout << countNodesInLoop(head) << endl;
	}
	return 0;
}