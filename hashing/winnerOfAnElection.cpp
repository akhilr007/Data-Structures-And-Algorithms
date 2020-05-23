// winner of an election 

/*Given an array of names (consisting of lowercase characters) of candidates in an election.
A candidate name in array represents a vote casted to the candidate. 
Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. 
Then T test case follows. Each testcase contains two lines input. First line is the number of votes cast N.
And second line is the name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output:
For each testcase, print the name of the candidate with the maximum votes, and also print the votes casted for the candidate. 
The name and votes are separated by a space.

Your Task:
This is a functional problem. 
You only need to complete the function winnter() that takes an array of strings arr, 
and n as parameters and prints the candiate with maximum votes. Newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark
Output:
john 4
andy 1

Explanation:
Testcase1: john has 4 votes casted for him, but so does johny. john is lexicographically smaller, so we print john and the votes he received.
Testcase2: All the candidates get 1 votes each. We print andy as it is lexicographically smaller.*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void findWinner(string arr[], int n)
{
	unordered_map<string, int> m;

	// incresing the frequency of occurences of each element in an hashmap
	for(int i = 0; i < n; i++)
		m[arr[i]]++;

	int maxValue = 0;
	string winner;

	// traversing in a map
	for(auto it: m)
	{
		string key = it.first;
		int val = it.second;

		if(val > maxValue)
		{
			maxValue = val;
			winner = key;
		}

		else if(val == maxValue && winner > key)
			winner = key;
	}

	cout << winner << " " <<maxValue;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		string arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		findWinner(arr, n);
		cout << endl;
	}
	return 0;
}