#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>
 
class FixedPoint
{
private:
	std::int16_t m_base; // это целая часть значения
	std::int8_t m_decimal; // это дробная часть значения
    
public:
	FixedPoint(std::int16_t base = 0, std::int8_t decimal = 0)
		: m_base(base), m_decimal(decimal)
	{
		assert(decimal <= 99 && decimal >= -99 && "Decimal must be in range -99...99");
 
		// Если целая или дробная части отрицательные
		if (m_base < 0.0 || m_decimal < 0.0)
		{
			// Проверяем целую часть
			if (m_base > 0.0)
				m_base = -m_base;
			// Проверяем дробную часть
			if (m_decimal > 0.0)
				m_decimal = -m_decimal;
		}
	}
    FixedPoint(double d)
    {
        m_base = static_cast<int16_t>(d);
        m_decimal = static_cast<int8_t>(round((d - m_base)*100));
    }

	operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100;
	}
    
    FixedPoint operator-()
	{
		return FixedPoint(-m_base, -m_decimal);
	}

    friend bool operator==(const FixedPoint &fp1, const FixedPoint &fp2)
	{
		return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
	}
 
	friend std::istream& operator >> (std::istream &in, FixedPoint &fp)
	{
		double d;
		in >> d;
		fp = FixedPoint(d);
 
		return in;
	}
 
	friend FixedPoint operator+(const FixedPoint &fp1, const FixedPoint &fp2)
	{
		return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
	}
 
	friend std::ostream& operator<<(std::ostream &out, const FixedPoint &fp)
	{
		out << static_cast<double>(fp);
		return out;
	}
};
 
int main()
{
	FixedPoint a(37, 58);
	std::cout << a << '\n';
 
	FixedPoint b(-3, 9);
	std::cout << b << '\n';
 
	FixedPoint c(4, -7);
	std::cout << c << '\n';
 
	FixedPoint d(-5, -7);
	std::cout << d << '\n';
 
	FixedPoint e(0, -3);
	std::cout << e << '\n';
 
	std::cout << static_cast<double>(e) << '\n';
 
    FixedPoint f(0.03);
	std::cout << f << '\n';
 
	FixedPoint g(-0.03);
	std::cout << g << '\n';
 
	FixedPoint h(4.01); 
	std::cout << h << '\n';
 
	FixedPoint i(-4.01); 
	std::cout << i << '\n';
    std::cout << -i << '\n';
    
    std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; 
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n';
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; 
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; 
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; 
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; 
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n';
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n';
   
    std::cout << "Enter a number: "; //50.6785
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	
    return 0;
}