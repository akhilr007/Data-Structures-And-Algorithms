// remove loop in a linked list

/*You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

Input:
First line of input contains number of testcases T. T testcases follow. 
For each testcase, first line of input contains length N of the linked list and next line contains N data of the linked list. 

The third line contains the position of the node(from head) to which the last node will get connected. If it is 0 then there is no loop.

Output:
For each testcase, in a new line, 1 will be printed if loop is removed and the list still has all N nodes connected to it, else 0 will be printed.

User Task:
Your task is to complete the function removeLoop(). The only argument of the function is head pointer of the linked list. Do not print anything. 
Simply remove the loop in the list (if present) without disconnecting any nodes from the list.

Expected time complexity : O(n)

Expected auxiliary space : O(1)

Constraints:
1 <= T <= 102
1 <= N <= 104

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0
Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3.The linked list with nodes N = 3 is given. Here, x = 2 which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

Testcase 2: N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void loopIsHere(Node *head, Node *tail, int pos)
{
	if(pos == 0) return;

	Node *curr = head;
	for(int i = 1; i < pos; i++)
		curr = curr->next;
	tail->next = curr;
}

bool isLoop(Node *head)
{
	if(head == NULL) return false;

	Node *fast = head->next;
	Node *slow = head;

	while(slow != fast)
	{
		if(fast == NULL or fast->next == NULL) return false;
		fast = fast->next->next;
		slow = slow->next;
	}

	return true;
}

int length(Node *head)
{
	int ret = 0;
	while(head)
	{
		head = head->next;
		ret++;
	}
	return ret;
}

// function to remove loop from the linked list
void removeLoop(Node *head)
{
	Node *fast = head, *slow = head;
	Node *temp;

	// first we detect the loop if present in the linked list
	while(fast != NULL and fast->next != NULL)
	{
		slow = slow->next;
		temp = fast->next;
		fast = fast->next->next;

		// if such loop present in the list break that is if slow is equal to fast pointers.
		if(slow == fast)
			break;
	}
    
    // if linked list has only one node present
	if(fast == head)
		temp->next = NULL;

	else if(slow == fast)
	{
		slow = head;
		while(slow->next != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}

	else return;
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

		removeLoop(head);

		if(isLoop(head) or length(head) != n)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}