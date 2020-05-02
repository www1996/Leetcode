#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*

面试题59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.empty())    return ans;
        for(int i = 0; i < nums.size() - k + 1; i++)
        {
            int max = nums[i];
            for(int j = i; j < i + k; j ++)
            {
                if(nums[j] > max)   max = nums[j];
            }
            ans.push_back(max);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    return 0;
}