#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
面试题59 - II. 队列的最大值
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

*/
class MaxQueue
{
public:
    queue<int> q;
    deque<int> maxq;
    MaxQueue()
    {
    }

    int max_value()
    {
        if (q.empty() || maxq.empty())
        {
            return -1;
        }
        else
        {
            return maxq.front();
        }
    }

    void push_back(int value)
    {
        q.push(value);
        while (!maxq.empty() && value > maxq.back())
        {
            maxq.pop_back(); //不用保留比value小的数字的原因是
            //比value进来早的数字也比value更先弹出，所以不用担心最大值是被扔掉的数字
        }
        maxq.push_back(value);
    }

    int pop_front()
    {
        if (!q.empty())
        {
            int num = q.front();
            q.pop();
            if (num == maxq.front())
            {
                maxq.pop_front();
            }
            return num;
        }
        return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main()
{

    return 0;
}