// quadratic probing in hashing'
/*Quadratic probing is a collision handling technique in hashing. 
Quadratic probing says that whenever a collision occurs, search for i2 position.

In this question, we'll learn how to fill up the hash table using Quadratic probing technique. 
You are given hash table size which you'll use to insert elements into their correct position in the hash table. 
You are also given an array arr[] of size N. You need to fill up the hash table using Quadratic probing and print the resultant hash table.
Note:

All the positions that are unoccupied are denoted by -1 in the hash table.
An empty slot can only be found if load factor < 0.5 and hash table size is a prime number.
The given testcases satisfy the above condition so you can assume that an empty slot is always reachable.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 3 lines of input. 
The first line contains size of the hashtable. The second line contains size of the array. The third line contains elements of the array.

Output:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. 
You only need to complete the function QuadraticProbing that takes hash, hashSize, arr, and sizeOfArray
 as parameters and inserts elements of arr in hash. The printing is done by the driver code.

Constraints:
1 <= T <= 100
2 <= hashSize (prime) <= 97
1 <= sizeOfArray < hashSize*0.5
0 <= Array[] <= 105

Examples:
Input:
2
11
4
21 10 32 43
11
4
880 995 647 172 
Output:
10 -1 -1 32 -1 -1 -1 -1 43 -1 21
880 -1 -1 -1 -1 995 -1 172 -1 647 -1 

Explanation:
Testcase1: 21%11=10 so 21 goes into hashTable[10] position. 10%11=10. hashTable[10] is already filled so we try for (10+12)%11=0 position.
 hashTable[0] is empty so we put 10 there. 32%11=10. hashTable[10] is filled. We try (32+12)%11=0. But hashTable[0] is also already filled. 
 e try (32+22)%11=3. hashTable[3] is empty so we put 32 in hashTable[3] position. 43 uses (43+33)%11=8. We put it in hashTable[8].

Testcase2: Using the similar approach as used in above explanation we will get the output like 880 -1 -1 -1 -1 995 -1 172 -1 647 -1 .*/

#include <iostream>
#include <cmath>
using namespace std;

void quadraticProbing(int hash[], int hashSize, int arr[], int sizeOfArray)
{
	int hashValue;
	for(int i = 0; i < sizeOfArray; i++)
	{
		hashValue = arr[i] % hashSize;

		//if position of hashtable is empty ,i.e, -1 then insert the value to the hashtable.
		if(hash[hashValue] == -1)
			hash[hashValue] = arr[i];

		// if there is a collision search for positions by incrementing i^2 .
		else
		{
			int k = arr[i];
			for(int j = 1; j < hashSize; j++)
			{
				// implementation for quadratic probing
				hashValue = (k + (int)pow(j,2)) % hashSize;
				// if we get the value insert the value to the hashtable, else continue.
				if(hash[hashValue] == -1)
				{
					hash[hashValue] = arr[i];
					break;
				}
				else
					continue;
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

		int hash[hashSize];

		int arr[sizeOfArray];
		for(int i = 0; i < sizeOfArray; i++)
			cin >> arr[i];

		// intialising hashtable with -1
		for(int i = 0; i < hashSize; i++)
			hash[i] = -1;

		// function to implement quadratic probing in hashing
		quadraticProbing(hash, hashSize, arr, sizeOfArray);

		// to display the hash table
		for(int i = 0; i < hashSize; i++)
			cout << hash[i] << " ";
		cout << endl;
	}
	return 0;
}

