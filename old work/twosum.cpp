#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
void twoSum(vector<int> nums, vector<int>& res, int target)
{
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                break;
            }
            if (res.size() != 0)
                break;
        }
        if (res.size() != 0)
            break;
    }//return 语句只能出现在函数体中
}


int main() {
    vector<int> ans{ 3,2,4 };
    int target = 6;
    vector<int> res;
    twoSum(ans, res, target);
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
        cout << *iter << ' ';
}
