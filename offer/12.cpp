#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 面试题12. 矩阵中的路径
// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
// 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
// [["a","b","c","e"],
// ["s","f","c","s"],
// ["a","d","e","e"]]

// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, int i, int j, string str, int len)
    {
        if (str.length() == len)
            return true;
        if (board[i][j] != str[len])
            return false;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        char tmp = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++)
        {
            int newX = i + dx[i];
            int newY = j + dy[i];
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[newX].size())
            {
                if (dfs(board, newX, newY, str, len + 1))
                    return true;
            }
        }
        board[i][j] = tmp;
        return false;
    }
};

int main()
{
    Solution s;

    return 0;
}