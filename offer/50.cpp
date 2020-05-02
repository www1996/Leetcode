#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 面试题50. 第一个只出现一次的字符
// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
class Solution {
public:
    char firstUniqChar(string s) 
    {
        map<char,int> mp;
        for(auto c : s)
        {
            if(mp.find(c) == mp.end())
            {
                mp[c] = 1;
            }
            else{
                mp[c] += 1;
            }
        }
        for(auto c : s)
        {
            if(mp[c] == 1)
            {
                return c;
            }
        }
        return ' ';
    }
};

int main()
{

    return 0;
}