#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题55 - II. 平衡二叉树
// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if(abs(left - right) > 1) ans = false;
        return max(left, right) + 1;
    }
};

int main()
{
    Solution s;

    return 0;
}