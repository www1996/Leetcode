#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
// 面试题06. 从尾到头打印链表
// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ans;
        while(head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;

    return 0;
}