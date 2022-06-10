#include<bits/stdc++.h>
using namespace std;

class Point {
public:
	Point(int x, int y) : x(x), y(y) {//构造函数
		count++;
		cout << "Constructor called" << endl;
	}
	Point();
	Point(const Point& p) {//复制构造函数，常引用
		x = p.x; y = p.y; count++;
	}
	void move(int newx, int newy);	
	~Point() { count--;
	cout << "Point destructor called" << endl;
	}//析构函数 
	int getX() { return x; }
	int getY() { return y; }
	static void showcount() {//不通过对象调用	
		cout << "object count=" << count << endl;
	}
	friend float dis(const Point& a,const Point& b);//先进行声明

private:
	int x, y;//私有成员
	static int count;//静态数据成员，记录点的总数,属于整个类
};

void Point::move(int newx,int newy) {
	cout << "Moving poing to (" << newx << "," << newy << ")" << endl;
	x = newx; y = newy;//对类的成员进行操作
}
Point::Point() :x(0), y(0) {
	cout << "Default constructor called" << endl;
	count++;
}
float dis(const Point& a, const Point& b) {
	double x = b.x - a.x;
	double y = b.y - a.y;//为提高效率，比getx好
	return static_cast<float>(sqrt(x * x + y * y));//类型转换
}
int Point::count = 0;//静态数据成员初始化


class ArrayOfPoint {
public:
	ArrayOfPoint(int size) :size(size) {
		points = new Point[size];
	}
	~ArrayOfPoint() {
		cout << "Deleting Array" << endl;
		delete[] points;
	}
	Point& element(int index) {//返回引用是为了参数的双向传递
		assert(index >= 0 && index < size);//保证下标不越界
		return points[index];//就可以使用Point类
	}
	ArrayOfPoint(const ArrayOfPoint& Points_arr);
private:
	Point* points;//动态数组的首地址
	int size;
};

ArrayOfPoint::ArrayOfPoint(const ArrayOfPoint& v) {
	size = v.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
		points[i] = v.points[i];
	cout << "Copy constructor called"<<endl;
}
int main() {
	cout << "Constructing one point"<<endl;
	Point* ptr1 = new Point;
	delete ptr1;//没有删除指针
	ptr1 = new Point(3,4);
	delete ptr1;
	cout << "Constructing point array" << endl;
	Point* ptr = new Point[2];
	ptr[0].move(1, 0);
	ptr[1].move(0, 1);
	cout << "Deleting normal array..."<<endl;
	delete[]ptr;
	Point::showcount();
	Point a = Point(4, 5);
	Point b = Point(1, 1);
	Point arr[2];
	cout << "a=("<<a.getX() << ',' <<a.getY() <<")"<< endl;
	Point* p1 = &b;//用对象指针访问成员
	cout << "b=(" << p1->getX() << ','  << p1->getY() << ")" << endl;
	a.showcount();//可通过对象调用
	cout <<"distance="<< dis(a, b) << endl;
	arr[0] = a; arr[1] = b;
	for (int i = 0; i < 2; i++)
		arr[i].move(i + 10, i + 11);
	ArrayOfPoint Dynamic_arr1=ArrayOfPoint(2);
	Dynamic_arr1.element(0).move(1, 1);
	Dynamic_arr1.element(0).move(2, 2);
	/*ArrayOfPoint Dynamic_arr2(Dynamic_arr1);
	默认复制构造,使用的是arr1的内存地址，导致arr1析构
	但arr2析构时没有可析构的内存，导致出错*/
	ArrayOfPoint Dynamic_arr2(Dynamic_arr1);
	return 0;
}
