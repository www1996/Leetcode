#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// 29. 两数相除
// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

// 返回被除数 dividend 除以除数 divisor 得到的商。

// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 特判
        if (divisor == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int signdiff = (dividend > 0) ^ (divisor >0);
        
        long t = abs((long)dividend);
        long d = abs((long)divisor);
        int result = 0;
        
        for (int i = 31; i >= 0; i --){
            if ((t >> i) >= d){
                result += 1 << i;
                t -= d << i;
            }
        }
        return signdiff ? -result : result;
    }
};

int main()
{
    Solution s;
    return 0;
}