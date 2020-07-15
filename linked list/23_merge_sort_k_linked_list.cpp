// merge k sorted linked listGiven K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

/*Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of linked lists N and next line contains data of nodes of all K linked lists, with first element as M, the length of linked list and next M elements for the same linked list.

Output:
For each testcase, in a new line, print the merged linked list.

Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input:
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8
Output:
1 2 3 4 5 5 6 7 8
1 3 4 5 6 8

Explanation :
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
Testcase 2: The test case has 3 sorted linked list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be 1->3->4->5->6->8.*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

// function to merge sort the linked list
Node *mergeSort(Node *first, Node *second)
{
	Node *result = NULL;

	if(first == NULL) return second;

	if(second == NULL) return first;

	if(first->data <= second->data)
	{
		result = first;
		result->next = mergeSort(first->next, second);
	}

	else
	{
		result = second;
		result->next = mergeSort(first, second->next);
	}

	return result;
}

Node *mergeKList(Node *arr[], int N)
{
	int k = N-1;

	while(k != 0)
	{
		int i = 0, j = k;

		while(i < j)
		{
			arr[i] = mergeSort(arr[i], arr[j]);
			i++;
			j--;

			if(i >= j)
				k = j;
		}
	}

	return arr[0];
}

// function to print the linked list
void printList(Node *head)
{
	Node *curr = head;
	while(curr)
	{
		cout << curr->data << " ";
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
		int N;
		cin >> N;

		Node *arr[N];
		for(int i = 0; i < N; i++)
		{
			int n;  // no of elements in linked list
			cin >> n;

			int x; // data in the linked list
			cin >> x;

			arr[i] = new Node();
			arr[i]->data = x;
			Node *curr = arr[i];
			n--;

			for(int j = 0; j < n; j++)
			{
				cin >> x;
				Node *temp = new Node();
				temp->data = x;
				curr->next = temp;
				curr = temp;
			}
		}

		Node *res = mergeKList(arr, N);
		printList(res);
	}
	return 0;
}