#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 给定一个 有重复 数字的序列，返回其所有可能的全排列。

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
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
            if(used[i] || (i > 0 && nums[i] == nums[i -1] && !used[i -1])) //!used[i -1] 这个剪枝指的是上一个相同元素被撤销选择
                continue;
            else
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

    return 0;
}