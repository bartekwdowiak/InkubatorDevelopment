#include <string.h>
#include <assert.h>


char* highestScoringWord(const char *sentence){

    int lenght = strlen(sentence);
    int highestScore = -1;

}


void test_cases()
{
	char* answer = highestScoringWord("Ala ma kota");
	assert(answer == true);

	answer = highestScoringWord("Dupa zupa kupa");
	assert(answer == false);

	answer = highestScoringWord("Tieto tieto TiEtO");
	assert(answer == true);

	answer = highestScoringWord("asd asdafdfdsfgad gdfa fafas AAAAAAAAAAAAA");
	assert(answer == false);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}