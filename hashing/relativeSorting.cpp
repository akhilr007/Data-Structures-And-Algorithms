// relative sorting

/*Given two arrays A1[] and A2[] of size N and M respectively. 
The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. 
For the elements not present in A2, append them at last in sorted order. 
It is also given that the number of elements in A2[] are smaller than or equal to 
number of elements in A1[] and A2[] has all distinct elements.
Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. '
For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
2
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
8 4
2 6 7 5 2 6 8 4 
2 6 4 5
Output:
2 2 1 1 8 8 3 5 6 7 9
2 2 6 6 4 5 7 8

Explanation:
Testcase 1: After sorting the resulted output is 2 2 1 1 8 8 3 5 6 7 9.
Testcase 2: After sorting the resulted output is 2 2 6 6 4 5 7 8.
 */

#include <iostream>
#include <map>
typedef long long int lli;

using namespace std;

void realativeSorting(lli a[], lli n, lli b[], lli m)
{
	map<int, int> map;
	//store the frequency of each element in array a[] in hashtable
	for(lli i = 0; i < n; i++)
		map[a[i]]++;

	// loop through b[], if any element present in hashmap print the element as many times with its frequencies.
	// and erase the element from the hashmap
	for(lli i = 0; i < m; i++)
	{
		if(map.find(b[i]) != map.end())
		{
			int t = map[b[i]];

			while(t--)
				cout << b[i] << " ";

			map.erase(b[i]);
		}
	}

	// print the remaining elements in a sorted manner.
	for(auto it = map.begin(); it != map.end(); it++)
	{
		while(it->second--)
			cout << it->first << " ";
	}
}

int main()
{

	int t;
	cin >> t;

	while(t--)
	{
		lli n, m;
		cin >> n >> m;

		lli a[n], b[m];
		for(lli i = 0; i < n; i++)
			cin >> a[i];

		for(lli i = 0; i < m; i++)
			cin >> b[i];

		realativeSorting(a, n, b, m);
		cout << endl;
	}
	return 0;
}