#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::min;
using std::max;

struct Point
{
    void swap(Point &other)
    {
        Point tmp = *this;
        *this = other;
        other = tmp;
    }
    int x;
    int y;
};

struct Rect
{
    Rect() {}
    Rect(istream &in);
    int area() const { return (right.x - left.x) * (right.y - left.y); }
    Point left; // 左下角的点
    Point right; // 右上角的点
};

Rect::Rect(istream &in)
{
    in >> left.x >> left.y >> right.x >> right.y;
    // 如果输入的两个点不是左下角和右上角，则进行修正
    if ((left.x > right.x) && (left.y > right.y))
    {
        left.swap(right);
    }
    else if ((left.x > right.x) && (left.y < right.y))
    {
        int tmp = left.x;
        left.x = right.x;
        right.x = tmp;
    }
    else if ((left.x < right.x) && (left.y > right.y))
    {
        int tmp = left.y;
        left.y = right.y;
        right.y = tmp;
    }
}

int main()
{
    Rect first(cin);
    Rect second(cin);
    Rect overlap;

    overlap.left.x = max(first.left.x, second.left.x);
    overlap.right.x = min(first.right.x, second.right.x);

    if (overlap.left.x >= overlap.right.x)
    {
        cout << 0 << endl;
        return 0;
    }

    overlap.left.y = max(first.left.y, second.left.y);
    overlap.right.y = min(first.right.y, second.right.y);

    if (overlap.left.y >= overlap.right.y)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << overlap.area() << endl;
    return 0;
}
