// subarray with zero sum

/*Given an array a[] of N positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains an integer n denoting the size of the array. 
The next line contains N space separated integers forming the array.

Output:
Print "Yes" (without quotes) if there exist a subarray of size at least one with sum equal to 0 or else print "No" ( without quotes).

Your Task:
This is a function problem. 
You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false.

Constraints:
1 <= T <= 100
1 <= N <= 104
-105 <= a[i] <= 105

Example:
Input:
2
5
4 2 -3 1 6
5
4 2 0 1 6
Output:
Yes
Yes

Explanation:
Testcase 1: 2, -3, 1 is the subarray with sum 0.
Testcase 2: 0 is one of the element in the array so there exist a subarray with sum 0.*/

#include <iostream>
#include <unordered_set>

typedef long long int lli;

using namespace std;

bool subArrayExists(lli arr[], lli n)
{	/*
		arr[] = {1, 4, -2, -2, 5, -4, 3}

	If we consider all prefix sums, we can
	notice that there is a subarray with 0
	sum when :
	1) Either a prefix sum repeats or
	2) Or prefix sum becomes 0.

	Prefix sums for above array are:
	1, 5, 3, 1, 6, 2, 5

	Since prefix sum 1 repeats, we have a subarray
	with 0 sum.*/

	int sum = 0;

	unordered_set<int> s;

	for(lli i = 0; i < n; i++)
	{
		sum = sum + arr[i];

		if(sum == 0 || s.find(sum) != s.end())
			return true;
		s.insert(sum);
	}
	return false;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		lli n;
		cin >> n;

		lli arr[n];
		for (lli i = 0; i < n ; i++)
			cin >> arr[i];

		// to check if subarray with sum equals to zero exists or not.
		if(subArrayExists(arr, n))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}