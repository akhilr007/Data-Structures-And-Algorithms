// implementing stack using two queues

/*Implement a Stack using two queues q1 and q2.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack.

Your Task:
Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack and pop() which returns the integer poped out from the stack.

Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
2
5
1 2 1 3 2 1 4 2
4
1 2 2 2 1 3
Output:
3 4
2 -1

Explanation:
Testcase1:
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4  
Testcase 2: 
1 2 the stack will be {2}
2    poped element will be 2
2    the stack is empty hence -1
1 3 the stack will be {3}.*/


#include <iostream>
#include <queue>

using namespace std;

class queueStack
{
private:
	queue<int> q1;
	queue<int> q2;

public:
	void push(int);
	int pop();
};

// function to enque the element
void queueStack :: push(int x)
{
	q1.push(x);
}

// function to deque the element
int queueStack :: pop()
{
	// if queue is empty return -1
	if(q1.empty()) return -1;

	int s = q1.size();

	// we will remove all the elements from queue q1 till only last element is present
	// we will push all those deleted elements into q2 
	for(int i = 0; i < s-1; i++)
	{
		q2.push(q1.front());
		q1.pop();
	}

	// at last return the last element that needs to be popped
	int x = q1.front();

	//we just emptied all the elements from q1 to q2..

	int sx = q2.size();
	// again we will reset the q1 as before after removing the element
	for(int i = 0; i < sx; i++)
	{
		q1.push(q2.front());
		q2.pop();
	}

	return x;// return the element that needs to be popped out
}


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		queueStack *qs = new queueStack();

		int q;  // number of queries
		cin >> q; 

		while(q--)
		{
			int queryType = 0;
			cin >> queryType;  // 1---> push into the queue and 2---> pop from the queue

			if(queryType == 1)
			{
				int a;
				cin >> a;

				qs->push(a);
			}

			else if(queryType == 2)
				cout << qs->pop() << " ";
		}

		cout << endl;
	}

	return 0;
}