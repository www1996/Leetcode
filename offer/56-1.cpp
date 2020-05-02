#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
面试题56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums)
            sum ^= n;   //sum = x ^ y sum是所求两个元素的异或和
        int k = 0;
        // x y 不相等, sum必有一位是1，找到最低位的 1 将元素组划分成第 k 位 为0和为1 的两个集合
        while(!(sum >> k & 1))  k++;
        int first = 0;
        for(auto n : nums)
            if(n >> k & 1)
                first ^= n;
        return vector<int>{first , sum^first};
    }
}; 
int main()
{
    vector<int> v{0,1, 2, 3, 4, 4, 5};
    int sum = 0;
    // for(auto i : v)
    // {
    //     sum ^= i;
    //     cout << sum << endl;
    // }
    int x = 0 ^ 3;
    cout <<  x << endl;
    return 0;
}