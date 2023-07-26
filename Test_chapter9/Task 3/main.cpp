#include <iostream>
#include <cassert>

class IntArray
{
    private:
        int* m_data = nullptr;
        int m_length = 0;
    public:
        IntArray(int length = 0) : m_length(length) 
        {
            assert(m_length > 0 && "length must be > 0" );
            m_data = new int[m_length]{0};
            std::cout << "Class constructor" << '\n';
 
        }
        ~IntArray() //destructor
        {
            //Free allocated memory
            std::cout << "Destructor" << '\n';
            delete[] m_data;
        }
        //Copy constructor
        IntArray(const IntArray& src) : m_length(src.m_length)
        {
            m_data = new int[m_length];
            for(int i = 0; i < m_length; ++i)
            {
                m_data[i] = src.m_data[i];
            }
            std::cout << "Copy constructor" << '\n';
        }
        int& operator[](const int index);
        IntArray& operator=(const IntArray& src);
        friend std::ostream& operator<<(std::ostream &out, const IntArray& arr);
};

std::ostream& operator<<(std::ostream &out, const IntArray& arr)
{
    for(int i = 0; i < arr.m_length; ++i)
    {
        out << arr.m_data[i] << ' ';
    }
    return out;
}

IntArray& IntArray::operator= (const IntArray& src)
{
    //Check for "selfassignment"
    if (this == &src)
        return *this;

    delete[] m_data; //if array exists, just delete it to avoid memory leak (it makes resource free)
 
    //Copy values
    m_length = src.m_length;
    
    m_data = new int[m_length];
    for(int i = 0; i < m_length; ++i)
    {
        m_data[i] = src.m_data[i];
    }
    //return current object
    return *this; 
}

int& IntArray::operator[](const int index)
{
    assert(index >= 0 && index < m_length);
	return m_data[index];
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
    a[5] = 8;
 
	return a;
}
 
int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';
 
	IntArray b(1);
	a = a;
	b = a;
 
	std::cout << b << '\n';
    
    IntArray c(b);
    std::cout << c << '\n';
    //IntArray c;  //we get assert here because of m_length =0

	return 0;
}