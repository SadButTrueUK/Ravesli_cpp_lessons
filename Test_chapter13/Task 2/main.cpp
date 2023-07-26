#include <iostream>

template <typename T1, typename T2>
class Pair
{
    private:
        T1 m_first; 
        T2 m_second;
    public:
        Pair(T1 first_val, T2 second_val) 
        : m_first(first_val), m_second(second_val)
        {

        }
        T1& first() { return m_first; }
        const T1& first() const { return m_first; }
        T2& second() { return m_second; }
        const T2& second() const { return m_second; }
};


int main()
{
	Pair<int, double> p1(6, 7.8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
 
	const Pair<double, int> p2(3.4, 5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
	return 0;
}