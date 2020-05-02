#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 面试题29. 顺时针打印矩阵
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        if (matrix.size() == 0)
            return res;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while (top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            if (bottom < top || left > right)
                break;
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (bottom < top || left > right)
                break;

            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (bottom < top || left > right)
                break;

            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.spiralOrder(matrix);
    return 0;
}