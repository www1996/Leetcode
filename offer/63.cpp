#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
面试题63. 股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty())  return 0;
        int min = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size();i++)
        {
            if(min > prices[i])
            {
                min = prices[i];
            }
            int gap;
            if(min < prices[i])
            {
                gap = prices[i] - min;
            }
            if(gap > ans)   ans = gap;
        }
        return ans;
    }
};


int main()
{
    Solution s;

    return 0;
}