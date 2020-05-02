#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
// 面试题26. 树的子结构
// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if(A==nullptr || B==nullptr)
            return false;
        queue<TreeNode *> q;
        q.push(A);
        while(!q.empty())
        {
            TreeNode *nowNode = q.front();
            q.pop();
            if(nowNode->val == B->val)
            {
                if(fun(nowNode,B))
                {
                    return true;
                }
            }
            if(nowNode->left != nullptr)
            {
                q.push(nowNode->left);
            }
            if(nowNode->right != nullptr)
            {
                q.push(nowNode->right);
            }
        }
        return false;
    }
    bool fun(TreeNode* &A, TreeNode* &B)
    {
        if(B == nullptr)    return true;
        if(B != nullptr && A ==nullptr) return false;
        if(A->val != B->val)    return false;
        
        bool left = fun(A->left,B->left);
        bool right = fun(A->right,B->right);

        return left && right;
    }


};

class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        bool ans = false;
        if(A != nullptr && B != nullptr)
        {
            if(A->val == B->val)
            {
                ans = fun(A,B);
            }
            if(!ans)    ans = isSubStructure(A->left,B);
            if(!ans)    ans = isSubStructure(A->right,B);
        }
        return ans;
    }
    bool fun(TreeNode* &A, TreeNode* &B)
    {
        if(B == nullptr)    return true;
        if(B != nullptr && A ==nullptr) return false;
        if(A->val != B->val)    return false;

        bool left = fun(A->left,B->left);
        bool right = fun(A->right,B->right);

        return left && right;

    }
};

int main()
{
    Solution s;

    return 0;
}