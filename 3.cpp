#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// 3. 无重复字符的最长子串
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int start(0), ans(0);
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end() && start <= m[s[i]])// abba 更新左边界要满足哈希表找到了s[i]并且m[s[i]]要比左边界大
            {
                start = m[s[i]] + 1;
            }
            m[s[i]] = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
int main()
{
    Solution s;

    return 0;
}