#include <iostream>
//#include <vector>
//#include <numeric>

class Average
{
    private:
        //std::vector<int> m_data{};
        //int m_average = 0;
        int m_sum = 0;
        int m_count = 0;
    
    public:
        Average& operator+=(int value);   
        friend std::ostream& operator<<(std::ostream &out, const Average &avg);
};

Average& Average::operator+=(int value)
{
    // this->m_data.push_back(value);
    // this->m_average = std::accumulate(this->m_data.begin(), this->m_data.end(), 0) / this->m_data.size();
    m_sum += value;
    m_count++;
    return *this;
}   

std::ostream& operator<< (std::ostream &out, const Average &avg)
{
    //out << avg.m_average;   
    out << static_cast<double>(avg.m_sum / avg.m_count);
    return out;
}


int main()
{
	Average avg;
	
	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5
	
	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7
 
	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11
 
	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6
 
	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}