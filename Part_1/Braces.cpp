#include <assert.h>
#include <iostream>
#include <string>

bool bracesOrder(const std::string &input)
{
    std::cout<<input.length()<<std::endl;
    for ( int i = 0; i < input.length(); i++ ){
        
    }
    return true;
}

void test_cases()
{
    bool answer = bracesOrder("(){}[]");
	assert(answer == true);

	answer = bracesOrder("([{}])[]");
	assert(answer == true);

	answer = bracesOrder("(]");
	assert(answer == false);

    answer = bracesOrder("[(])");
	assert(answer == false);

    answer = bracesOrder("[({})](]");
	assert(answer == false);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}