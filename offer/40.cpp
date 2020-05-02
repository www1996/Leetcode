#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 面试题40. 最小的k个数
// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        sort(arr.begin(),arr.end());
        arr.erase(arr.begin() + k,arr.end());
        return arr;
    }
};


int main()
{

    return 0;
}