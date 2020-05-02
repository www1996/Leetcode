#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题57. 和为s的两个数字
// 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            if(nums[l] + nums[r] == target)
            {
                return {nums[l], nums[r]};
            }
            else if(nums[l] + nums[r] > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return {-1, -1};
    }
};


int main()
{
    Solution s;

    return 0;
}