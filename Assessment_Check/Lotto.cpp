#include <array>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>
#include <algorithm>

/** 
* Function returns an array of 5 elements.
* Those 5 elements are created randomly in the range 1 - 49.
* Numbers can't repeat.
*/
std::array<int, 5> Lotto_drawing()
{
    std::array<int, 5> result;
	srand (time(NULL));
    for(int i=0; i<5; i++) result[i]=rand()%49+1;
    return result;
}

/* Please create test cases for this program. test_cases() function can return void, bool or int. */
bool test_cases()
{
    std::array<int,5> answer = Lotto_drawing();
    std::sort(answer.begin(), answer.end());
    for(int i=0; i<5; i++){
        if(answer[i]>=answer[i+1] || answer[i]<1 || answer[i]>49) return false;
    }
    return true;
}


int main()
{
    assert(test_cases() == true);
}
