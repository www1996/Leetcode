#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 面试题42. 连续子数组的最大和
// 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 要求时间复杂度为O(n)。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxS = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i -1] > 0)
                nums[i] += nums[i - 1];
            maxS = max(nums[i], maxS);
        }
        return maxS;
    }
};

int main()
{

    return 0;
}