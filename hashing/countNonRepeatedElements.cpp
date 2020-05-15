// count of non repeated elements in an array

/*Hashing is very useful to keep track of the frequency of the elements in a list.

You are given an array arr[] of size n. You need to print the count of non-repeated elements in the array.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains an integer n denoting the size of the array. The second line contains n space separated elements of the array.

Output:
For each testcase, in a new line, print the count of distinct elements in the array.

Your Task:
This is a function problem. You only need to complete the function countNonRepeated() that takes arr and n as parameters and returns count.

Constraints:
1 <= T <= 100
1 <= n <= 103
0 <= arri <= 107

Examples:
Input:
2
10
1 1 2 2 3 3 4 5 6 7
5
10 20 30 40 10
Output:
4
3

Explanation:
Testcase 1: 4, 5, 6 and 7 are the elements with frequency 1 and rest elements are repeated so the number of non-repeated elements are 4.
Testcase 2: 20, 30, 40 are the elements with the frequency 1 and 10 is the repeated element to number of non-repeated elements are 3.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

void nonRepeatingElement(int arr[], int n)
{
	unordered_map<int, int> m;

	// to count the frequency of the elements in an array using hashtable.
	for(int i = 0; i < n; i++)
		m[arr[i]]++;

	int counter = 0; // to keep the track of elements which have frequency 1.
	for(int i = 0; i < n; i++)
		if(m[arr[i]] == 1)
			counter++;
	cout << counter << endl;
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

		nonRepeatingElement(arr, n);
	}

	return 0;
}