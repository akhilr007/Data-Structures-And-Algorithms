// delete mid element of stack

/*Given a stack with push(), pop(), empty() operations, delete the middle of it without using any additional data structure.
Middle: ceil(size_of_stack/2.0)

Input:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer sizeOfStack denoting the stack size. The next line contains space-separated integers that will be pushed into the stack.

Output:
For each test case, in a new line, print the stack elements. If stack size if 1 then just print the top element.

Your Task:
This is a function problem. The input is already taken by the driver code. You only need to complete the function deleteMid() which takes 3 arguments(stack, size of the stack, and current index - initially 0) that returns the modified stack.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= sizeOfStack <= 100

Example:
Input:
3
5
1 2 3 4 5
7
1 2 3 4 5 6 7
4
1 2 3 4
Output:
5 4 2 1
7 6 5 3 2 1
4 3 1

Explanation:
Testcase 1: As the number of elements is 5 , hence the middle element will be the 3rd one so the output will be 5 4 2 1.
Testcase 2: As the number of elements is 7, hence the middle elements will be the 4th one so the output will be 7 6 5 3 2 1.
Testcase 3: As the number of elements is 4, hence the middle elements will be the 2nd one so the output will be 4 3 1.*/


#include <iostream>
#include <stack>

using namespace std;

// function to delete the middle element in stack
stack<int> deleteMid(stack<int> s, int size, int current)
{
	if(current == size/2)  // if it reaches middle to the element of stack pop the element
	{
		s.pop();
		return s;
	}

	int temp = s.top();  // otherwise pop the element and recursively push it into the stack  1 2 3 4 ----> 4 3 1
	s.pop();

	s = deleteMid(s, size, current + 1);

	s.push(temp);
	return s;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int size;
		cin >> size;

		stack<int> myStack;

		for(int i = 0; i < size; i++)
		{ 	
			int x;
			cin >> x;
			myStack.push(x);
		}

		if(size == 1) 
			cout << myStack.top() << " ";

		else
		{
			stack<int> s = deleteMid(myStack, myStack.size(), 0);

			while(!s.empty())
			{
				cout << s.top() << " ";
				s.pop();
			}
		}

		cout << endl;
	}

	return 0;
}