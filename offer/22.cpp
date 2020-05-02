#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题22. 链表中倒数第k个节点
// 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
// 例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        auto fast = head;
        auto slow = head;
        while(--k)
        {
            fast = fast->next;
        }
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    Solution s;

    return 0;
}