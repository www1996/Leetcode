#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题19. 正则表达式匹配
// 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
// 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        if ('*' == p[1])
        {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        }
        else
        {
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};

int main()
{
    string s = "abcde";
    cout << s.substr(2) << endl;
    return 0;
}