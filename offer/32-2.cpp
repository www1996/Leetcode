#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题32 - II. 从上到下打印二叉树 II
// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)   return ans;
        vector<int> v={root->val};
        ans.push_back(v);
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;

        while(!q.empty())
        {
            vector<int> vec;
            while(cnt--)
            {
            auto tmp = q.front();
            q.pop();
            
            if(tmp->left)
            {
                vec.push_back(tmp->left->val);
                q.push(tmp->left);
            }   
            if(tmp->right)
            {
                vec.push_back(tmp->right->val);
                q.push(tmp->right);
            }

            } 
            if(!vec.empty())
                ans.push_back(vec); 
            cnt = vec.size();
        }
        return ans;
    }
};

int main()
{

    return 0;
}