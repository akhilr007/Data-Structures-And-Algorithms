// intersection of two arrays

/*Intersection of two arrays
Given two arrays A and B respectively of size N and M. 
The task is to print the count of elements in the intersection (or common elements) of the two arrays.
For this question, intersection of two arrays can be defined as the set containing distinct common elements between the two arrays.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and M, N is the size of array A and M is size of array B. 
The second line of each test case contains N input A[i].
The third line of each test case contains M input B[i].

Output:
Print the count of intersecting elements.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, M ≤ 105
1 ≤ A[i], B[i] ≤ 105

Example:
Input:
4
5 3
89 24 75 11 23
89 2 4
6 5
1 2 3 4 5 6
3 4 5 6 7
4 4
10 10 10 10
20 20 20 20
3 3
10 10 10
10 10 10
Output:
1
4
0
1

Explanation:
Testcase 1: 89 is the only element in the intersection of two arrays.
Testcase 2: 3 4 5 and 6 are the elements in the intersection of two arrays.
Testcase 3: Non of the elements are common so the output will be -1.
Testcase 4: 10 is the only element which is in the intersection of two arrays.*/

#include <iostream>
#include <unordered_map>
//#include <unordered_set> if using set

typedef long long int lli;

using namespace std;

void intersection(lli a[], lli n, lli b[], lli m)
{
	unordered_map<lli, lli> map;  // we can also use unordered_set<int> s;

	// storing elements of first array into hashtable or set.
	for(lli i = 0; i < n; i++)
		map[a[i]] = a[i];   // s.insert(a[i]);

	int count = 0;

	// now iterating through the second array and search for the element into the hashtable.
	// if exists increase the counter and erase the element from the hashtable.
	for(lli i = 0; i < m;i++)
	{
		if(map.find(b[i]) != map.end())   // if(s.find(b[i]) != s.end())
				{
					count++;			// count++;		
					map.erase(b[i]);	// s.erase(b[i]);
				}
	}

	cout << count << endl;
}

int main()
{
	lli t;
	cin >> t;

	while(t--)
	{
		lli n , m;
		cin >> n >> m;

		lli a[n], b[m];

		for(lli i = 0; i < n; i++)
			cin >> a[i];

		for(lli i = 0; i < m; i++)
			cin >> b[i];

		intersection(a, n, b, m);
	} 
	return 0;
}