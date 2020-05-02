#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 面试题24. 反转链表
// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        auto fast = head->next;
        auto slow = head;
        while(fast !=nullptr)
        {
            auto tmp = fast->next;
            fast->next = slow;
            fast = tmp;
            slow = fast;
        }
        return slow;
    }
};

int main()
{
    Solution s;

    return 0;
}