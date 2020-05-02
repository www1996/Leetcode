#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题57 - II. 和为s的连续正数序列
// 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;)
        {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target)
            {
                res.clear();
                for (int i = l; i <= r; ++i)
                    res.emplace_back(i);
                vec.emplace_back(res);
                l++;
            }
            else if (sum < target)
                r++;
            else
                l++;
        }
        return vec;
    }
};

int main()
{
    Solution s;

    return 0;
}