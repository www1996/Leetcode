#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
面试题66. 构建乘积数组
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

*/

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ret(n, 1);
        int left = 1;
        for (int i = 0; i < n; i ++) {
            ret[i] = left;
            left = left * a[i];
        } 
        int right = 1;
        for (int i = n-1; i >= 0; i --) {
            ret[i] *= right;
            right *= a[i];
        }
        return ret;
    }
};

int main()
{
    Solution s;

    return 0;
}