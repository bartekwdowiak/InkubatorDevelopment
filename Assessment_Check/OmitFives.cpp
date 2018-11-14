#include <assert.h>
#include <iostream>

/**
* Function takes a 'start' and 'end' number of a range, and should return the count of all numbers except numbers with 5 in it.
* For example: start = 4, end = 8. It should return 4, because: 4, 6, 7, 8
*/
int numbers_without_five(int start, int end)
{
    int temp, count=0;
    bool isFive=false;
    for(int i=start; i<=end; i++){
        temp=i;
        while(temp!=0 && !isFive){
            if(temp%5==0 && temp%10!=0) isFive=true;
            temp/=10;
        }
        if(!isFive) {
            count++;
        }
        isFive=false;
    }
    
	return count;
}

void test_cases()
{
	int answer = numbers_without_five(4, 8);
	assert(answer == 4);

	answer = numbers_without_five(1, 9);
	assert(answer == 8);

	answer = numbers_without_five(4, 17);
	assert(answer == 12);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}