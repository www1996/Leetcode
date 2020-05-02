#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 面试题30. 包含min函数的栈
// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> s_data;//存放数据
	stack<int> s_min;//存放每一次压入后，栈内的最小值
	MinStack() {	
	}
	void push(int x) {
		s_data.push(x);
		if (s_min.size() == 0) s_min.push(x);
		else
		{
			if (x < s_min.top()) s_min.push(x);
			else s_min.push(s_min.top());
		}
	}
	void pop() {
		if (s_data.size() == 0) return;
		s_data.pop();
		s_min.pop();
	}
	int top() {
		return s_data.top();
	}
	int min() {
		return s_min.top();
	}
};
int main()
{

    return 0;
}