#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

bool bracesOrder(const std::string &input)
{
	int len = input.length();
	std::vector<char> bracesOpenings;


	for (int i = 0; i < len; i++) {

		if (input[i] == '[' || input[i] == '(' || input[i] == '{') 
		{
			bracesOpenings.push_back(input[i]);
		}

		else if (bracesOpenings.back() == '[' && input[i] == ']' 
			||	 bracesOpenings.back() == '(' && input[i] == ')' 
			||	 bracesOpenings.back() == '{' && input[i] == '}') 
		{
			bracesOpenings.pop_back();
		}

		else 
		{
			return false;
		}

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