#include<bits/stdc++.h>
#include<vec.h>
using namespace std; 
bool miny(point a, point b) { return a.getY() > b.getY(); }

int main() {
	point a = point(1, 1);
	point b = point(2.5, 2);
	point c = point(2, 0);
	point d = point(2, 4);
	point e = point(4, 4);
	point f = point(4, 2);
	vector<point> arr{ a,b,c,d,e,f };
	for (vector<point>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
		print(*iter);
	cout << endl;
	int minypos = max_element(arr.begin(), arr.end(), miny) - arr.begin();
	vector<point>::iterator start = arr.begin() + minypos;
	point u = (*start);
	arr[minypos] = arr[0];
	arr[0] = u;
	arr[0].visit = true;
	for (vector<point>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
		print(*iter);
	cout << endl;
	bool ok = true;
	int num = 0;
	while (ok) {//对角度冒泡
		num = 0;
		for (vector<point>::iterator iter = arr.begin(); iter != (arr.end() - 1); ++iter)
		{
			if ((!(toleft((*(iter + 1)), (arr[0]), (*iter))))&!(*iter).visit) {
				int dis = distance(arr.begin(), iter);
				point v = (*iter);
				arr[dis] = (*(iter + 1));
				arr[dis + 1] = v;
				++num;
			}
			if (num > 0)
				ok = 1;
			else
				ok = 0;
		}
		for (vector<point>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
			print(*iter);
		cout << endl;
	}
	//注意连续三点不能不能共线
	for (vector<point>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
		print(*iter);
	cout << endl;
	vector<point> S, T;
	S.push_back(arr[0]);
	S.push_back(arr[1]);
	T = arr;//初始化
	vector<point>::iterator it = T.begin();
	T.erase(it);
	vector<point>::iterator it1 = T.begin();
	T.erase(it1);
	for (vector<point>::iterator iter = T.begin(); iter != T.end(); ++iter)
		print(*iter);
	cout <<"T"<< endl;
	for (vector<point>::iterator iter = S.begin(); iter != S.end(); ++iter)
		print(*iter);
	cout <<"S"<< endl;
	while (T.size() > 0) {
		if (toleft(T[0], S[S.size() - 2], S[S.size() - 1])) {
			S.push_back(T[0]);
			vector<point>::iterator it2 = T.begin();
			T.erase(it2);
			for (vector<point>::iterator iter = S.begin(); iter != S.end(); ++iter)
				print(*iter);
			cout << "S1" << endl;
			for (vector<point>::iterator iter = T.begin(); iter != T.end(); ++iter)
				print(*iter);
			cout << "T1" << endl;
		}
		else {
			if (T.size() > 0)
				while (!(toleft(T[0], S[S.size() - 2], S[S.size() - 1]))) {
					S.pop_back();
					S.push_back(T[0]);
					vector<point>::iterator it3 = T.begin();
					T.erase(it3);
					for (vector<point>::iterator iter = S.begin(); iter != S.end(); ++iter)
						print(*iter);
					cout << "S2" << endl;
					for (vector<point>::iterator iter = T.begin(); iter != T.end(); ++iter)
						print(*iter);
					cout << "T2" << endl;
				}
		}//注意前和后
	}
}