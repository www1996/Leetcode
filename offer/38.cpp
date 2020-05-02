#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 面试题38. 字符串的排列
// 输入一个字符串，打印出该字符串中字符的所有排列。
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
// class Solution
// {
// public:
//     void permutation(string &s, int start, vector<string> &res)
//     {
//         if (start == s.size())
//         {
//             res.push_back(s);
//             return;
//         }
//         vector<bool> swapped(256, false); //记录是否交换过，防止重复
//         for (int i = start; i < s.size(); i++)
//         {
//             if (swapped[s[i]])
//             { //交换过就不用再次交换
//                 continue;
//             }
//             swapped[s[i]] = true;
//             swap(s[start], s[i]);
//             cout << s << endl;
//             permutation(s, start + 1, res);
//             swap(s[start], s[i]);
//         }
//     }
//     vector<string> permutation(string s)
//     {
//         vector<string> res;
//         permutation(s, 0, res);
//         return res;
//     }
// };

class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        vector<string> ans;
        vector<bool> isused(s.size(),false);
        string path = "";
        dfs(s,path,isused,ans);
        return ans;
    }
    void dfs(string &s, string &path,vector<bool> &isused,vector<string> &ans)
    {
        if(s.length() == path.length())
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(isused[i])   continue;
            if(i > 0 && s[i - 1] == s[i] && isused[i -1])   continue;
            isused[i] = true;
            path += s[i];
            dfs(s,path,isused,ans);
            path.pop_back();
            isused[i] = false;
        }
    }
};

int main()
{
    Solution s;
    s.permutation("aab");
    return 0;
}