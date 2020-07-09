// check if linked list is palindrome

/*Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Input:
First line of input contains number of testcases T. 
For each testcase, first line of input contains length of linked list N and next line contains N integers as data of linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

User Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter 
and returns true or false if linked list is palindrome or not respectively.

Constraints:
1 <= T <= 103
1 <= N <= 50

Example:
Input:
2
3
1 2 1
4
1 2 3 4
Output:
1
0

Explanation:
Testcase 1: The given linked list is 1 2 1 , which is a pallindrome and Hence, the output is 1.
Testcase 2: The given linked list is 1 2 3 4 , which is not a pallindrome and Hence, the output is 0.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

// the logic behind this problem is to divide the list into two halves
// then reverse the second half and check it with first half if both are equal then
// its a palindrome otherwise it is not a palindrome.

// function to reverse the linked list
Node *reverseList(Node *head)
{
	Node *prev = NULL;
	Node *curr = head;
	Node *next;

	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// function to check if the nodes of two halves are identical or not
bool isIdentical(Node *n1, Node *n2)
{
	for( ; n1 and n2; n1 = n1->next, n2 = n2->next)
		//we will check the data of the nodes
		if(n1->data != n2->data)
			return 0;

	return 1;
}

// function to check if the list is palindrome or not
bool isPalindrome(Node *head)
{
	int size = 0;
	Node *curr = head;

	// count the size of linked list
	while(curr)
	{
		size++;
		curr = curr->next;
	}

	// if there is no node or only one node present in linked list
	// then it is a palindrome
	if(size < 2)
		return 1;

	curr = head;
	int midPoint = (size-1)/2;
	// if we divide the list into two halves and if nodes are odd first half has the middle node
	while(midPoint--)
		curr = curr->next;

	//here curr is the last node of the first half

	Node *head2 = curr->next; // head node for the second half of the linked list
	// disconnecting the first half with the second half
	curr->next = NULL;

	head2 = reverseList(head2); // reversing the second half of the list
	bool ret = isIdentical(head, head2);

	head2 = reverseList(head2); // again reversing the second half as it was earlier

	curr->next = head2;// reconnecting the first half with the second half

	return ret;

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

		cout<<isPalindrome(head)<< endl;
	}
	return 0;
}