#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
面试题47. 礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

*/

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (size_t i = 1; i < grid.size(); ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (size_t j = 1; j < grid[0].size(); ++j)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (size_t i = 1; i < grid.size(); ++i)
        {
            for (size_t j = 1; j < grid[0].size(); ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};

int main()
{
    Solution s;

    return 0;
}