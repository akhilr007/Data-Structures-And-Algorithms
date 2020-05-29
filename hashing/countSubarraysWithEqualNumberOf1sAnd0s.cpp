// subarrays with equal of 0s and 1s

/*Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. 
First line of each test case contains an Integer N denoting size of array and the second line contains N space separated 0 and 1.

Output:
For each test case, in a new line, print the count of required sub arrays in new line

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function countSubarrWithEqualZeroAndOne() which takes the array arr[] and 
the size of the array as inputs and returns the number of subarrays with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
7
1 0 0 1 0 1 1
5
1 1 1 1 0
Output:
8
1

Explanation:
Testcase 1: The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6)
Testcase 2: The index range for the subarray is (3,4).
 */

#include <iostream>
#include <unordered_map>

using namespace std;

void equalSubarray(int arr[], int n)
{
	unordered_map<int, int> m;
	// putting every element in an array with value 0 to 1.
	for(int i = 0; i < n; i++)
		if(arr[i] == 0)
			arr[i] = -1;

	// after this the problem is same as zero sum subarray
	int sum = 0, count = 0;
	int curr_sum = 0;

	for(int i = 0; i < n; i++)
	{
		curr_sum = curr_sum + arr[i];

		if(curr_sum == sum)
			count++;

		if(m.find(curr_sum-sum) != m.end())
			count = count + m[curr_sum-sum];

		m[curr_sum]++;
	}
	cout << count;
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

		equalSubarray(arr, n);
		cout << endl;
	}
	return 0;
}