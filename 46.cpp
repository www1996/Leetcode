#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//Solution A: 
// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<vector<int>> permute(vector<int>& nums) 
//     {
//         if(nums.empty())
//             return res;
//         recursion(nums, 0);
//         return res;
//     }
//     void recursion(vector<int> &vec, int len)
//     {
//         if(len == vec.size())
//         {
//             res.push_back(vec);
//             return;
//         }
//         for (int i = len; i < vec.size(); i++)
//         {
//             swap(vec[len], vec[i]);
//             recursion(vec, len + 1);
//             swap(vec[len], vec[i]);

//         }
//     }
// };
//Solution B:
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        dfs(path, used, nums);
        return ans;
    }
    void dfs(vector<int> &path, vector<bool> &used,vector<int> &nums)
    {
        if(path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(!used[i])
            {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(path, used, nums);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> vec = {1, 2, 3};
    s.permute(vec);
    return 0;
}