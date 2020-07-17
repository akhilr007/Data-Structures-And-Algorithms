// clone a linked list with next and random pointer

/*You are given a Singly Linked List with N nodes where each node next pointing to its next node. 
You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1
Input:
First line of input contains number of testcases T. 
For each testcase, first line of input contains two integers N and M. Next line of input contains values of N nodes of the linked list 
and last line contains M pairs denoting arbitrary connecting  nodes, for which each ith node is connected to any jth node. ( ith->arb = jth ).
NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Output:
For each testcase, clone the given linked list.

Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned 
and should return the head of the cloned linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

Example:
Input:
2           
4 2                                       
1 2 3 4                             
1 2 2 4
4 3
1 3 5 9
1 1 3 4
Output:
1
1

Explanation:
Testcase 1: In this test case, there are 4 nodes in linked list.  
Among these 4 nodes,  2 nodes have arbit pointer set, rest two nodes have arbit pointer as NULL. Third line tells us the value of four nodes. 
The fourth line gives the information about arbitrary pointers. The first node arbit pointer is set to node 2.  
The second node arbit pointer is set to node 4.

Testcase 2: In the given testcase , applying the method as stated in the abpve testcase , the output will be 1.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *arb;

	Node(int x)
	{
		data = x;
		next = NULL;
		arb = NULL;
	}
};

Node *copyList(Node *head)
{
	if(head == NULL) return head;

	// creating and merging the duplicate list with original list
	Node *t = head;
	while(t != NULL)
	{
		Node *n = new Node(t->data);
		n->next = t->next;
		t->next = n;
		t = n->next;
	}

	t = head;
	Node *head2 = head->next;// variable to be returned

	while(t != NULL)
	{
		// setting the arbitrary pointers to the duplicate list 1 1 2 2 3 3
		if(t->arb == NULL)
			t->next->arb = NULL;
		else
			t->next->arb = t->arb->next;

		t = t->next->next;
	}

	t = head;
	while(t != NULL)
	{
		// separating the 2 merge list (original and duplicate)
		head = t->next->next;

		if(head != NULL)
			t->next->next = head->next;
		else
			t->next->next = NULL;

		t->next = head;
		t = head;

	}
	return head2;
}

void append(Node **head, Node **tail , int newData)
{
	Node *newNode = new Node(newData);
	if(*head == NULL)
		*head = newNode;
	else
		(*tail)->next = newNode;
	*tail = newNode;
}

bool validation(Node *head, Node *res, Node *clonedArr, Node *generated_node)
{
	if(generated_node == clonedArr) return false;

	Node *temp1 = head;
	Node *temp2 = res;

	int len1 = 0, len2 = 0;

	while(temp1 != NULL)
	{
		len1++;
		temp1 = temp1->next;
	}

	while(temp2 != NULL)
	{
		len2++;
		temp2 = temp2->next;
	}

	// if lengths not equal
	if(len1 != len2) return false;

	temp1 = head;
	temp2 = res;

	while(temp1 != NULL)
	{
		if(temp1->data != temp2->data) return false;

		if(temp1->arb != NULL and temp2 != NULL)
		{
			if(temp1->arb->data != temp2->arb->data) return false;
		}

		else if(temp1->arb != NULL and temp2->arb == NULL)
			return false;
		else if(temp1->arb == NULL and temp2->arb != NULL)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return true;
}

int main()
{
	int t, n, l , m;
	cin >> t;

	Node *generated_node = NULL;

	while(t--)
	{
		generated_node = NULL;
		Node *head = NULL, *tail = NULL;

		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}

		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;

			Node *tempA = head;
			int count = -1;

			while(tempA != NULL)
			{
				count++;
				if(count == a-1) break;
				tempA = tempA->next;
			}

			Node *tempB = head;
			count = -1;

			while(tempB != NULL)
			{
				count++;
				if(count == b-1) break;
				tempB = tempB->next;
			}

			if(a <= n) tempA->arb = tempB;
		}

		generated_node = head;
		Node *res = copyList(head);

		Node *clonedArr = res;
		cout << validation(head, res, clonedArr, generated_node) << endl;
	}

	return 0;
}
