#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
// 面试题27. 二叉树的镜像
// 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)   return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            TreeNode * tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);            
        }
        return root;
    }
    
};
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
int main()
{
    Solution s;

    return 0;
}