#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题20. 表示数值的字符串
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"及"-1E-16"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

class Solution
{
public:
    bool isNumber(string s)
    {
        bool seenE = false;
        bool seenNum = false;
        bool seenDot = false;
        // 去除首尾空格
        int len = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(0, s.size() - len);

        len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(len);


        if(s.size() == 0) return false;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >='0' && s[i] <= '9')
            {
                seenNum = true;
            }
            else if(s[i] == '.')
            {
                if(seenDot || seenE)
                    return false;
                seenDot = true;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(!seenNum || seenE)
                    return false;
                seenE = true;
                seenNum = false;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if(i != 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }
            else
                return false;
        }
        return seenNum;
    }
};

int main()
{
    Solution s;
    cout << s.isNumber("46.e3");
    return 0;
}