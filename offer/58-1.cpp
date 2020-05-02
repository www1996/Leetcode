#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题58 - I. 翻转单词顺序
// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
class Solution {
public:
    string reverseWords(string s) 
    {
        string ans;
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            string tmp = "";
            if(s[i] == ' ')
            {
                continue;
            }
            else
            {
                while(s[i] != ' ')
                {
                    tmp += s[i];
                    i++;
                }
                st.push(tmp);
            }
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
            ans += " ";
        }
        return ans.erase(ans.length() - 1);
    }
};

int main()
{
    Solution s;
    s.reverseWords(" ds das fefdwed  a");
    return 0;
}