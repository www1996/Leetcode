#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 19. 删除链表的倒数第N个节点
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：

// 给定一个链表: 1->2->3->4->5, 和 n = 2.

// 当删除了倒数第二个节点后，链表变为 1->2->3->5.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;
        while(n--)
        {
            p2 = p2->next;
        }
        if(p2 == nullptr)
        {
            return head->next;
        }
        while(p2->next != nullptr)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p2;
        free(p2);

        return head;
    }
};

int main()
{
    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    // ListNode *n3 = new ListNode(3);
    // ListNode *n4 = new ListNode(4);
    // ListNode *n5 = new ListNode(5);

    n1->val = 1;
    n1->next = n2;

    n2->val = 2;
    n2->next = nullptr;

    // n3->val = 3;
    // n3->next = n4;

    // n4->val = 4;
    // n4->next = n5;

    // n5->val = 5;
    // n5->next = nullptr;
    s.removeNthFromEnd(n1,1);
    return 0;
}