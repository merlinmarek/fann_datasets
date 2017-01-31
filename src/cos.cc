#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        std::cout << "Usage: cos <number of samples> <lower limit> <upper limit>" << std::endl;
        return -1;
    }
    int num_samples = std::stoi(std::string(argv[1]));
    float lower_limit = std::stof(std::string(argv[2]));
    float upper_limit = std::stof(std::string(argv[3]));
    float range = upper_limit - lower_limit;
    
    if(lower_limit > upper_limit)
    {
        std::cout << "lower limit has to be greater than upper limit" << std::endl;
        return -1;
    }

    std::ofstream file("cos.data");
    file << num_samples << " 1 1" << std::endl;

    for(int i = 0; i < num_samples; ++i)
    {
        float input = ((float)(rand())) / ((float)RAND_MAX) * range + lower_limit;
        float output = std::cos(input);
        file << input << std::endl << output << std::endl;
    }
    return 0; 
}
