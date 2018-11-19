#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int remainingSpecies(int patchCount, std::string givenSpecies)
{
    std::istringstream speciesStream(givenSpecies);
    std::vector<int> speciesVec;
    int singleSpecies, result, allSpecies=15000;

    while(speciesStream >> singleSpecies)
    {
        speciesVec.push_back(singleSpecies);
    }

    std::sort(speciesVec.begin(), speciesVec.end());
    auto last = std::unique(speciesVec.begin(),speciesVec.end());

    result = allSpecies - std::distance(speciesVec.begin(), last);

    return result;
}

void test_cases()
{
	int answer = remainingSpecies(8,"3 6 2 2 4 6 3 7");
	assert(answer == 14995);

	answer = remainingSpecies(12, "1 2 3 4 5 6 7 8 9 10 11 12");
	assert(answer == 14988);

	answer = remainingSpecies(10, "1 1 1 1 1 1 6 9 6 9");
	assert(answer == 14997);

	answer = remainingSpecies(2, "1 2");
	assert(answer == 14998);

	answer = remainingSpecies(7,"1 2 4 5 5 5 4");
	assert(answer == 14996);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}