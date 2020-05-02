#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) 
    {
        string hash[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> allwords(1,"");
        for(auto word : allwords)
        {
            vector<string> tmp;
            for(auto n : num)
            {
                for(auto c : hash[n - '0'])
                {
                    word += c;
                    tmp.push_back(word);
                }
                    
            }
            allwords = tmp;
        }
        return allwords;
    }
};

int main()
{
    // char str1[] = "abc";
    // char str2[] = "abc";
    // const char str3[] = "abc";
    // const char str4[] = "abc";
    // char *str5 = "abc";
    // char *str6 = "abc";
    // const char *str7 = "abc";
    // const char *str8 = "abc";
    // cout<<(str1==str2)<<endl;
    // cout<<(str3==str4)<<endl;
    // cout<<(str5==str6)<<endl;
    // cout<<(str7==str8)<<endl;


    // https://blog.csdn.net/qq_39521554/article/details/88364471

    // int &i = 1; 非法，引用是从一个变量处取得变量的地址，然后赋值给引用变量
    // int &&i = 1; //合法 
    // cout << i << endl;

    // map<int, int> mp;


    // mp[1] = 1;
    // mp[2] = 2;
    // mp[3] = 3;
    // mp[4] = 4;


    // map<int, int>::iterator it = mp.begin();
    // mp.erase(++it);
    // cout << it->first << " "<< it->second<<endl;
    // // for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    // // {
    // //     cout << it->first << " "<< it->second<<endl;
    // // }
    Solution s;
    vector<string> v = {"tree", "used"};
    s.getValidT9Words("8733", v);

    return 0;
}