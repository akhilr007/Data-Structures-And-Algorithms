// removing duplicate elements -2

/*You are given a string str. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together. 

Input:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains one line of input containing string str.

Output:
For each testcase, in a new line, print the modified string. If the final string is empty, then print "Empty String".

Your Task:
This is a function problem. You only need to complete the function removePair() that takes a string as a parameter and returns the modified string. Return an empty string if the whole string is deleted.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
N = length of string.

Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaabbaaccd
aaaa
Output:
ad
Empty String

Explanation:
Testcase1: Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
Testcase 2: Remove (aa)aa => aa
Again removing pair of duplicates then (aa) will be removed and we will get 'Empty String'.*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removePair(string str)
{
	stack<char> st;
	string res;

	// pushing first character of string in stack and result
	st.push(str[0]);
	res.push_back(str[0]);

	// now iterating through the remaining string
	// if string and stack both have same character remove the elements
	// if not push the elements in both of them

	for(int i = 1; i < str.length(); i++)
	{
		if(!st.empty() and str[i] == st.top()) // if stack is not empty and both the string and stack have same elements
		{
			st.pop();
			res.pop_back();
		}

		else
		{
			st.push(str[i]);
			res.push_back(str[i]);
		}
	}

	return res;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string ans;
		cin >> ans;

		ans = removePair(ans);

		if(ans == "")
			cout << "Empty String " << endl;
		else
			cout << ans << endl;
	}

	return 0;
}