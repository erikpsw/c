#include <iostream>
#include <vector>

using namespace std;

struct vertex
{
	int pare = 0;//父节点
	int find = 0; //访问时间
	int finish=0;//返回时间
	int color = 0;
};
vector<int>adj[6];//邻接表
vertex vert[6];//六个点
int time = 0;//目前时间

void DFS_visit(int num)
{

	vert[num].find = ++time;
	vert[num].color = 1;
	for (unsigned i = 0; i < adj[num].size(); i++)
	{	
		int t = adj[num][i];
		if (vert[t].color == 0)
		{
			vert[t].pare = num;
			DFS_visit(t);
		}
	}
	vert[num].finish = ++time;//源节点没有父节点
}
void DFS()
{
	for (int i = 0; i <= 5; i++)
	{
		if (vert[i].color == 0)//没被访问
			DFS_visit(i);
	}
}

int main()
{
	adj[0].insert(adj[0].begin(), { 1,3 });
	adj[1].insert(adj[1].begin(), { 4 });
	adj[2].insert(adj[2].begin(), { 4,5 });
	adj[3].insert(adj[3].begin(), { 1 });
	adj[4].insert(adj[4].begin(), { 3 });
	adj[5].insert(adj[5].begin(), { 5 });
	DFS();
	for (int i = 0; i <= 5; i++)
	{
		printf("vertex: %d\n",i);
		printf("find: %d\n", vert[i].find);
		printf("finish:%d\n", vert[i].finish);
		cout << endl;
	}
}