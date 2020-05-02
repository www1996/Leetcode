#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 面试题14- I. 剪绳子
// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。
// 请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
class Solution {
public:
    int cuttingRope(int n) {
        int max = 1;
        for (int m = 2; m <= n; m++) {
            int s = n / m; // 商
            int y = n % m; // 余数
            int res = 1;
            for (int i = 0; i < m - y; i++) {
                res *= s;
            }
            for (int i = 0; i < y; i++) {
                res *= s + 1;
            }
            if (res > max) {
                max = res;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;

    return 0;
}