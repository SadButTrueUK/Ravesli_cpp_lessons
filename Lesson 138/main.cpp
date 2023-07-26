#include <string>
#include <vector>
#include <iostream>

struct StudentGrade
{
    std::string name;
    char grade;
};

class GradeMap
{
    private:
        std::vector<StudentGrade> m_map;
    public:
        GradeMap()
        {
        }
        char& operator[](const std::string& name); 
};

char& GradeMap::operator[](const std::string& name)
{
  for(auto &el: m_map)
  {
    if(el.name == name)
    {
        return el.grade;
    }
  }
  m_map.push_back({name, ' '});
  return m_map.back().grade;  
}

int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';
 
	return 0;
}