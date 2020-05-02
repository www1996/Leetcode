#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 翻转单链表

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr)
            return nullptr;
        ListNode *pre, *cur;
        pre = head;
        cur = nullptr;
        while (pre != nullptr)
        {
            ListNode *tmp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }
        return cur;
    }
};
int main()
{
    Solution s;
    vector<int> v;

    return 0;
}