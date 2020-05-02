#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
// 面试题33. 二叉搜索树的后序遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
class Solution
{
public:
    vector<int> seq;
    bool verifyPostorder(vector<int> &postorder)
    {
        seq = postorder;
        return dfs(0, seq.size() - 1);
    }
    bool dfs(int l, int r)
    {
        if (l >= r)
            return true;
        int root = seq[r];
        int k = l;
        while (root > seq[k])
            k++;
        for (int i = k; i < r; i++)
        {
            if (seq[i] < root)
                return false;
        }
        return dfs(l, k - 1) && dfs(k, r - 1);
    }
};

int main()
{
    Solution s;

    return 0;
}