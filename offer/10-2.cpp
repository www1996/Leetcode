#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 面试题10- II. 青蛙跳台阶问题
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

class Solution {
public:
    int numWays(int n) 
    {
        vector<int> v = {1, 1, 2};
        for (int i = 3; i <= n; i ++)
        {
            v.push_back((v[i - 1] + v[i - 2]) % 1000000007);
        }
        return v[n];
    }
};
int main()
{
    Solution s;

    return 0;
}