#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 从前序与中序遍历序列构造二叉树

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
            return NULL;
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

        vector<int> pre_left, pre_right, in_left, in_right;
        for (int i = 0; i < k; i++)
        {
            pre_left.push_back(preorder[i + 1]);
            in_left.push_back(inorder[i]);
        }
        for (int i = k + 1; i < preorder.size(); i++)
        {
            pre_right.push_back(preorder[i]);
            in_right.push_back(inorder[i]);
        }
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};
int main()
{
    Solution s;
    vector<int> v;

    return 0;
}