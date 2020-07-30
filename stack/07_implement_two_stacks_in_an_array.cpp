// implement two stacks in an array

/*Your task is to implement  2 stacks in one array efficiently .

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 4 Types
(i)    1 1 x    (a query of this type means  pushing 'x' into the stack 1)
(ii)   1 2      (a query of this type means to pop element from stack1  and print the poped element)
(iii)  2 1 x  (a query of this type means pushing 'x' into the stack 2)
(iv)  2 2     (a query of this type means to pop element from stack2 and print the poped element)
The second line of each test case contains Q queries seperated by space.Output:
The output for each test case will be space separated integers having -1 if the stack is empty else the element poped out from the stack. 

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided functions. You are required to complete the 4 methods push1, push2 which takes one argument an integer 'x' to be pushed into the stack one and two and pop1, pop2 which returns the integer poped out from stack one and two.

Expected Time Complexity: O(1) for all the four methods.
Expected Auxiliary Space: O(1) for all the four methods.

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input
2
6
1 1 2 1 1 3 2 1 4 1 2 2 2 2 2
4
1 1 2 2 2 1 2 2 2
Output
3 4 -1
-1 2 -1

Explanation:
Testcase1:
1 1 2    the stack1 will be {2}
1 1 3    the stack1 will be {2,3}
2 1 4   the stack2 will be {4}
1 2      the poped element will be 3 from stack1 and stack1 will be {2}
2 2      the poped element will be 4 from stack2 and now stack2 is empty
2 2      the stack2 is now empty hence -1 .
Testcase 2:
1 1 2 the stack1 will be {2}
2 2 the stack2 is now empty hence -1
1 2 the poped element from stack1 will be 2
2 2 the stack2 is still empty and hence -1
Hence, the output will be -1 2 -1.*/


#include <iostream>
#include <stack>

using namespace std;

class twoStack
{
	int *arr;
	int top1, top2;
	int size;

public:
	twoStack(int n = 100)
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	void push1(int x);
	void push2(int x);
	int pop1();
	int pop2();
};

void twoStack :: push1(int x)
{
	if(top1 < top2-1)
	{
		top1++;
		arr[top1] = x;
	}
}

void twoStack :: push2(int x)
{
	if(top1 < top2-1)
	{
		top2--;
		arr[top2] = x;
	}
}

int twoStack :: pop1()
{
	if(top1 >= 0)
	{
		int x = arr[top1];
		top1--;
		return x;
	}

	else return -1;
}

int twoStack :: pop2()
{
	if(top2 < size)
	{
		int x = arr[top2];
		top2++;
		return x;
	}

	else return -1;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		twoStack *ts = new twoStack();

		int q;
		cin >> q;  // number of queries

		while(q--)
		{
			int stackNo;
			cin >> stackNo;  // stack number

			int queryType;
			cin >> queryType;   // our query type

			if(queryType == 1)
			{
				int a;
				cin >> a;   // the number that needs to be pushed

				if(stackNo == 1)
					ts->push1(a);

				else if(stackNo == 2)
					ts->push2(a);
			}

			else if(queryType == 2)
			{
				if(stackNo == 1)
					cout << ts->pop1() << " ";

				else if(stackNo == 2)
					cout << ts->pop2() << " ";
			}
		}
		cout << endl;
	}
	return 0;
}