#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题55 - I. 二叉树的深度
// 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return l > r ? l : r + 1;
    }
};
int main()
{
    Solution s;

    return 0;
}