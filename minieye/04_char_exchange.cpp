#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/* 
 * Description: 返回一个字母串或下划线串
 * str: 输入字符串
 * pos: 从输入字符串的pos开始扫描
 * is_alpha: true: 当前获取的是字母串；false: 当前获取的是下划线串
 * */
string get_token(const string &str, string::size_type &pos, bool &is_alpha)
{
    string::size_type start = pos, end;

    if (pos == str.size())
    {
        return string();
    }
    else if (str[pos] == '_')
    {
        is_alpha = false;
        if ((end = str.find_first_not_of('_', pos)) == string::npos)
        {
            end = str.size();
        }

        pos = end;
        return str.substr(start, end - start);
    }
    else
    {
        is_alpha = true;
        if ((end = str.find_first_of('_', pos)) == string::npos)
        {
            end = str.size();
        }

        pos = end;
        return str.substr(start, end - start);
    }
}

void print(const string &str)
{
    bool is_alpha = false;
    string prev, cur, next, null_str;
    string::size_type pos = 0;

    while ((cur = get_token(str, pos, is_alpha)) != null_str)
    {
        if (is_alpha)  // 如果是字母串，直接输出
        {
            cout << cur;
            prev = cur;
        }
        else  // 如果是下划线串，根据其前后的字母串是否相等进行输出
        {
            next = get_token(str, pos, is_alpha);
            cout << ((prev == next) ? string(cur.size(), '+') : cur) << next;
            prev = next;
        }
    }

    cout << endl;
}

int main()
{
    string str;
    cin >> str;
    print(str);

    return 0;
}
