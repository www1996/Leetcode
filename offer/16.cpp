#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题16. 数值的整数次方
// 实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) { return 1; }
        if (n == 1) { return x; }
        if (n == -1) { return 1 / x; }
        double half = myPow(x, n / 2);
        double rest = myPow(x, n % 2);
        return rest * half * half;
    }
};


int main()
{
    Solution s;
    double ans = s.myPow(2.0, -10);
    cout << ans << endl;
    return 0;
}