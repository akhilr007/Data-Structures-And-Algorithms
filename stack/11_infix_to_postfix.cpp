// infix to postfix /*/*

/*Given an infix expression in the form of string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
​Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Input:
The first line of input contains an integer T denoting the number of test cases. The next T lines contain an infix expression. The expression contains all characters and ^,*,/,+,-. 

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string as a parameter and returns the postfix expression. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= length of str <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D
Output:
abcd^e-fgh*+^*+i-
ABC+*D/

Explanation:
Testcase 1: After converting the infix expression into postfix expression , the resultant expression will be abcd^e-fgh*+^*+i-
Testcase 2: After converting the infix expression into postfix expression , the resultant expression will be ABC+*D/* */


#include <iostream>
#include <stack>
#include <string>

using namespace std;

// function to check the precedence between operators that is plus minus multiplication etc
int checkPredence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 1;

		case '*':
		case '/': return 2;

		case '%': return 3;

		case '^': return 4;

		default : return 0;
	}
}

//  function to evaluate the expression from infix to postfix
string infixToPostfix(string str)
{
	stack<char> s;
	s.push('(');

	str += ')';

	string res = "";

	for(int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z'))  // if char then add it to resultant string
		{
			res = res + str[i];
			continue;
		}	

		if(str[i] == '(') // if opening bracket then add it to stack
		{
			s.push(str[i]);
			continue;
		}

		if(str[i] == ')') // if closing bracket then pop all the elements until opening bracket arrives if avialable
		{
			while(!(s.top() == '('))
			{
				res = res + s.top();
				s.pop();
			}

			s.pop();
			continue;
		}

		// for the operators

		while(!(s.empty()) and (checkPredence(str[i])) <= checkPredence(s.top()))
		{
			char val = s.top();
			s.pop();
			res = res + val;
		}

		s.push(str[i]);
	}

	return res;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string str;
		cin >> str;

		cout << infixToPostfix(str) << endl;
	}

	return 0;
}