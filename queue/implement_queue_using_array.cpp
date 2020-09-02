// implement queue using array

#include <iostream>
using namespace std;

struct queueNode
{
	int data;
	queueNode *next;
};

class myQueue
{
private:
	int arr[100005];
	int front;
	int rear;

public:
	myQueue()
	{
		front = 0;
		rear = 0;
	}

	void push(int);
	int pop();
};

void myQueue :: push(int x)
{
	arr[rear++] = x;
}

int myQueue :: pop()
{
	if(front >= rear)
		return -1;
	else
		return arr[front++];
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		myQueue *sq = new myQueue();

		int q;
		cin >> q;

		while(q--)
		{
			int queryType = 0;
			cin >> queryType;

			if(queryType == 1)
			{
				int a;
				cin >> a;
				sq->push(a);
			}

			else if(queryType == 2)
			{
				cout << sq->pop() << " ";
			}
		}

		cout << endl;
	}

	return 0;
}