#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
面试题68 - I. 二叉搜索树的最近公共祖先
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int rootV = root->val;
        int pV = p->val;
        int qV = q->val;

        if(pV > rootV && qV > rootV)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(pV < rootV && qV < rootV)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else
            return root;

    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//     {
//         TreeNode* pointer = root;
//         while(pointer != NULL)
//         {
//             if(pointer->val < p->val && pointer->val < q->val )
//                 pointer = pointer->right;
//             else if(pointer->val > p->val && pointer->val > q->val )
//                 pointer = pointer->left;
//             else return pointer;
//         }
//         return pointer;
//     }
// };
int main()
{
    Solution s;

    return 0;
}