#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
// 面试题07. 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {        
        if(preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        int k;
        for (int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == preorder[0])
            {
                k = i;
                break;
            }
        }
        vector<int> pre_left, pre_right,in_left,in_right;
        for (int i = 1; i <= k; i++)
        {
            pre_left.push_back(preorder[i]);
            in_left.push_back(inorder[i -1]);
        }
        for (int i = k + 1; i < preorder.size(); i++)
        {
            pre_right.push_back(preorder[i]);
            in_right.push_back(inorder[i]);
        }

        root->left = buildTree(pre_left,in_left);
        root->right = buildTree(pre_right,in_right);

        return root;
    }
};

int main()
{
    Solution s;

    return 0;
}