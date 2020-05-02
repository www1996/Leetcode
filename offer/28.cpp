#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 面试题28. 对称的二叉树
// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root==NULL)  return true;
//         return func(root->left,root->right);
//     }
//     bool func(TreeNode* p, TreeNode* q)
//     {
//         if(!p && !q)    return true;
//         if(!p || !q)    return false;
//         if(p->val != q->val)    return false;
//         return func(p->left,q->right) && func(q->left,p->right);
//     }
// };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        q2.push(root);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *cur1 = q1.front();
            TreeNode *cur2 = q2.front();
            q1.pop();
            q2.pop();
            if(!cur1 &&! cur2)
                continue;
            if(!cur1 || ! cur2)
                return false;
            if(cur1->val != cur2->val)
                return false;
            q1.push(cur1->left);
            q1.push(cur1->right);
            q2.push(cur2->right);
            q2.push(cur2->left);

        }
        return true;

    }
};

int main()
{
    Solution s;



    return 0;
}