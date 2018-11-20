#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char* firstAndLast(char* firstVerse, char* pricesInput)
{
    int arrayPos = -1, firstOccur = -1, lastOccur = -1, resultSize = 1, tempOccur;
    char *priceTemp, *daysCount, *givenPrice;
    

    //extracting single characters from first input
    daysCount = strtok(firstVerse, " ,.-");
    givenPrice = strtok(NULL, " ,.-");
    

    //array containg price for every day
    char *pricesArray[atoi(daysCount)];


    //extracting variables from second input into an array
    priceTemp = strtok(pricesInput, " ,.-");

    while (priceTemp != NULL)
    {
        pricesArray[++arrayPos] = priceTemp;
        priceTemp = strtok(NULL, " ,.-");
    }
  

    //going through the prices array from the beginning to find first occurance of given price
    for (int i = 0; i < atoi(daysCount); i++)
    {
        //comparing variable from array with given price
        if (strcmp(pricesArray[i], givenPrice) == 0)
        {
            //if found it saves incremented "i" variable as first occurance (i=0)
            firstOccur = ++i;
            
            //loop to check how many digits there are in firstOccur
            while (i != 0)
            {
                i /= 10;
                resultSize++;
            }

            break;
        }
    }

    //going through the prices array from the end to find last occurance of given price
    for (int i = atoi(daysCount) - 1; i >= 0; i--)
    {
        //comparing variable from array with given price
        if (strcmp(pricesArray[i], givenPrice) == 0)
        {
            //if found it saves incremented "i" variable as last occurance (i=0)
            lastOccur = ++i;

            //loop to check how many digits there are in lastOccur
            while (i != 0)
            {
                i /= 10;
                resultSize++;
            }

            break;
        }
    }


    //allocating memory for result using resultSize variable which was determined in previous loops
    char *result = malloc(sizeof *result * resultSize);

    //saving first and last occurance variables into result
    sprintf(result, "%d %d", firstOccur, lastOccur);

    return result;
}
    
void test_cases()
{
    char input1[] = "7 3", input2[] = "1 3 5 2 3 4 3";
    char *answer = firstAndLast(input1, input2);
    assert(strcmp(answer,"2 7") == 0);

    char input3[] = "4 2", input4[] = "2 3 4 5";
    answer = firstAndLast(input3, input4);
    assert(strcmp(answer,"1 1") == 0);

    char input5[] = "3 2", input6[] = "5 3 1";
    answer = firstAndLast(input5, input6);
    assert(strcmp(answer,"-1 -1") == 0);

    char input7[] = "1 3", input8[] = "2";
    answer = firstAndLast(input7, input8);
    assert(strcmp(answer,"-1 -1") == 0);

    char input9[] = "1 3", input10[] = "3";
    answer = firstAndLast(input9, input10);
    assert(strcmp(answer,"1 1") == 0);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}