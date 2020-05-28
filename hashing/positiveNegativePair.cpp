// positive negative pairs

/*Given an array arr[] of N positive and negative integer pairs, may not be in sorted order. 
The task is to pair the positive and negative element in such a way 
that a positive element is paired with a negative element of same absolute value. 
If a pair element is not present for an element, then ignore it. 
The output should contain all pairs in increasing order of absolute values. 
To print a pair, positive value should be printed before its corresponding negative value.
Note: The elements in array are distinct.

Input:
First line of input contains number of testcases T. 
For each testcase, first line contains an integer N, number of elements in the array. 
Next line contains N space separated array elements.

Output:
For each testcase, print the pairs of positive and negative, sorted with positive numbers. 
If no such pair exists, print 0.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
8
1 3 6 -2 -1 -3 2 7
3
3 2 -3
Output:
1 -1 2 -2 3 -3
3 -3

Explanation:
Testcase 1: 1, 2 and 3 are present pairwirse postive and negative. 6 and 7 have no pair.
Testcase 2: 3 is the only element present pairwise positive and negative.*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void posNegPair(int arr[], int n)
{
	unordered_set<int> s, set;
	// inserting all the values into a set
	for(int i = 0; i < n; i++)
		s.insert(arr[i]);

	// traversing into the set s 
	for(int x : s)
	{	
		// finding the negative pair if present store the absolute value in set.
		if(s.find(-1 * x) != s.end())
			set.insert(abs(x));
	}

	for(int i = 0; i < n; i++)
	{
		if(set.find(arr[i]) != s.end())
			cout << arr[i] << " " << -arr[i] << " ";
	}

	if(set.empty())
		cout << 0;

}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		// we are sorting the array
		sort(arr, arr + n);

		posNegPair(arr, n);
		cout << endl;
	}
	return 0;
}

