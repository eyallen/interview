#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct Point
{
    int x;
    int y;
    int distance;

    Point(int a, int b)
        : x(a), y(b)
    {
        distance = (a*a) + (b*b);
    }
};

template<class T>
class bounded_queue
{
public:
    bounded_queue<T>(int size, function<bool(T a, T b)> compare)
    {
        m_size = size;
        m_compare = compare;
        m_queue = priority_queue<T, std::vector<T>, function<bool(T,T)>>(compare);
    }

    void push(T obj)
    {
        if (m_queue.size() < m_size)
        {
            m_queue.push(obj);
        }
        else if (m_compare(obj, m_queue.top()))
        {
            m_queue.pop();
            m_queue.push(obj);
        }
    }

    vector<T> toVector()
    {
        vector<T> v = {};
        while(!m_queue.empty())
        {
            v.push_back(m_queue.top());
            m_queue.pop();
        }

        return v;
    }

private:
    int m_size;
    function<bool(T a, T b)> m_compare;
    priority_queue<T, std::vector<T>, function<bool(T,T)>> m_queue;
};

vector<Point> getClosestPoint(vector<Point> points, int size)
{
    function<bool(Point a, Point b)> comp = [](Point a, Point b) { return a.distance < b.distance; };
    bounded_queue<Point> q = bounded_queue<Point>(size, comp);

    for (const auto& point : points)
    {
        q.push(point);
    }

    return q.toVector();
}

int main()
{
    Point a = Point(0,1);
    Point b = Point(1,1);
    Point c = Point(10,0);
    Point d = Point(1,0);

    vector<Point> points = {a,b,c,d};
    vector<Point> closest = getClosestPoint(points, 1);

    for (const auto& p : closest)
    {
        cout << "(" << p.x << "," << p.y << ") ";
    }

    cout << endl;

    closest = getClosestPoint(points, 3);

    for (const auto& p : closest)
    {
        cout << "(" << p.x << "," << p.y << ") ";
    }
}

