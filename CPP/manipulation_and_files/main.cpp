#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int get_sum(const std::vector<int> &v);
double get_avg(const std::vector<int> &v);
int get_max(const std::vector<int> &v);
int get_min(const std::vector<int> &v);

int main(void)
{
    std::string file_name = "input.txt";
    std::string out_file_name = "output.txt";
    int val =0;
    std::vector<int> v;
    std::ifstream in(file_name);

    if(!in)
    {
        std::cerr << "Error couldn't open the file\n";
        return 1;
    }

    std::string line;
    while(std::getline(in, line))
    {
        val = std::stoi(line);
        v.push_back(val);        
    }

    in.close();
    // for(int i =0 ; i < v.size(); i++)
    // {
    //     std::cout << v[i];
    // }
    
    int sum = get_sum(v);
    double avg = get_avg(v);
    int max_elem = get_max(v);
    int min_elem = get_min(v);

    std::ofstream out(out_file_name);

    if(!out)
    {
        std::cerr << "Error couldn't open the file\n";
        return 1;
    }



    out << std::setw(48) << std::setfill('-')<< "" << "\n";

    out << "|" << std::setw(6) << std::setfill(' ')<< "Sum" << std::setw(6) << std::setfill(' ') << "|" 
        << std::setw(6) << std::setfill(' ')<< "Avg" << std::setw(6) << std::setfill(' ') << "|"
        << std::setw(6) << std::setfill(' ')<< "Max" << std::setw(6) << std::setfill(' ') << "|"
        << std::setw(6) << std::setfill(' ')<< "Min" << std::setw(6) << std::setfill(' ') << "|\n";

    out << std::setw(48) << std::setfill('-')<< "" << "\n";

    out << "|" << std::setw(6) << std::setfill(' ')<< sum << std::setw(6) << std::setfill(' ') << "|" 
        << std::setw(6) << std::setfill(' ')<< avg << std::setw(6) << std::setfill(' ') << "|"
        << std::setw(6) << std::setfill(' ')<< max_elem << std::setw(6) << std::setfill(' ') << "|"
        << std::setw(6) << std::setfill(' ')<< min_elem << std::setw(6) << std::setfill(' ') << "|\n";
    out << std::setw(48) << std::setfill('-')<< "" << "\n";



    return 0;
}


int get_sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

double get_avg(const std::vector<int> &v)
{
    double avg = (double)get_sum(v) / v.size();
    return avg;
}

int get_max(const std::vector<int> &v)
{
    auto max_elem = std::max_element(v.begin(), v.end());

    return *max_elem; 
}

int get_min(const std::vector<int> &v)
{
    auto min_elem = std::min_element(v.begin(), v.end());
    return *min_elem;
}