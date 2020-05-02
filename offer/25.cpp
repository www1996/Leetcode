#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题25. 合并两个排序的链表
// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        ListNode*p = l1;
        ListNode*q = l2;
        while(p && q)
        {
            if(p->val < q->val)
            {
                head->next = p;
                p = p->next;
            }
            else
            {
                head->next = p;
                q = q->next;
            }
                
            head = head->next;
        }
        if(p)
            head->next = p;
        if(q)
            head->next = q;
        return ans->next;
    }
};

int main()
{
    Solution s;

    return 0;
}