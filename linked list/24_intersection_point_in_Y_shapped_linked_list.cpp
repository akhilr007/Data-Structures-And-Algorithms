// intersection point in y shapped linked list

/*Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.
Note: Expected time complexity is O(m + n) where m and n are lengths of two linked lists.

Input:
First line of input is the number of test cases T. Every test case has four lines. First line of every test case contains three numbers, x (number of nodes before merge point in 1st list), y (number of nodes before merge point in 2nd list) and z (number of nodes after merge point). Next three lines contain x, y and z values.

Output:
Print the data of the node in the linked list where two linked lists intersects.

Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it should return -1.

Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= value <= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 2
10 20
30 40 50
10 20
Output:
5
10

Explanation:
Testcase 1: The point of intersection of two linked list is 5, means both of them get linked (intersects) with each other at node whose value is 5.
Testcase 2: The point of intersection of two linked list is 10. Hence, output is 10.*/

#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node* next;
};

// function to find the intersection point of two linked list
int intersectionPoint(Node *head1, Node *head2)
{
	int c1 = 0, c2 = 0;
	// count the nodes of both the linked list
	Node *curr1 = head1;
	while(curr1)
	{
		c1++;
		curr1 = curr1->next;
	}

	Node *curr2 = head2;
	while(curr2)
	{
		c2++;
		curr2 = curr2->next;
	}

	// if list1 is longer, we ignore some of its starting
    // elements till it has as many elements as list2
	for( ; c1 > c2 ; c1--)
		head1 = head1->next;
	// similarly, if list2 is longer, we ignore some of its starting
    // elements till it has as many elements as list2
	for( ; c2 > c1; c2--)
		head2 = head2->next;

	// now we simple traverse ahead till we get the
    // intersection point, if there is none, this loop
    // will break when both pointers point at NULL
	while(head1 != head2)
	{
		head1 = head1->next;
		head2 = head2->next;
	}

	// if head1 is not null we return the head1->data otherwise -1
	if(head1) return head1->data;

	return -1;
}

// functiont to insert the node in linked list
Node* insertList(int size)
{
	if(size == 0) return NULL;

	Node *head = NULL, *tail = NULL;
	int x;
	cin >> x;

	head = new Node();
	head->data = x;
	tail = head;

	for(int i = 0; i < size-1; i++)
	{
		cin >> x;
		tail->next = new Node();
		tail->next->data = x;
		tail = tail->next;
	}
	tail->next = NULL;

	return head;
}

int main()
{
	int t, x, y, z;
	cin >> t;

	while(t--)
	{
		cin >> x >> y >> z;

		Node *head1 = insertList(x);
		Node *head2 = insertList(y);
		Node *common = insertList(z);

		Node *curr = head1;
		while(curr != NULL and curr->next != NULL)
			curr = curr->next;
		if(curr) curr->next = common;

		curr = head2;
		while(curr != NULL and curr->next != NULL)
			curr = curr->next;
		if(curr) curr->next = common;

		

		cout << intersectionPoint(head1, head2) << endl;
	}
	return 0;
}