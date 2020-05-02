#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 面试题04. 二维数组中的查找
// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size();
        while(i < matrix.size() && j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
            {
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;


    return 0;
}