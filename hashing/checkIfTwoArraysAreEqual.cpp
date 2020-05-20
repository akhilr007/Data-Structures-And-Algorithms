// check if two arrays are equal or not 

/*Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not.
Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation)
of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow.  Each test case contains 3 lines of input. 
The first line contains an integer N denoting the size of the array. 
The second line contains element of array A[]. The third line contains elements of the array B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[],B[] <= 1018

Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15
Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1}; Since all the array elements are same. So,
Output : 1
Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15}; Since all the array elements are not same. So,
Output : 0*/


#include <iostream>
#include <unordered_map>

typedef long long int lli;

using namespace std;

int checkArrayEqual(lli a[], lli b[], lli n)
{
	unordered_map<lli, lli> m;

	// store the elements of a[] in hashtable and count the frequency of elements.
	for(lli i = 0; i < n; i++)
		m[a[i]]++;

	for(lli i = 0; i < n; i++)
	{	
		// iterate through the b[] and find if elements of b[] are not present in a[]
		// then return 0
		if(m.find(b[i]) == m.end())
			return 0;
		// if elements of b[] appears more times than a[] then return false
		if(m[b[i]] == 0)
			return 0;
		// reduce the count of elememts, if the elements are present in both arrays.
		m[b[i]]--;
	}

	return 1;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		lli n;
		cin >> n;

		lli a[n];
		for(lli i = 0; i < n; i++)
			cin >> a[i];

		lli b[n];
		for(lli i = 0; i < n; i++)
			cin >> b[i];

		cout << checkArrayEqual(a, b, n) << endl;
	}
	return 0;
}