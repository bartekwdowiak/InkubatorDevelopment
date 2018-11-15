#include <assert.h>
#include <string>
#include <algorithm>
/** 
* Function returns true if word_1 and word_2 are anagrams to each other. Otherwise false.
* Case sensitivity doesn't matter.
*/
bool check_if_anagram(const std::string &word_1, const std::string &word_2)
{
	std::string word1=word_1, word2=word_2;										//tworzenie kopii stringow, bo "const"

	word1.erase(remove_if(word1.begin(), word1.end(), isspace), word1.end());	//usuniecie spacji ze stringow
	word2.erase(remove_if(word2.begin(), word2.end(), isspace), word2.end());

	transform(word_1.begin(), word_1.end(), word_1.begin(), ::tolower);
	transform(word_2.begin(), word_2.end(), word_2.begin(), ::tolower);

	std::sort(word1.begin(), word1.end());										//sortowanie strigow
	std::sort(word2.begin(), word2.end());

	return word1==word2 ? true:false;											//porownanie i return
}

void test_cases()
{
	bool answer = check_if_anagram("LordVader", "VaderLord");
	assert(answer == true);

	answer = check_if_anagram("silent", "listen");
	assert(answer == true);

	answer = check_if_anagram("funeral", "real fun");
	assert(answer == true);

	answer = check_if_anagram("Tieto", "Tietonator");
	assert(answer == false);

	answer = check_if_anagram("Football", "Basketball");
	assert(answer == false);

	answer = check_if_anagram("F", "");
	assert(answer == false);
}

int main()
{
	test_cases();
}
