// evalutate the postfix expression

/*Given a postfix expression, the task is to evaluate the expression and print the final value. Operators will only include the basic arithmetic operators like *,/,+ and -.

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Your Task:
This is a function problem. You need to complete the function evaluatePostfixExpression() that takes the string denoting the expression as input and returns the evaluated value.

Expected Time Complexity : O(n)
Expected Auixilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= length of expression <= 1000

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3

Explanation:
Testcase 1: After solving the given expression, we have -4 as result.
Testcase 2: After solving the given postfix expression , we have -3 as result.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// function to evaluate the postfix expression
int evaluatePostfixExpression(string &str)
{
	stack<int> s;

	for(int i = 0; i < str.length(); i++)
	{
		// if current char is an operand
		// then push the char into stack
		if(str[i] >= '0' and str[i] <= '9')
			s.push(str[i] - '0');

		// if the curr char is operand
		else
		{
			// pop the two elements from stack
			int x = s.top();
			s.pop();

			int y =  s.top();
			s.pop();

			// evalutate the expression x op y
			// and push the result into stack

			if(str[i] == '+')
				s.push(y + x);

			else if(str[i] == '-')
				s.push(y - x);

			else if(str[i] == '*')
				s.push(y * x);

			else if(str[i] == '/')
				s.push(y / x);
		}
	}

	// at this only one element is in the stack that is our result

	return s.top();
}

// main function
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string str;
		cin >> str;

		cout << evaluatePostfixExpression(str) << endl;
	}

	return 0;
}