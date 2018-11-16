#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <ctype.h>

/**
* Function duplicates letters based on their index. Each index means how many times the letter needs to be duplicated.
* See test cases for examples.
*/

char* accumulate(const char *word, const int length)
{
    char *result = (char*)malloc(((length*length)+(3*length)-2)/2);
    int arrayPos = 0;

    for (int i = 0; i < length; i++) 
	
	{
        for (int j = 0; j < (i + 1); j++) 
		{
			result[arrayPos++] = (j==0 ? toupper(word[i]) : tolower(word[i]));
		}

		result[arrayPos++]='-';

	}

    result[--arrayPos]='\0';
	return result;
}

void test_cases()
{
	char* result = accumulate("abcd", strlen("abcd"));
	assert(strcmp(result, "A-Bb-Ccc-Dddd") == 0);

	result = accumulate("cwAt", strlen("cwAt"));
	assert(strcmp(result, "C-Ww-Aaa-Tttt") == 0);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}