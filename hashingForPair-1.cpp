// hashing of pair -1
/*
You are given an array A (distinct integers) of size N, and you are also given a sum. You need to find if two numbers in A exists that have sum equal to the given sum.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains three lines of input. The first line contains N denoting the size of the array A. The second line contains N elements of the array. The third line contains element sum.

Output:
For each testcase, in a new line, print  "1"(without quotes) if any pair found, othwerwise print "0"(without quotes) if not found.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function sumExists.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= Ai <= 106
1 <= sum <= 1000

Examples:
Input:
2
10
1 2 3 4 5 6 7 8 9 10
14
2
2 5
10
Output:
1
0

Explanation:
Testcase 1: arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} and sum = 14.  There is a pair {4, 10} with sum 14.
Testcase 2: arr[]  = {2, 5} and sum = 10. There is no pair with sum 10.*/


#include <iostream>
#include <unordered_map>

typedef long long int lli;

using namespace std;

int hashingForPair(lli arr[], int size, int sum)
{
	unordered_map<int, int> m;

	for(int i = 0; i < size; i++)
	{
		// to find the pairs which is equal to sum , i.e, x+y = sum
		// we can write it as x = sum - y
		// so to find the pairs we will use an empty hashtable.
		// if its not present in hashtable we will add it in hashtable 
		// it its present then just return 1 otherwise 0.
		if(m.find(sum - arr[i]) != m.end())
			return 1;
		else
			m[arr[i]] = arr[i];
	}
	return 0;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int size;
		cin >> size;

		lli arr[size];
		for(int i = 0; i < size; i++)
			cin >> arr[i];

		int sum;
		cin >> sum;

		cout << hashingForPair(arr, size, sum) << endl;
	}
	return 0;
}