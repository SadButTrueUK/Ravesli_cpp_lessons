#include <iostream>
 
class Something
{
private:
    double m_length = 3.5;
    double m_width = 3.5;
 
public:
 
    Something(double length, double width)
        : m_length(length), m_width(width)
    {
        // m_length и m_width инициализируются конструктором (значения по умолчанию, приведенные выше, не используются)
    }
    Something()
    {

    }

    void print()
    {
        std::cout << "length: " << m_length << " and width: " << m_width << '\n';
    }
 
};
 
int main()
{
    Something a(4.5, 5.5);
    a.print();
    Something b;
    b.print();
    return 0;
}