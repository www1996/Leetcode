#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 78. 子集
// 给定一组含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(ans, path, nums, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int> &path, vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        dfs(ans, path, nums, index + 1);
        path.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1])
        {
            index++;
        }
        dfs(ans, path, nums, index + 1);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3};

    return 0;
}