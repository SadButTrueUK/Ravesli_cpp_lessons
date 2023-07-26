#include <iostream>
#include <cassert>

class Fraction
{
    private:
        int m_nom{0}, m_denom{1};
        int m_array[10] {11,22,33,44,55,66,77,88,99,111};
        int nod(int a, int b) const;
        void reduce();
    public:
        Fraction(int nom = 0, int denom = 1) : m_nom(nom), m_denom(denom) 
        {
          assert(denom != 0);
          reduce();  
        } 
        //Copy constructor (if it is private then object copy can't be created)
        Fraction(const Fraction &f) : m_nom(f.m_nom), m_denom(f.m_denom)
        {
          std::cout << "Copy constructor worked here!\n"; 
        }
        void print() const
        {
            std::cout << m_nom << "/" << m_denom << "\n";
        }
        Fraction operator-() const;     //unary minus (for example get negative value)
        Fraction& operator++();         // ++i
        Fraction& operator--();         // --i
        Fraction operator++(int);       // i++
        Fraction operator--(int);       // i--
        Fraction& operator= (const Fraction &f);
        Fraction& operator+= (const Fraction &f);
        Fraction& operator+= (int);
        Fraction& operator-= (const Fraction &f);
        Fraction& operator-= (int);
        int& operator[](const int index);
        const int& operator[](const int index) const;

        friend Fraction operator*(const Fraction& v1, const Fraction& v2);
        friend Fraction operator*(const Fraction& v, int val);
        friend Fraction operator*(int val, const Fraction& v);
        friend std::ostream& operator<<(std::ostream &out, const Fraction& fraction);
        friend std::istream& operator>>(std::istream &in, Fraction& fraction);
        friend bool operator==(const Fraction& v1, const Fraction& v2);
        friend bool operator!=(const Fraction& v1, const Fraction& v2);
        friend bool operator>=(const Fraction& v1, const Fraction& v2);
        friend bool operator>(const Fraction& v1, const Fraction& v2);
        friend bool operator<=(const Fraction& v1, const Fraction& v2);
        friend bool operator<(const Fraction& v1, const Fraction& v2);
}; 

Fraction& Fraction::operator+= (const Fraction &f)
{

}

Fraction& Fraction::operator+= (int val)
{

}

Fraction& Fraction::operator-= (const Fraction &f)
{
    
}

Fraction& Fraction::operator-= (int val)
{

}

Fraction& Fraction::operator= (const Fraction &f)
{
    //Check for "selfassignment"
    if (this == &f)
        return *this;
 
    //Copy values
    m_nom = f.m_nom;
    m_denom = f.m_denom;
 
    //return current object
    return *this;
}

Fraction& Fraction::operator++()
{
    ++m_nom;
    ++m_denom;
    reduce();
    
    return *this;
}
 
Fraction& Fraction::operator--()
{
    --m_nom;
    --m_denom;
    reduce();
    
    return *this;
}
 
Fraction Fraction::operator++(int)
{
    // Создаем временный объект класса Number с текущим значением переменной m_number
    Fraction temp(m_nom, m_denom);
 
    // Используем оператор инкремента версии префикс для реализации перегрузки оператора инкремента версии постфикс
    ++(*this); // реализация перегрузки
 
    // Возвращаем временный объект
    return temp;
}
 
Fraction Fraction::operator--(int)
{
    // Создаем временный объект класса Number с текущим значением переменной m_number
    Fraction temp(m_nom, m_denom);
 
    // Используем оператор декремента версии префикс для реализации перегрузки оператора декремента версии постфикс
    --(*this); // реализация перегрузки
 
    // Возвращаем временный объект
    return temp; 
}

bool operator==(const Fraction& v1, const Fraction& v2)
{
    return v2.m_nom == v2.m_nom && v1.m_denom == v2.m_denom;
}

bool operator!=(const Fraction& v1, const Fraction& v2)
{
    return !(v1 == v2);
}

bool operator>=(const Fraction& v1, const Fraction& v2)
{
    double v1_dbl = static_cast<double>(v1.m_nom) / v1.m_denom;
    double v2_dbl = static_cast<double>(v2.m_nom) / v2.m_denom;
    return v1_dbl >= v2_dbl;
}

bool operator>(const Fraction& v1, const Fraction& v2)
{
    double v1_dbl = static_cast<double>(v1.m_nom) / v1.m_denom;
    double v2_dbl = static_cast<double>(v2.m_nom) / v2.m_denom;
    return v1_dbl > v2_dbl;
}

bool operator<=(const Fraction& v1, const Fraction& v2)
{
    double v1_dbl = static_cast<double>(v1.m_nom) / v1.m_denom;
    double v2_dbl = static_cast<double>(v2.m_nom) / v2.m_denom;
    return v1_dbl <= v2_dbl;
}

bool operator<(const Fraction& v1, const Fraction& v2)
{
    double v1_dbl = static_cast<double>(v1.m_nom) / v1.m_denom;
    double v2_dbl = static_cast<double>(v2.m_nom) / v2.m_denom;
    return v1_dbl < v2_dbl;
}

Fraction Fraction::operator-() const
{
    return Fraction(-m_nom, m_denom);
}

int Fraction::nod(int a, int b) const
{
    return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);    
}

void Fraction::reduce() 
{
    const int divider = nod(m_nom, m_denom);
    m_nom /= divider;
    m_denom /= divider;
}

Fraction operator*(const Fraction& v1, const Fraction& v2)
{
    return Fraction(v1.m_nom * v2.m_nom, v1.m_denom * v2.m_denom);
} 

Fraction operator*(const Fraction& v, int val)
{
    return Fraction(v.m_nom * val, v.m_denom );
}

Fraction operator*(int val, const Fraction& v)
{
    return Fraction(v.m_nom * val, v.m_denom);
}

std::ostream& operator<<(std::ostream &out, const Fraction& fraction)
{
    out << fraction.m_nom << "/" << fraction.m_denom;
    return out;
}

std::istream& operator>>(std::istream &in, Fraction& fraction)
{
    char c;
    in >> fraction.m_nom;
    in >> c;
    in >> fraction.m_denom;
    fraction.reduce();

    return in;
}

int& Fraction::operator[](const int index)
{
    return m_array[index];
}
const int& Fraction::operator[](const int index) const
{
    return m_array[index];
}


int main()
{
    Fraction f1(5, 8);
    f1.print();
 
    Fraction f2(2, 4);
    f2.print();
    
    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 3;
    f4.print();
 
    Fraction f5 = 4 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    Fraction f7;
	std::cout << "Enter fraction 1: ";
	std::cin >> f7;
 
	Fraction f8;
	std::cout << "Enter fraction 2: ";
	std::cin >> f8;
    std::cout << f7 << " * " << f8 << " is " << f7 * f8 << '\n';
	std::cout << "Is f1 > f2 equal to " << (f1 > f2) << '\n';
    std::cout << "Is f1 >= f2 equal to " << (f1 >= f2) << '\n';
    std::cout << "Is f1 < f2 equal to " << (f1 < f2) << '\n';
    std::cout << "Is f1 <= f2 equal to " << (f1 <= f2) << '\n';
    std::cout << "Is f1 == f2 equal to " << (f1 == f2) << '\n';
    std::cout << "Is f1 != f2 equal to " << (f1 != f2) << '\n';
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "++f1 = " << ++f1 << '\n';
    std::cout << "f1++ = " << f1++ << '\n';
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "--f1 = " << --f1 << '\n';
    std::cout << "f1-- = " << f1-- << '\n';
    std::cout << "f1 = " << f1 << '\n';

    Fraction f9;
    std::cout << "f9[4] before changing = " << f9[4] << '\n';
    f9[4] = 7777;
    std::cout << "f9[4] after changing = " << f9[4] << '\n';  
    Fraction f10(f9); //copy constructor executes here
    Fraction f11;
    f11 = f10;
}