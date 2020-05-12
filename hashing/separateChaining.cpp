// Separate Chaining in Hashing

#include <iostream>
#include <vector>
typedef long long int  lli;

using namespace std;

void SeparateChaining(vector<vector <lli>> &hashTable, lli hashSize, lli Arr[], lli sizeOfArray)
{
	int value;
	for(lli i = 0; i < sizeOfArray; i++)
	{
		value = Arr[i]%hashSize;
		hashTable[value].push_back(Arr[i]);
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		lli hashSize, sizeOfArray;
		cin >> hashSize;
		cin >> sizeOfArray;

		lli Arr[sizeOfArray];
		for(lli i = 0; i < sizeOfArray; i++)
			cin >> Arr[i];

		vector<vector <lli>> hashTable(hashSize);

		// function to implement separate chaining in hashing
		SeparateChaining(hashTable, hashSize, Arr, sizeOfArray);

		// to display the hashtable
		for(lli i = 0; i < hashTable.size(); i++)
		{
			if(hashTable[i].size() > 0)
			{
				cout << i << "->";
				for(lli j = 0; j < hashTable[i].size() - 1; j++)
					cout << hashTable[i][j] <<"->";
				cout << hashTable[i][hashTable[i].size()-1];
				cout << endl;
			}
		}

	}	
	return 0;
}