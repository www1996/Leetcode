#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
// 22. 括号生成
// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        dfs(n, 0, 0, "", ans);
        return ans;
    }
    void dfs(int n, int nowl,int nowr,string path, vector<string> &ans)
    {
        if(path.length() == n * 2)
        {
            ans.push_back(path);
            return;
        }
        if(nowl < n)
        {
            dfs(n, nowl + 1, nowr, path + "(", ans);
        }
        if(nowr < nowl)
        {
            dfs(n, nowl, nowr + 1, path + ")", ans);
        }
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);

    return 0;
}