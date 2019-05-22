#include <iostream>

using std::cout;
using std::cin;
using std::endl;

inline void swap(int &lhs, int &rhs)
{
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main()
{
    int l1_start, l1_end, l2_start, l2_end, tmp;
    cin >> l1_start >> l1_end >> l2_start >> l2_end;

    if (l1_start > l1_end)
    {
        swap(l1_start, l1_end);
    }

    if (l2_start > l2_end)
    {
        swap(l2_start, l2_end);
    }

    if ((l1_end <= l2_start) || (l1_start >= l2_end))
    {
        cout << 0 << endl;
        return 0;
    }

    cout << ((l1_end - l1_start) + (l2_end - l2_start) - 
            (std::max(l1_end, l2_end) - std::min(l1_start, l2_start))) << endl;

    return 0;
}
