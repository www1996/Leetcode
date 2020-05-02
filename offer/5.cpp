#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 面试题05. 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                s.erase(i, 1);
                s.insert(i, "%20");
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    s.replaceSpace(" fd fe a");

    return 0;
}