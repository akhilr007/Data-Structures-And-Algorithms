// removing consecutive duplicates

/*Stacks can be used to remove duplicate characters from a string that are stacked next to each other. For example, we take the string aabbccccc and convert it into abc. We can push the first character into a stack and skip if the top of the stack is equal to the current character.
You are given a string str. You need to remove the consecutive duplicates.

Input:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains one line of input containing string str.

Output:
For each testcase, in a new line, print the modified string.

Your Task:
This is a function problem. You need to complete the function removeConsecutiveDuplicates() that takes a string as a parameter and returns the modified string. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaaaaabaabccccccc
abbccbcd
Output:
ababc
abcbcd

Explanation:
Testcase 1: Removing all consecutive duplicates, we have no duplicates consecutively.
Testcase 2: Removing all the consecutive duplicates, we have the output as abcbcd.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removingDuplicates(string s)
{
 	stack<char> st;

 	for(auto x : s)  // iterating through the string
 	{
 		if(st.empty()) st.push(x);   // if our stack is empty push the character of the string in stack

 		else
 		{
 			if(st.top() == x) // if both the char are same skip the part
 				continue;
 			else
 				st.push(x);  // otherwise push the character in the stack
 		}
 	}

 	string res = "";  // creating new string for showing results
 	while(!st.empty())  // iterating through our stack
 	{
 		res = st.top() + res;
 		st.pop();
 	}

 	return res;  // return the resultant string
}

int main()
{
 	int t;  // testcases
 	cin >> t;

 	while(t--)
 	{
 		string s; // input string
 		cin >> s;
 		cout << removingDuplicates(s) << endl; // function call to remove duplicates
 	}

 	return 0;
}