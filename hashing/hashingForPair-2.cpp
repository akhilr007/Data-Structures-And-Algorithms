// hashing for pair -2

/*You are given an array A[] of size N, and you are also given a sum. You need to find if two numbers in A exists that have sum equal to the given sum.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains three lines of input. The first line contains N denoting the size of the array A. The second line contains N elements of the array. The third line contains element sum.

Output:
For each testcase, in a new line, print the required output.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function sumExists().

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
4
4 3 5 6
12
Output:
1
0

Explanation:
Testcase 1: there exists a pair which gives sum as 14 example (4,10), (5,9) etc.
Testcase 2: there does not exist any such pair which gives sum as 12.*/

#include <iostream>
#include <unordered_set>

typedef long long int lli;

using namespace std;

int hashingForPair(lli arr[], int size, int sum)
{
	unordered_set<int> s;

	for(int i = 0; i < size; i++)
	{
		if(s.count(sum - arr[i]) != 0)
			return 1;
		else
			s.insert(arr[i]);
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
