#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 面试题03. 数组中重复的数字
// 找出数组中重复的数字。


// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        const int MAXL = 100001;
        bool hashtable[MAXL] = {false};
        for(int i = 0; i < nums.size(); i++)
        {
            if(hashtable[nums[i]] == false)
            {
                hashtable[nums[i]] = true;
            }
            else
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 2, 3};
    s.findRepeatNumber(v);

    return 0;
}