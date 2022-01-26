#include <iostream>
#include <cmath>
using namespace std;
class Point
{
    float x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void getinfo()
    {
        cout << "The point is (" << x << ',' << y << ')' << endl;
    }
    friend float dist(Point, Point);
};
float dist(Point p1, Point p2)
{
    float distance, d1, d2, d3;
    d1 = p2.x - p1.x;
    d2 = p2.y - p1.y;
    d3 = (pow(d1, 2) + pow(d2, 2));
    distance = pow(d3, 0.5);
    return (distance);
}
int main()
{
    Point p(1, 1);
    p.getinfo();
    Point q(4, 3);
    q.getinfo();
    cout << "The distance between these two points is " << dist(p, q);
    return 0;
}