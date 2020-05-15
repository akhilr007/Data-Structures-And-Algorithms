// print non repeating element

/*Hashing is very useful to keep track of the frequency of the elements in a list.

You are given an array arr of size n. You need to print the non-repeated elements as they appear in the array.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains n denoting the size of the array. The second line contains n elements of the array.

Output:
For each testcase, in a new line, print the non-repeated elements in the order they appear in the array.

Your Task:
This is a function problem. You only need to complete the function printNonRepeated() that takes arr and n as parameters and prints the distinct elements in same order as they appear in input array. The newline is appended automatically by the driver code.

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
10 20 40 30 10
Output:
4 5 6 7
20 40 30

Explanation:
Testcase 1: 4, 5, 6 and 7 are the only elements which is having only 1 frequency and hence, Non-repeating.
Testcase 2: 20, 40, 30 are the only elements which is having only 1 frequency and hence, Non-repeating.*/

#include <iostream>
#include <unordered_map>

using namespace std;

void printNonRepeatingElements(int arr[], int n)
{
	unordered_map<int, int> m;

	for(int i = 0; i < n; i++)
		m[arr[i]]++;

	int counter = 0;
	for(int i = 0; i < n; i++)
		if(m[arr[i]] == 1)
			cout << arr[i] << " ";

	cout << endl;
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

		printNonRepeatingElements(arr, n);
	}

	return 0;
}