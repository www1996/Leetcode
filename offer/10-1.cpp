#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题10- I. 斐波那契数列
// 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

class Solution {
public:
    int fib(int n) 
    {
        vector<int> v = {0, 1};
        for (int i = 2; i <= n; i ++)
        {
            v.push_back((v[i - 1] + v[i - 2]) % 1000000007);
        }
        return v[n];
    }
};
int main()
{
    Solution s;
    cout<<s.fib(34);

    return 0;
}