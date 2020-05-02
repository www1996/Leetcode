#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 面试题52. 两个链表的第一个公共节点
// 输入两个链表，找出它们的第一个公共节点。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        ListNode *countA = headA;
        ListNode *countB = headB;
        int lA = 0;
        int lB = 0;
        while (countA)
        {
            ++lA;
            countA = countA->next;
        }
        while (countB)
        {
            ++lB;
            countB = countB->next;
        }
        int i = max(lA, lB) - min(lA, lB);
        if (lA > lB)
            for (i; i > 0; --i)
                headA = headA->next;
        else
            for (i; i > 0; --i)
                headB = headB->next;
        while (headA)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main()
{

    return 0;
}