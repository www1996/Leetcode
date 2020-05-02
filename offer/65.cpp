#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
面试题65. 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

*/

//位运算， 加法定义为： 二进制下，异或（^）运算后的结果，再加上进位，进位用与(&)然后左移一位，直到进位为 0
class Solution {
public:
    int add(int a, int b) 
    {
        return b ? add(a ^ b, (unsigned int)(a & b) << 1) : a;
    }
};

int main()
{
    Solution s;

    return 0;
}