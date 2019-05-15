#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

/*
 * Description: 判断"helloworld"是否是输入字符串的不连续子串
 */
bool is_uncontinuous_substr(const string &str)
{
    string hi("helloworld");
    map<char, vector<int>> alpha_map;  // key为字母，value为字母在str出现的所有位置
    int prev = -1; // helloworld中上一个字母出现的位置
    for (int pos = 0; pos < str.size(); ++pos)
    {
        alpha_map[str[pos]].push_back(pos);
    }

    for (int pos = 0; pos < hi.size(); ++pos)
    {
        if (alpha_map.find(hi[pos]) == alpha_map.end())
        {
            return false;
        }

        auto iter = lower_bound(alpha_map[hi[pos]].begin(), alpha_map[hi[pos]].end(), prev);
        if (iter == alpha_map[hi[pos]].end())
        {
            return false;
        }
        prev = *iter + 1;
    }

    return true;
}

int main()
{
    string str;
    // 示例中的字符串有空格，为保险起见使用getline代替>>
    getline(cin, str);
    cout << std::boolalpha 
         << is_uncontinuous_substr(str) 
         << std::noboolalpha << endl;
    return 0;
}
