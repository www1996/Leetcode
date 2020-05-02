#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <3)    
            return ans;
        sort(nums.begin(), nums.end());

        
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1, r = nums.size() - 1;
            int now = nums[i];
            if(now > 0)
                break;
            while(l < r)
            {
                if(nums[l] + nums[r] == -now)
                {
                    int L = nums[l];
                    int R = nums[r];
                    vector<int> tmp{now,L,R};
                    ans.push_back(tmp);
                    while(l < r && L == nums[l])
                    {
                        l++;
                    }
                    while(l < r && R == nums[r])
                    {
                        r--;
                    }
                }
                else if(nums[l] + nums[r] > -now)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            while(i < nums.size() -1 && now == nums[i + 1])
            {
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,-1,-1,0};
    s.threeSum(v);
    return 0;
}