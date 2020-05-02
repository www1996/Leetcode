#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

面试题45. 把数组排成最小的数
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

*/
class Solution {
public:
    static bool cmp(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1 + s2 < s2 + s1;
    }
    string minNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(),cmp);
        string ans = "";
        for(auto s:nums)
        {
            ans += to_string(s);
        }
        return ans;
    }
};


int main()
{
    Solution s;

    return 0;
}