// numbers containing 1, 2 and 3

/*Given an array arr[] of N numbers. The task is to print only those numbers whose digits are from set {1,2,3}.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines. 
First line of each test case contains an integer N and the second line contains N space separated array elements.

Output:
For each test case, In new line print the required elements in increasing order. 
if there is no such element present in the array print "-1".

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
3
4 6 7
4
1 2 3 4
5
12 111 34 13 55
Output:
-1
1 2 3
12 13 111

Explanation:
Testcase 1: No elements are there in the array which contains digits 1, 2 or 3.
Testcase 2: 1, 2 and 3 are the only elements in the array which conatins digits as 1, 2 or 3.
Testcase 3: 12 , 13 and111 are the three elements in the array which contains digit as 1 , 2 or 3.*/

#include <iostream>
#include <map>
typedef long long int lli;

using namespace std;

// to check that a given number is valid or not ,i.e, it contains 1 2 3 or not.
bool isValid(lli n)
{	
	//
	int digit ;

	if (n == 0) return 0;

	while(n != 0)
	{
		digit = n % 10;
		if(digit == 1 || digit == 2 || digit == 3) 
			n = n / 10;
		else
			return 0;
	}
	return 1;
}

void numContaining(lli arr[], lli n)
{
	// we are using map because it will store elements in ordered way.
	map<lli, lli> m;

	// if the given element in an array is valid then we increase the frequency.
	for(lli i = 0; i < n; i++)
		if(isValid(arr[i]))
			m[arr[i]]++;

	// here flag is used to detect whether such elements exists or not.
	int flag = 0;
	// we are traversing the map
	// by checking the occurences of numbers 
	// we will print the numbers if exists otherwise print -1.
	for(auto it = m.begin(); it != m.end(); it++)
	{
		while(it -> second--)
			cout << it -> first << " ";
		flag = 1;
	}

	if(flag == 0)
		cout << -1;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		lli n;
		cin >> n;

		lli arr[n];
		for(lli i = 0; i < n; i++)
			cin >> arr[i];

		numContaining(arr, n);
		cout << endl;
	}
	return 0;
}