#include <string>
#include <iostream>

class Fruit
{
    private:
        std::string m_name;
        std::string m_color;
    public:
        Fruit(std::string name, std::string color) : m_name(name), m_color(color)
        {
            std::cout << "Fruit()" << '\n';
        }
    std::string getName() const 
    {
        return m_name;
    }
    std::string getColor() const 
    {
        return m_color;
    }
};

class Apple : public Fruit
{
    protected:
        Apple(std::string name, std::string color) 
            : Fruit(name, color)
        {
            std::cout << "Apple() protected" << '\n';
        }
    public:
        Apple(std::string color="red")
		: Fruit("apple", color)
	    {
            std::cout << "Apple() public" << '\n';
        }  
   
};

class Banana : public Fruit
{
    public:
        Banana() : Fruit("banana", "yellow")
        {
            std::cout << "Banana()" << '\n';
        }
};

class GrannySmith : public Apple
{
    public:
        GrannySmith() 
            : Apple("Granny Smith apple", "green")
        {
            std::cout << "Granny Smith apple()" << '\n';
        }
        
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
 
	return 0;
}