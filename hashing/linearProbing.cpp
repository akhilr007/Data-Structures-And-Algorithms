// Linear probing in hashing

#include <iostream>
using namespace std;

void LinearProbing(int hash[], int hashSize, int arr[], int sizeOfArray)
{
	int counter = 0, hashValue;
	for(int i = 0; i < sizeOfArray; i++)
	{
		hashValue = arr[i] % hashSize;
		if(hash[hashValue] == -1)
		{	
			hash[hashValue] = arr[i];
			counter = counter + 1;
		}

		else
		{
			int value;
			value = hash[hashValue];

			while(hash[hashValue] != -1 && counter != -1)
			{
				value = value + 1;
				hashValue = value % hashSize;
			}
			if(counter != hashSize)
			{
				hash[hashValue] = arr[i];
				counter = counter + 1;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int hashSize, sizeOfArray;
		cin >> hashSize;
		cin >> sizeOfArray;

		int arr[sizeOfArray];
		for(int i = 0; i < sizeOfArray; i++)
			cin >> arr[i];

		int hash[hashSize];
		for(int i = 0; i < hashSize; i++)
			hash[i] = -1;

		LinearProbing(hash, hashSize, arr, sizeOfArray);

		for(int i = 0; i < hashSize; i++)
			cout << hash[i] << " ";
		cout << endl;
	}

	return 0;
}