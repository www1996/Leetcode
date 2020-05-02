#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题32 - III. 从上到下打印二叉树 III
// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
        int flag = -1;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *head = q.front();
                q.pop();
                if(head->left)
                {
                    q.push(head->left);
                    tmp.push_back(head->val);
                }
                if(head->right)
                {
                    q.push(head->right);
                    tmp.push_back(head->val);
                }
            }
            if(flag == -1)
            {
                if(!tmp.empty())
                {
                    reverse(tmp.begin(), tmp.end());
                    ans.push_back(tmp);
                }
                flag *= -1;
            }
            else
            {
                if(!tmp.empty())
                {
                    ans.push_back(tmp);
                }
                flag *= -1;
            }

        }
        
        return ans;
    }
};

int main()
{

    return 0;
}