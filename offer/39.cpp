#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 面试题39. 数组中出现次数超过一半的数字
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]] += 1;
        }
        for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if(it->second > n)
                return it->first;
        }
        return -1;
    }
};


int main()
{

    return 0;
}