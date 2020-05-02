#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
面试题56 - II. 数组中数字出现的次数 II
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i 的值大于0即为真
                if(n & 1 << i) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if(cnt % 3 == 1) ans ^= (1 << i);
        }
        return ans;
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
    int x = 4 & -4;
    cout <<  x << endl;
    return 0;
}