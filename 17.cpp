#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 17. 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

class Solution {
public:
    void recursion(unordered_map<char,string>& mp,int n,string& str,vector<string>& res,string& tmp)
    {
        if(n == str.size())
        {
            res.push_back(tmp);
        }
        
        if(mp.find(str[n]) != mp.end())
        {
            string s = mp[str[n]];
            for(int i=0;i<s.size();i++)
           {
                tmp.push_back(s[i]);
                recursion(mp,n + 1,str,res,tmp);
                tmp.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> res;
        string tmp;
        recursion(mp,0,digits,res,tmp);
        return res;
    }
};

int main()
{
    Solution s;
    s.letterCombinations("234");
    return 0;
}