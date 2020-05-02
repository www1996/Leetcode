#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题34. 二叉树中和为某一值的路径
// 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {        
        vector<vector<int>> ans;
        if(!root)   return  ans;
        vector<int> path;
        dfs(root,sum,path,ans);
        return ans;
    }
    void dfs(TreeNode* root, int sum,vector<int> &path,vector<vector<int>> &ans)
    {
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            int tmpSum = 0;
            for(int i = 0; i < path.size(); i++)
            {
                tmpSum += path[i];
            }
            if(tmpSum == sum)   ans.push_back(path);
            return;
        }
        if(root->left)  
        {
        dfs(root->left,sum,path,ans);
        path.pop_back();
        }
        if(root->right){
        dfs(root->right,sum,path,ans);
        path.pop_back();
        }

    }
};

int main()
{

    return 0;
}