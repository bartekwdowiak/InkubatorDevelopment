#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> dirReduc(const std::vector<std::string> &input)
{
    std::vector<std::string> reducedPath;
    reducedPath.push_back("filling");

    for (std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); it++)
    {
        if (    *it == "NORTH" && reducedPath.back() == "SOUTH"
             || *it == "SOUTH" && reducedPath.back() == "NORTH"
             || *it == "WEST"  && reducedPath.back() == "EAST"
             || *it == "EAST"  && reducedPath.back() == "WEST" )
        {
            reducedPath.pop_back();
        }

        else
        {
            reducedPath.push_back(*it);
        }
    }

    reducedPath.erase(reducedPath.begin());

    return reducedPath;
}


void test_cases()
{
    std::vector<std::string> input = {"NORTH", "WEST", "SOUTH", "EAST"};
    std::vector<std::string> correct = {"NORTH", "WEST", "SOUTH", "EAST"};

    std::vector<std::string> answer = dirReduc(input);
    assert(std::equal(answer.begin(), answer.end(), correct.begin()));

    
    input = {"NORTH", "SOUTH", "EAST", "WEST", "WEST"};
    correct = {"WEST"};

    answer = dirReduc(input);
    assert(std::equal(answer.begin(), answer.end(), correct.begin()));


    input = {"NORTH", "SOUTH", "SOUTH","EAST", "WEST", "NORTH", "WEST"};
    correct = {"WEST"};

    answer = dirReduc(input);
    assert(std::equal(answer.begin(), answer.end(), correct.begin()));


    input = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"};
    correct = {};

    answer = dirReduc(input);
    assert(std::equal(answer.begin(), answer.end(), correct.begin()));
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}