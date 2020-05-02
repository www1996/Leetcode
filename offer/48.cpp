#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
面试题48. 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        string tmp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (tmp.find(s[i]) == -1)
            {
                tmp += s[i];
                if (ans < tmp.length())
                    ans = tmp.length();
            }
            else
            {
                tmp.erase(0, tmp.find(s[i]) + 1);
                tmp += s[i];
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;


    return 0;
}