#include <iostream> // for cout etc
//using namespace stc ==> standard namespace which means you use the object and variable names from the standard library
#include <string> // for string
#include <cctype> //for string length

static std::string capitalizeString(std::string input)
{
    int    letter;
    for (int i = 0; i < input.length(); i++) 
    {
        letter = toupper(input[i]);
        std::cout << char(letter);
    }
    return (input);
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    
    i = 1;
    while (i < argc)
    {
        capitalizeString(argv[i]);
        i++;
    }
    std::cout << std:: endl; //print new line
    return (EXIT_SUCCESS);
}