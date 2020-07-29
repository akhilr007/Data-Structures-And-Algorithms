// paranthesis checker

/*Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”.

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Your Task:
This is a function problem. You only need to complete the function ispar() that takes string as parameter and returns true if brackets are balanced else returns false. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auixilliary Space : O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ |x| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced

Explanation:
Testcase 1: { ( [ ] ) }. Same colored brackets can form balaced pairs, with 0 number of unbalanced bracket.
Testcase 2: () . Same bracket can form balanced pairs, and here only 1 type of bracket is present and in balanced way.
Testcase 3: ([] . Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool matching(char a, char b)
{
	return ((a== '(' and b ==')') or (a == '{' and b == '}') or (a == '[' and b == ']'));
}

bool paranthesisChecker(string str)
{
	stack<char> st;

	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '{' or str[i] == '[' or str[i] == '(') // pushing the opening brackets into the stack
			st.push(str[i]);
		else
		{
			if(st.empty() == true)  // if our stack is empty that is no opening brackets are present then it is not balanced
				return false;

			else if(matching(st.top(), str[i]) == false)  // if our stack does not have opening bracket followed by closing bracket 
				return false;							  // then it is not balanced

			else
				st.pop();         // if balanced, pop the closing bracket from the stack
		}
	}

	return (st.empty() == true);  // if our stack is empty it means our string is balanced
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string str;
		cin >> str;

		if(paranthesisChecker(str))
			cout << "Balanced" << endl;
		else
			cout << "Not Balanced" << endl;
	}

	return 0;
}
