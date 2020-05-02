#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 面试题15. 二进制中1的个数
// 请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n)
        {
            if(n % 2 == 1 ) ans++;
            n /=2;
        }
        return ans;
    }
};


int main()
{
    int i = -2;
    i = i << 4;
    cout << i << endl;
    return 0;
}