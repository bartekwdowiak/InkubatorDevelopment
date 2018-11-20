#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int remainingSpecies(int patchCount, std::string givenSpecies)
{
	//input stream class to operate on strings
    std::istringstream speciesStream(givenSpecies);


	//vector that contains tulip species
    std::vector<int> speciesVec;
    int singleSpecies, result, allSpecies=15000;


	//loop using operator>>, pushes species into a vector
    while(speciesStream >> singleSpecies)
    {
        speciesVec.push_back(singleSpecies);
    }


	//checking if input is valid
	if (speciesVec.size() != patchCount)
	{
		std::cout<<"WRONG INPUT DATA"<<std::endl;
		return 0;
	}

	//sorting vector containing species
    std::sort(speciesVec.begin(), speciesVec.end());


	//extracting uniqe characters from vector, last is a pointer to last unique character
    auto last = std::unique(speciesVec.begin(),speciesVec.end());


	//subtracting distance between begining of a vector to last unique character from all species
    result = allSpecies - std::distance(speciesVec.begin(), last);


    return result;
}

void test_cases()
{
	int answer = remainingSpecies(8, "3 6 2 2 4 6 3 7");
	assert(answer == 14995);

	answer = remainingSpecies(12, "1 2 3 4 5 6 7 8 9 10 11 12");
	assert(answer == 14988);

	answer = remainingSpecies(10, "1 1 1 1 1 1 6 9 6 9");
	assert(answer == 14997);

	answer = remainingSpecies(2, "1 2");
	assert(answer == 14998);

	answer = remainingSpecies(7, "1 2 4 5 5 5 4");
	assert(answer == 14996);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}