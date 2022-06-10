#include <queue>
#include <iostream>
using namespace std;
queue <int>q;
priority_queue<int>pq;

int main()
{
	for (int i = 0; i < 10; i ++ )
	{
		q.push(rand());
		pq.push(rand());
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	while (!pq.empty()) 
	{//越大越优先
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}