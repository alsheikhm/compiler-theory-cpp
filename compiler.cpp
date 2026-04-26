// Mohammed Al-Sheikh
// compiler.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

// Compiler function that decodes each line from textfile and returns position of first mismatched closing delimiter
int compiler(const std::string& line)
{
    // Store delimiter values in stack due to LIFO logic
    std::stack<char> s;
    
    for(int i = 0; i < line.length(); ++i)
    {
        // Tests character by character in the string line
        char c = line[i];
        
        // Push opening delimiters to stack
        // When a closing delimiter is found, check if it's matching opening delimiter is at top of stack
        // If so, pop the opening delimter out from the stack. If not, return 1-based column position of mismatch
        if(c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else if(c == ')')
        {
            if(s.empty() || s.top() != '(')
            {
                return (i + 1);
            }
            
            s.pop();
        }
        else if(c == ']')
        {
            if(s.empty() || s.top() != '[')
            {
                return (i + 1);
            }
            
            s.pop();
        }
        else if(c == '}')
        {
            if(s.empty() || s.top() != '{')
            {
                return (i + 1);
            }
            
            s.pop();
        }
    }
    
    return 0;
}

int main()
{
    // Reading from the input file "programs.txt"
    std::ifstream inputFile("programs.txt");
    
    // Checks if file was properly opened, display error message and return 1 if failed
    if(!inputFile.is_open())
    {
        std::cout << "Error Opening Program File 'programs.txt'" << std::endl << std::endl;
        return 1;
    }
    
    std::string line;
    std::vector<int> vPos;
    std::string message;
    
    // Reads each line from the file assigning to line, compiles the line using helper function, and push into vector
    while(std::getline(inputFile, line))
    {
        vPos.push_back(compiler(line));
    }
    
    // Loops through vector and converts integer positions to ASCII characters using modululus by 256
    for(int i = 0; i < vPos.size(); ++i)
    {
        int num = vPos[i] % 256;
        char c = static_cast<char>(num);
        message += c;
    }
    
    std::cout << message << std::endl << std::endl;
    
    inputFile.close();
    
    return 0;
}
