#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题18. 删除链表的节点
// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head->val == val)
            return head->next;
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != NULL)
        {
            if (q->val == val)
            {
                p->next = q->next;
            }
            p = p->next;
            q = q->next;
        }

        return head;
    }
};

int main()
{
    Solution s;

    return 0;
}