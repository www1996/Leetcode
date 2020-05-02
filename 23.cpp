#include <iostream>
#include <string>
#include <algorithm>
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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *tmp = lists[i];
            while(tmp != nullptr)
            {
                v.push_back(tmp->val);
                tmp = tmp->next;
            }
        }
        
        sort(v.begin(), v.end());
        ListNode *head = new ListNode(v[0]);
        ListNode *p = head;
        for (int i = 1; i < v.size(); i++)
        {
            ListNode *tmp = new ListNode(v[i]);
            tmp->next = nullptr;
            p->next = tmp;
            p = p->next;
        }
        return head;
    }
};

int main()
{
    Solution s;

    return 0;
}