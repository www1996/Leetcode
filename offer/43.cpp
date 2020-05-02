#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

面试题43. 1～n整数中1出现的次数
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

*/
class Solution {
public:
    int countDigitOne(int n) 
    {
        if(!n)  return 0;
        int ans = 0;
        vector<int> num;
        while(n)    
        {
            num.push_back( n % 10);
            n /= 10;
        }
        for(int i  = num.size() -1; i >= 0; i--)
        {
            int left = 0, right = 0, t = 1;
            for(int j = num.size() -1; j > i; j--) left = left * 10 + num[j];
            for(int j = i -1; j >= 0; j-- )
            {
                right = right * 10 + num[j];
                t *= 10;
            }
            ans += left * t;
            if(num[i] == 1) ans += right + 1;
            else if(num[i] > 1) ans += t;
        }
        return ans;
    }

};

int main()
{
    Solution s;

    return 0;
}