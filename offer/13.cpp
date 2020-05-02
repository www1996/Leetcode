#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
// 它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

class Solution {
public:
    int path[101][101] = {0};
    int movingCount(int m, int n, int k) 
    {
        int ans = 0;
        dfs(m,n,0,0,k,ans);
        return ans;
    }
    bool judge(int m, int n,int x, int y,int k)
    {
        if(x >= m || y >= n)    return false;
        int sum = 0;
        while(x)
        {
            sum += x%10;
            x /= 10;
        }
        while(y)
        {
            sum += y % 10;
            y /= 10;
        }
        if(sum <= k) return true;
        return false;  
    }
    void dfs(int &m, int &n,int x, int y,int k,int &ans)
    {
        if(!judge(m,n,x,y,k))   return;
        if(path[x][y]) return;
        ans++;
        path[x][y] =1;
        dfs(m,n,x -1,y,k,ans);
        dfs(m,n,x + 1,y,k,ans);
        dfs(m,n,x,y - 1,k,ans);
        dfs(m,n,x,y + 1,k,ans);
    }
};

int main()
{
    Solution s;

    return 0;
}