#include <assert.h>
#include <iostream>
#include <string>
#include <map>

std::string convertToRomanNumeral(int decimalNumber)
{
    if (decimalNumber > 3999)
    {
        std::cout << "INPUT NUMBER CAN'T BE GREATER THAN 3999!" << std::endl;
        return "";
    }

    std::string romanNumber = "";
    int numberMultiplier;

    std::map<int, std::string> romanMap = {
        { 1, "I" },
        { 4, "IV" },
        { 5, "V" },
        { 9, "IX" },
        { 10, "X" },
        { 40, "XL" },
        { 50, "L" },
        { 90, "XC" },
        { 100, "C" },
        { 400, "CD" },
        { 500, "D" },
        { 900, "CM" },
        { 1000, "M" } };


    for (auto current = romanMap.rbegin(); current != romanMap.rend(); current++)
    {
        numberMultiplier = decimalNumber / current->first;

        for (int i = 0; i < numberMultiplier; i++)
        {
            romanNumber += current->second;
        }

        decimalNumber -= numberMultiplier * current->first;

        if (decimalNumber == 0) 
        {
            break;
        }

    }

    return romanNumber;
}

void test_cases()
{
    std::string test = convertToRomanNumeral(1000);
    std::cout << test << std::endl;
    assert(test == "M");
 
    test = convertToRomanNumeral(1990);
    std::cout << test << std::endl;
    assert(test == "MCMXC");
 
    test = convertToRomanNumeral(2008);
    std::cout << test << std::endl;
    assert(test == "MMVIII");
 
    test = convertToRomanNumeral(1666);
    std::cout << test << std::endl;
    assert(test == "MDCLXVI");
 
    test = convertToRomanNumeral(1);
    std::cout << test << std::endl;
    assert(test == "I");
 
    test = convertToRomanNumeral(0);
    std::cout << test << std::endl;
    assert(test == "");

    test = convertToRomanNumeral(1231230);
    std::cout << test << std::endl;
    assert(test == "");
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}