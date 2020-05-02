#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

// 面试题35. 复杂链表的复制
// 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;

        unordered_map<Node *, Node *> rnd;

        Node *fakeHead = new Node(head->val);

        Node *p = head;
        Node *fp = fakeHead;

        while (p != NULL)
        {
            rnd[p] = fp;
            p = p->next;
            if (p == NULL)
                fp->next = NULL;
            else
            {
                Node *next = new Node(p->val);
                fp->next = next;
            }
            fp = fp->next;
        }

        p = head;
        fp = fakeHead;
        while (p != NULL)
        {
            fp->random = rnd[p->random];
            p = p->next;
            fp = fp->next;
        }

        return fakeHead;
    }
};

int main()
{

    return 0;
}