#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*

面试题60. n个骰子的点数
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

*/

class Solution
{
public:
    vector<double> twoSum(int n)
    {
        int dp[12][67] = {0};

        for (int i = 1; i <= 6; ++i)
        {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = 1; k <= 6; ++k)
                {
                    if (j - k <= 0)
                        break;
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ans;
        for (int i = n; i <= 6 * n; ++i)
        {
            ans.push_back(dp[n][i] * 1.0 / all);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    return 0;
}