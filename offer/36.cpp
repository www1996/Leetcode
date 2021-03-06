#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题36. 二叉搜索树与双向链表
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;
        Node *head = nullptr, *pre = nullptr;
        helper(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node *root, Node *&head, Node *&pre)
    {
        if (!root)
            return;
        helper(root->left, head, pre);
        if (!head)
        {
            head = root; // 找到head
            pre = root;  // 对pre进行初始化
        }
        else
        {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        helper(root->right, head, pre);
    }
};

int main()
{

    return 0;
}