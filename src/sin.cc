#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Usage: sin <number of samples>" << std::endl;
        return -1;
    }
    int num_samples = std::stoi(std::string(argv[1]));

    std::ofstream file("sin.data");
    file << argv[1] << " 1 1" << std::endl;

    for(int i = 0; i < num_samples; ++i)
    {
        float input = ((float)(rand())) / ((float)RAND_MAX) * 2.0f * M_PI - M_PI;
        float output = std::sin(input);
        file << input << std::endl << output << std::endl;
    }
    return 0; 
}
