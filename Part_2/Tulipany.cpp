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
    int singleSpecies, result;

    while(speciesStream >> singleSpecies)
    {
        speciesVec.push_back(singleSpecies);
    }

    std::sort(speciesVec.begin(), speciesVec.end());
    auto last = std::unique(speciesVec.begin(),speciesVec.end())

    result = speciesVec.begin() - last;
    std::cout<<result<<std::endl;
    return result;
}

void test_cases()
{
	int answer = remainingSpecies(8,"3 6 2 2 4 6 3 7");
	assert(answer == 14995);

	/*answer = remainingSpecies("");
	assert(answer == true);

	answer = remainingSpecies("");
	assert(answer == false);

	answer = remainingSpecies("");
	assert(answer == false);

	answer = remainingSpecies("");
	assert(answer == false);*/
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}