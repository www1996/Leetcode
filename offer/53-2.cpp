#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 面试题53 - II. 0～n-1中缺失的数字
// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)
                return nums[i] - 1;
        }
        return nums.size();
    }
};

int main()
{
    Solution s;

    return 0;
}