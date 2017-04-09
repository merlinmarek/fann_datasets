#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <math_eval.h>

int main(int argc, char** argv)
{
    if(argc != 5)
    {
        std::cout << "Usage: generator \"<mathematical expression>\" <number of samples> <lower limit> <upper limit>" << std::endl;
        return -1;
    }
    std::string math_expr = std::string(argv[1]);
    int num_samples = std::stoi(std::string(argv[2]));
    float lower_limit = std::stof(std::string(argv[3]));
    float upper_limit = std::stof(std::string(argv[4]));
    float range = upper_limit - lower_limit;
    
    if(lower_limit > upper_limit)
    {
        std::cout << "lower limit has to be greater than upper limit" << std::endl;
        return -1;
    }

    std::ofstream file("fann.data");
    file << num_samples << " 1 1" << std::endl;

    for(int i = 0; i < num_samples; ++i)
    {
        float input = ((float)(rand())) / ((float)RAND_MAX) * range + lower_limit;
        std::string input_string = std::to_string(input);
        std::string eval_string = math_expr;
        size_t start_pos = 0;
        while((start_pos = eval_string.find("x", start_pos)) != std::string::npos)
        {
            eval_string.replace(start_pos, 1, "(" + input_string + ")");
            start_pos += input_string.length() + 2;
        }
        float output = math_eval(infix_to_postfix(eval_string));
        //std::cout << eval_string << "\t->\t" << output << std::endl;
        file << input << std::endl << output << std::endl;
    }
    return 0; 
}
