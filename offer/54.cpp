#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 面试题54. 二叉搜索树的第k大节点
// 给定一棵二叉搜索树，请找出其中第k大的节点。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) 
    {
        vector<int> inorder;
        traverse(root,inorder);

        return inorder[inorder.size() - k];
    }
    void traverse(TreeNode* root, vector<int> &inorder)
    {
        if(!root)   return;
        traverse(root->left,inorder);
        inorder.push_back(root->val);
        traverse(root->right,inorder);
    }
};


// class Solution {
// public:
//     int ans;
//     int kthLargest(TreeNode* root, int k) {
//         dfs(root, k);
//         return ans;
//     }
//     void dfs(TreeNode* root, int &k){
//         if (!root) return;
//         dfs(root->right, k);
//         k --;
//         if(!k) ans = root->val;
//         if(k > 0) dfs(root->left, k);
//     }
// };

int main()
{
    Solution s;

    return 0;
}