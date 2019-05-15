#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;

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

// 点与矩形存在三种关系：点在矩形外面、点在矩形边上、点在矩形里面
enum Location
{
    inside,
    onside,
    outside
};

class Rect
{
public:
    Rect(istream &in);
    int area() const;
    int overlap_area(const Rect &other) const;
    bool is_overlap(const Rect &other) const;
    bool is_contain(const Rect &other) const;
    Location where(const Point &pnt) const;

private:
    Point left; // 左下角的点
    Point right; // 右上角的点
};

Rect::Rect(istream &in)
{
    in >> left.x >> left.y >> right.x >> right.y;
    if (left.x < right.x)
    {
        left.swap(right);
    }
}

int Rect::area() const
{
    return ((right.x - left.x) * (right.y - left.y));
}

int Rect::overlap_area(const Rect &other) const
{
    // 不重叠
    if (!is_overlap(other))
    {
        return 0;
    }

    // this包含other
    if (is_contain(other))
    {
        return other.area();
    }
    
    // other包含this
    if (other.is_contain(*this))
    {
        return area();
    }
    return 1;
}

bool Rect::is_overlap(const Rect &other) const
{
    Location first = where(other.left);
    Location second = where(other.right);
    if ((first == onside && second == outside) ||
        (first == outside && second == onside) ||
        (first == outside && second == outside))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Rect::is_contain(const Rect &other) const
{
    return ((where(other.left) != outside) && (where(other.right) != outside));
}

Location Rect::where(const Point &pnt) const 
{
    // 可能会落在边上，这种情况待讨论
    if ((pnt.x > left.x) && (pnt.x < right.x) && (pnt.y > left.y) && (pnt.y < right.y))
    {
        return inside;
    }

    if (((pnt.x == left.x) && (pnt.y >= left.y) && (pnt.y <= right.y)) || // 左边
        ((pnt.x == right.x) && (pnt.y >= left.y) && (pnt.y <= right.y)) || // 右边
        ((pnt.y == right.y) && (pnt.x >= left.x) && (pnt.x <= right.x)) || // 上边
        ((pnt.y == left.y) && (pnt.x >= left.x) && (pnt.x <= right.x))) // 下边
    {
        return onside;
    }

    return outside;
}

int main()
{
    Rect first(cin);
    Rect second(cin);
    cout << first.overlap_area(second) << endl;
    return 0;
}
