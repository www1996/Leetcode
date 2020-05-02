#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 面试题17. 打印从1到最大的n位数
// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
class Solution {
public:
    vector<int> printNumbers(int n) 
    {
        int tmp = 1;
        vector<int> ans;
        while(n--)
        {
            tmp *= 10;
        }
        for(int i = 1; i < tmp; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};



int main()
{
    Solution s;

    return 0;
}