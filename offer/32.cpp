#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题37. 序列化二叉树
// 请实现两个函数，分别用来序列化和反序列化二叉树。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string ans = "";
        dfs_0(root, ans);
        cout << ans;
        return ans;
    }
    void dfs_0(TreeNode *root, string &ans)
    {
        if (!root)
        {
            ans += "null ";
            return;
        }
        ans += to_string(root->val) + " ";
        dfs_0(root->left, ans);
        dfs_0(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (!data.length())
            return NULL;
        int len = 0;
        return dfs(data, len);
    }
    TreeNode *dfs(string &data, int &len)
    {
        if (len == data.size())
            return NULL;
        int val = 0;
        int k = len;
        bool flag = true;
        if (data[len] != 'n')
        {
            if (data[len] == '-')
            {
                k++;
                flag = false;
            }
            while (data[k] != ' ')
            {
                val = val * 10 + data[k] - '0';
                k++;
            }
            len = k + 1;
        }
        else
        {
            len += 5;
            return NULL;
        }
        TreeNode *root = new TreeNode(flag ? val : -val);
        root->left = dfs(data, len);
        root->right = dfs(data, len);
        return root;
    }
};

int main()
{
    string s = "abcde";
    cout << s.substr(2) << endl;
    return 0;
}