#include <iostream>
#include <vector>

class Point
{
    private:
        int m_x = 0;
        int m_y = 0;
        int m_z = 0;
    
    public:
        Point(int x, int y, int z)
            : m_x(x), m_y(y), m_z(z)
        {
    
        }
    
        friend std::ostream& operator<<(std::ostream &out, const Point &p)
        {
            out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
            return out;
        }
};

class Shape
{
    public:
        friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
        {
            return shape.print(out);
        }
        virtual std::ostream& print(std::ostream& out) const = 0;
        virtual ~Shape() 
        {
        }
};


class Triangle : public Shape
{
    private:
        Point m_p1, m_p2, m_p3;
    public:
        Triangle(const Point& p1, const Point& p2, const Point& p3)
                : m_p1(p1), m_p2(p2), m_p3(p3)
        {
        }
        
        virtual std::ostream& print(std::ostream& out) const override
        {
            out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
            return out;
        }    
};

class Circle : public Shape
{
    private:
        Point m_center;
        int m_radius;
    public:
        Circle(const Point& center, int radius)
              : m_center(center), m_radius(radius)
        {
        }
        
        virtual std::ostream& print(std::ostream& out) const override
        {
            out << "Circle(" << m_center << ", radius " << m_radius << ")";
            return out;
        }    
        int getRadius() const { return m_radius; }
};

int getLargestRadius(const std::vector<Shape*> &v)
{
	int largestRadius {0};
 
	// Перебираем каждый элемент вектора
	for (auto const &element : v)
	{
		// Выполняем проверку на нулевой указатель результата динамического приведения
    	if (Circle *c = dynamic_cast<Circle*>(element))
		{
			if (c->getRadius() > largestRadius)
				largestRadius = c->getRadius();
		}
	}
    return largestRadius;
}

int main()
{
    std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));
 
	for (auto const &element : v)
		std::cout << *element << '\n';
 
	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';
 
	for (auto const &element : v)
		delete element;
 
    return 0;
}