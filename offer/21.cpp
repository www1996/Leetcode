#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题21. 调整数组顺序使奇数位于偶数前面
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        int r = nums.size() -1;
        while( l < r)
        {
            if(nums[l] % 2 == 0)
            {
                while((nums[r] % 2 == 0))
                {
                    r--;
                    if(l == r)  return nums;
                }
                swap(nums[l],nums[r]);
            }
            else{
                l++;
            }
        }
        return nums;        

    }
};


int main()
{
    Solution s;

    return 0;
}