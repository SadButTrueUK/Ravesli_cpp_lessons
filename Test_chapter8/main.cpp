#include <iostream>
#include <cmath>

class Point
{
    private:
        double m_a{0.0};
        double m_b{0.0};
    public:
        Point() {}
        Point(double a, double b) : m_a(a), m_b(b) {}
        void print()
        {
            std::cout << "Point(" << m_a << ", " << m_b << ")\n";
        }
        friend double distanceTo(const Point& first, const Point& second);

};

double distanceTo(const Point& first, const Point& second)
{
    return sqrt((first.m_a - second.m_a) * (first.m_a - second.m_a) 
            + (first.m_b - second.m_b) * (first.m_b - second.m_b));
}

int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceTo(first, second) << '\n';
    return 0;
}