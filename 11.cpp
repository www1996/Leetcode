#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -1;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int tmp;
                if(height[i] <= height[j])
                {
                    tmp = height[i] * (j - i);
                }
                else{
                    tmp = height[j] * (j - i);
                }
                if(tmp > ans)
                    ans = tmp;
            }
        }
        return ans;
    }
};


int main()
{
    return 0;
}