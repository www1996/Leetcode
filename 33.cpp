#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

    // 33. 搜索旋转排序数组
    // 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

    // ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

    // 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

    // 你可以假设数组中不存在重复的元素。

    // 你的算法时间复杂度必须是 O(log n) 级别。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    s.search(v = {7, 8, 0, 1, 2, 3, 4, 5, 6}, 0);
    return 0;
}