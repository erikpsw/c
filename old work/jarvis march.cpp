#include <bits/stdc++.h>
#include <vec.h>
using namespace std;

bool maxx(point a, point b) { return a.getX() < b.getX(); }
bool minx(point a, point b) { return a.getX() > b.getX(); }
bool maxy(point a, point b) { return a.getY() < b.getY(); }
bool miny(point a, point b) { return a.getY() > b.getY(); }

int main()
{
	point a = point(1, 1);
	point b = point(2.5, 2);
	point c = point(2, 0);
	point d = point(2, 4);
	point e = point(4, 4);
	point f = point(4, 2);
	vector<point> arr{a, b, c, d, e, f};
	for (vector<point>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
		print(*iter);
	cout << endl;
	int maxxpos = max_element(arr.begin(), arr.end(), maxx) - arr.begin();
	int minxpos = max_element(arr.begin(), arr.end(), minx) - arr.begin();
	int maxypos = max_element(arr.begin(), arr.end(), maxy) - arr.begin();
	int minypos = max_element(arr.begin(), arr.end(), miny) - arr.begin();
	//测试
	vector<point>::iterator start = arr.begin() + minxpos; //起始(必须是极点)
	point first = (*start);								   //保存起始位置
	vector<point>::iterator now = arr.begin() + 1;
	vector<point> result = {};
	while ((*now) != first)
	{ //首尾相连
		result.push_back(*start);
		int count = 0;
		for (vector<point>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
		{
			if ((*iter).isVisit())
				continue;
			else
			{
				count++; //初始化新极点
				if (count == 1)
					now = iter;
				if (toleft(*iter, *start, *now))
					continue;
				else
				{
					now = iter;
				}
			}
		}
		start = now;
		(*start).visit = true;
	}
	for (vector<point>::iterator iter = result.begin(); iter != result.end(); ++iter)
		print(*iter);
}