#include <string.h>
#include <assert.h>
#include <stdbool.h>

/**
* Function checks if a string has the same amount of 'x' and 'o's. Function must be case insensitive.
*/
bool XO(const char *word, const int length)
{
	int countX = 0, countO = 0;
	for(int i=0; i<length; i++){
		if(word[i]==88 || word[i]==120) countX++;			//jezeli x lub X inkrementuj licznik X'ow
		else if(word[i]==79 || word[i]==111) countO++;		//jak wyzej z "O"
	}
	return countX==countO ? true : false;
}

void test_cases()
{
	bool answer = XO("ooxx", strlen("ooxx"));
	assert(answer == true);

	answer = XO("xooxx", strlen("xooxx"));
	assert(answer == false);

	answer = XO("ooxXm", strlen("ooxXm"));
	assert(answer == true);

	answer = XO("zzoo", strlen("zzoo"));
	assert(answer == false);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}