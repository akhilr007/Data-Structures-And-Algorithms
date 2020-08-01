// get min at pop

/*Now, we'll try to solve a famous stack problem.
You are given an array A of size N. You need to push the elements of the array into a stack and then print minimum in the stack at each pop.

Input:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains two lines of input. The first line of input contains the size of array N. The second line of the array contains the elements of array separated by spaces.

Output:
For each testcase, in a new line, print the required output.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided functions _push() and _getMinAtPop().

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= Ai <= 107

Examples:
Input:
2
5
1 2 3 4 5
7
1 6 43 1 2 0 5
Output:
1 1 1 1 1
0 0 1 1 1 1 1

Explanation:
Testcase 1: After pushing elements to the stack, the stack will be top --- > 5, 4, 3, 2, 1. Now, start popping elements from the stack:
popping 5: min in the stack is 1. popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1.
Testcase 2: After pushing the elements to the stack, the stack will be 5->0->2->1->43->6->1. Now, poping the elements from the stack:
popping 5: min in the stack is 0. popped 5
popping 0: min in the stack is 0. popped 0
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
popping 43: min in the stack is 1. popped 43
popping 6: min in the stack is 1. popped 6
popping 1: min in the stack is 1. popped 1.*/


#include <iostream>
#include <stack>
typedef long long ll;

using namespace std;

// function to push the elemetns into stack
stack<int> push(ll arr[], int n)
{
	stack<int> s;

	s.push(arr[0]);  // pushing the first element into stack

	for(int i = 1; i < n; i++)
	{
		if(s.top() < arr[i])  
		{
			int temp = s.top();
			s.push(temp);
		}

		else s.push(arr[i]);
	}

	return s;
}

void _getMinAtPop(stack<int> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		ll arr[n];
		for(ll i = 0; i < n; i++)
			cin >> arr[i];

		stack<int> mys = push(arr, n);
		_getMinAtPop(mys);

		cout << endl;
	}

	return 0;
}