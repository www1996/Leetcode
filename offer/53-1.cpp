#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题53 - I. 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > target)
                break;
            if(nums[i] == target)
                ans++;
        }
        return false;
    }
};

int main()
{
    Solution s;

    return 0;
}