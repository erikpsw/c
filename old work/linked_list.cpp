#include <iostream>
#include <list>
using namespace std;
list<int>list1;

int main()
{
    list1.push_front(rand());
    list1.pop_front();
    list1.push_back(rand());
    list1.pop_back();
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    while (!list1.empty()) 
    {
        cout << list1.front() << " ";
        list1.pop_front();
    }
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    cout << endl;
    list1.remove(1);
    while (!list1.empty())
    {
        cout << list1.front() << " ";
        list1.pop_front();
    }
    list1.push_front(rand());
    list1.push_front(rand());
    list1.push_front(rand());
    cout << endl;
    for (list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
        cout << *iter<<' ';
    return 0;
}
