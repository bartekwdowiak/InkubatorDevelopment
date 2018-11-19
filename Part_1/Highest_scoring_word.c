#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


char* highestScoringWord(char *sentence)
{
    int highestScore = -1, currentScore = 0, asciiValue = 96;
	char *result = NULL, *current = NULL;

	current = strtok(sentence, " ,.-");

	while (current != NULL)
	{
		for	(int i = 0; i < strlen(current); i++)
		{
			currentScore += current[i] - asciiValue;		//equation which allows to calculate the scoring of a letter using ascii code
		}

		if (currentScore>highestScore)
		{
			highestScore = currentScore;
			result = current;
		}

		current = strtok(NULL, " ,.-");
		currentScore = 0;
	}

	return result;
}


void test_cases()
{
	char input1[] = "aaaaa d";
	char* answer = highestScoringWord(input1);
	assert(strcmp(answer,"aaaaa")==0);

	char input2[] = "aaaaa e";
	answer = highestScoringWord(input2);
	assert(strcmp(answer,"aaaaa")==0);

	char input3[] = "aaaaa f";
	answer = highestScoringWord(input3);
	assert(strcmp(answer,"f")==0);

	char input4[] = "dupa zupa kupa";
	answer = highestScoringWord(input4);
	assert(strcmp(answer,"zupa")==0);

	char input5[] = "tieto teito itteo";
	answer = highestScoringWord(input5);
	assert(strcmp(answer,"tieto")==0);

	char input6[] = "zozole ida droga";
	answer = highestScoringWord(input6);
	assert(strcmp(answer,"zozole")==0);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}