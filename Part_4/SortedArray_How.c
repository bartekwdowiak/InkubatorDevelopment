#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function that checks if given array is descending
bool isDescending (const int *input, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (input[i] < input[i+1])
        {
            return false;
        }
    }

    return true;
}

//function that checks if given array is ascending
bool isAscending (const int *input, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (input[i] > input[i+1])
        {
            return false;
        }
    }

    return true;
}

char* isArraySorted(const int* inputArray, int arraySize)
{

    if (isDescending(inputArray, arraySize))
    {
        return "yes, descending";
    }

    else if (isAscending(inputArray, arraySize))
    {
        return "yes, ascending";
    }

    else
    {
        return "no";
    }

}

void test_cases()
{
    int input[] = {1, 23, 4, 4342, 42342, 1231, 41};
    char *answer = isArraySorted(input, 7);
    assert(strcmp(answer,"no") == 0);

    int input2[] = {1, 23, 23, 4342};
    answer = isArraySorted(input2, 4);
    assert(strcmp(answer,"yes, ascending") == 0);

    int input3[] = {1, 2, 3, 4, 5, 6, 7, 8, 1};
    answer = isArraySorted(input3, 9);
    assert(strcmp(answer,"no") == 0);

    int input4[] = {10, 8, 2, 0, -20};
    answer = isArraySorted(input4, 5);
    assert(strcmp(answer,"yes, descending") == 0);

    int input5[] = {1000000, 1000001, 1000002, 1000003};
    answer = isArraySorted(input5, 4);
    assert(strcmp(answer,"yes, ascending") == 0);

    int input6[] = {10, 9, 7, 8, 7};
    answer = isArraySorted(input6, 5);
    assert(strcmp(answer,"no") == 0);

}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}