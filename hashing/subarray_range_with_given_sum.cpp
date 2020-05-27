// subarray range with given sum

/*Given an unsorted array arr[] of N integers and a sum. The task is to count the number of subarray which adds to a given number.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated integers forming the array. The last line contains an integer denoting the value of the sum.

Output:
For each testcase, in a new line, print the count of the subarray which adds to the given sum.

Your Task:
This is a function problem. You only need to complete the function subArraySum() that takes arr, n, sum as parameters and returns the count.

Constraints:
1 <= T <= 200
1 <= N <= 105
-105 <= arr[i] <= 105
-105 <= sum <= 105

Example:
Input:
2
5
10 2 -2 -20 10
-10
6
1 4 20 3 10 5
33
Output:
3
1

Explanation:
Testcase 1: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
Testcase 2: Subarray with sum 33 is: [20,3,10].*/

#include <iostream>
#include <unordered_map>

using namespace std;

int subArraySum(int arr[], int n, int sum)
{
	unordered_map<int, int> m;

	int count = 0, curr_sum = 0;

	for(int i = 0; i < n; i++)
	{
		// calcualting the prefix sum
		curr_sum = curr_sum + arr[i];

		// if prefix sum is equal to sum increment count
		if(curr_sum == sum)
			count++;

		// if curr_sum - sum is present in array
		// increment count with no of occurences with particular element
		if(m.find(curr_sum - sum) != m.end())
			count = count + m[curr_sum - sum];

		m[curr_sum]++;
	}
	return count;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n, sum;
		cin >> n;

		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		cin >> sum;

		cout << subArraySum(arr, n, sum) << endl;
	}
	return 0;
}