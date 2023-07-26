#include <string>
#include <iostream>
#include <cassert>

class Substring
{
    private:
        std::string m_str;
    public:
        Substring(std::string s) : m_str(s) 
        {
        }
        std::string operator()(int index, int length);
};

std::string Substring::operator()(int index, int length)
{
    assert((index+length) <= m_str.length());
    return m_str.substr(index, length);
}


int main()
{
    Substring string("Hello, world!");
    std::cout << string(7, 6); // начинаем с 7-го символа (индекса) и возвращаем следующие 6 символов
 
    return 0;
}