#include <iostream>
#include <list>
#include<queue>
using namespace std;
list<int> adj[8];
queue<int> Q;
#define MAX 1000;
struct vertex
{
	int pare, dis, num;
	int color = 0;
};
vertex List[8];
void BFS(int s)
{
	List[s].dis = 0;
	List[s].pare = 0;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		while (!adj[u].empty())
		{
			int v = adj[u].front();
			if (List[v].color == 0)
			{
				List[v].color = 1;
				List[v].dis = List[u].dis+1;			
				List[v].pare = u;
				Q.push(v);
			}
			adj[u].pop_front();
		}
		List[u].color = 1;
	}
	int len = sizeof(List) / sizeof(List[0]);
	for (int i = 0; i < len; i++)
	{
		cout << "vertex:" << i << " ";
		cout << "distance" << List[i].dis << " ";
		cout << "parent:" << List[i].pare << " ";
		cout << endl;
	}
}
int main()
{	
	
	for (int i = 0; i < 7; i++)
	{
		List[i].num=i;
	}
	adj[0].insert(adj[0].begin(), { 1,4 });
	adj[1].insert(adj[1].begin(), { 0,5 });
	adj[2].insert(adj[2].begin(), { 3,5,6 });
	adj[3].insert(adj[3].begin(), { 2,6,7 });
	adj[4].insert(adj[4].begin(), { 0 });
	adj[5].insert(adj[5].begin(), { 1,2,6 });
	adj[6].insert(adj[6].begin(), { 2,3,5,7 });
	adj[7].insert(adj[7].begin(), { 3,6 });
	BFS(1);
	return 0;
}


