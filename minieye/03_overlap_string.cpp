#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;

void print_overlap(const string &str)
{
    char digits[] = "0123456789";
    string::size_type pos = 0, start, end;  // start和end分别对应数字串的开始位置与结尾的下一个位置
    unsigned long long cnt;  // 数字串对应的数值
    while ((start = str.find_first_of(digits, pos)) != string::npos)
    {
        string cur = str.substr(pos, start - pos);
        end = str.find_first_not_of(digits, start);
        try // 如果数字串对应的数值过大，会抛出异常
        {
            cnt = stoi(str.substr(start, end - start));
        }
        catch (std::out_of_range expt)
        {
            return;
        }
        while (cnt--)
        {
            cout << cur;
        }
        pos = end;
    }
    cout << endl;
}

int main()
{
    string str;
    cin >> str;
    print_overlap(str);
    return 0;
}
