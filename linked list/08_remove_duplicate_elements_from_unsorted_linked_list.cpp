// removing duplicate elements from unsorted linked list

/*Given an unsorted linked list of N nodes. 
The task is to remove duplicate elements from this unsorted Linked List. 
If all the nodes in the linked list are equal, then remove n-1 nodes.

Input:
The first line of input contains the number of test cases T. 
For each test case, the first line of input contains a number of nodes in the linked list, and the next line contains node data for N nodes.

Output:
For each test case, print the linked list with no repeating elements.

User Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list. 
You should not read any input from the stdin/console. Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 104
1 <= numbers in list <= 104

Example:
Input:
2
4
5 2 2 4
5
2 2 2 2 2
Output:
5 2 4
2

Explanation:

Testcase 1: Given linked list elements are 5->2->2->4, in which 2 is repeated only. 
So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4.

Testcase 2: Given linked list elements are 2->2->2->2->2, in which 2 is repeated. 
So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain only 2.*/

#include <iostream>
#include <set>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

//function to remove the duplicate node from the linked list
Node *removeDuplicates(Node *head)
{
	set<int> s;

	Node *curr = head;
	Node *temp;

	while(curr->next != NULL)
	{
		//inserting the current node in the set 
		s.insert(curr->data);

		// checking if the current node is present in the set
		// if present, link the temp node to the next of next node
		// the free the next node from the memory 
		// and link the curr->next node with the temp node.
		if(s.find(curr->next->data) != s.end())
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

// function to print the linked list
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

// main function
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
		printList(head);
	}

	return 0;
}