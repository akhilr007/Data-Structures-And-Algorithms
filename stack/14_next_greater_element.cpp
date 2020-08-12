// next greater element

/*Given an array A[] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1.

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Your Task:
This is a function problem. You only need to complete the function nextLargerElement that takes array and n as parameters and returns an array of length n denoting the next greater elements for all the corresponding elements in the input array.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
5
6 8 0 1 3
Output
3 4 4 -1
8 -1 1 3 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.

Testcase 2: In the array , the next larger element to 6 is 8 , for 8 there is no larger elements hence it is -1 , 
for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger elements and hence -1.*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

vector<ll> nextLargerElement(ll arr[], ll n)
{
	stack<ll> s;
	s.push(arr[n-1]);  // push last element of the  array in the stack

	vector<ll> v;
	v.push_back(-1);  // push -1 into the stack as the next element greater to last element will always be -1.

	for(int i = n-2; i >= 0; i--)  // itreate through array from right side 
	{
		while(s.empty() == false and s.top() <= arr[i])  // if the curr element is greater than next element pop the top element 
			s.pop();

		ll nextGre = (s.empty()) ? -1 : (s.top());
		v.push_back(nextGre);
		s.push(arr[i]);
	}

	reverse(v.begin(), v.end());
	return v;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;

		ll arr[n];

		for(ll i = 0; i < n; i++)
			cin >> arr[i];

		vector<ll> v = nextLargerElement(arr, n);

		for(auto x: v)
			cout << x <<" ";
		cout << endl;
	}

	return 0;
}