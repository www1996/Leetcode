#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 如果数组中不存在目标值，返回 [-1, -1]。
class Solution {
public:
    int binary_search(int l, int r, vector<int> nums, int target)
    {
        while(l <= r)
        {
            int m = (r + l) / 2;

            if(nums[m] == target)
                return m;
            else if( nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int index = binary_search(0, nums.size() - 1, nums, target);
        vector<int> ans = {-1, -1};
        if(index == -1)
            return {-1, -1};
        int l = index;
        while(binary_search(0, l - 1 , nums, target) != -1)
        {
            l = binary_search(0, l - 1 , nums, target);
        }
        ans.push_back(l);

        while(binary_search(l + 1, nums.size() -1 , nums, target) != -1)
        {
            l = binary_search(l + 1, nums.size() -1 , nums, target);
        }
        ans.push_back(l);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = { 1 };
    s.searchRange(v, 1);

    return 0;
}