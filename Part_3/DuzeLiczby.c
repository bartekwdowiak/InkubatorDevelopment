#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function that checks if two given numbers are equal
bool isEqual(const char* first, const char* second)
{
    //comparing two strings
    if (strcmp(first, second) == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

//function that checks if the first given number is greater than second
bool isGreater(const char* first, const char* second)
{
    //if one of the strings is longer it means it is greater
    if (strlen(first) > strlen(second))
    {
        return true;
    }

    else if (strlen(first) < strlen(second))
    {
        return false;
    }

    //if their lengths are the same, compares them digit by digit
    else
    {
        for (int i = 0; i < strlen(first); i++)
        {
            if (first[i] > second[i])
            {
                return true;
            }

            else if (first[i] < second[i])
            {
                return false;
            }
        }
    }
    return false;
}

const char* bigNumbersComparison(char* input)
{
    char *firstValue = NULL, *secondValue = NULL, *comparisonSymbol = NULL;


    //extracting both values and symbol knowing they're separated with spaces
    firstValue = strtok(input, " ,.-");
    comparisonSymbol = strtok(NULL, " ,.-");  
    secondValue = strtok(NULL, " ,.-");


    //if else block instead of switch case because of char* variable being the choosing factor
    if (strcmp(comparisonSymbol, "==") == 0)
    {
        if (isEqual(firstValue, secondValue))
        {
            return tak;
        }
       
        else
        {
            return nie;
        }
    }

    else if (strcmp(comparisonSymbol, "!=") == 0)
    {
        if (isEqual(firstValue, secondValue))
        {
            return "NIE";
        }
       
        else
        {
            return "TAK";
        }        
    }

    else if (strcmp(comparisonSymbol, "<") == 0)
    {
        if (isGreater(firstValue, secondValue))
        {
            return "NIE";
        }
       
        else
        {
            return "TAK";
        }       
    }

    else if (strcmp(comparisonSymbol, ">") == 0)
    {
        if (isGreater(firstValue, secondValue))
        {
            return "TAK";
        }
       
        else
        {
            return "NIE";
        }       
    }

    else if (strcmp(comparisonSymbol, "<=") == 0)
    {
        if (isGreater(firstValue, secondValue))
        {
            return "NIE";
        }
       
        else
        {
            return "TAK";
        }
    }    

    else if (strcmp(comparisonSymbol, ">=") == 0)
    {
        if (isGreater(firstValue, secondValue) || isEqual(firstValue, secondValue))
        {
            return "TAK";
        }
       
        else
        {
            return "NIE";
        }       
    }

    else
    {
        printf("WRONG COMPARISON SYMBOL!\n");
        return "";
    }
}


void test_cases()
{
    char input[] = "100 > 11";
    char *answer = bigNumbersComparison(input);
    assert(strcmp(answer,"TAK") == 0);

    char input2[] = "100000000000000000000000000000000000000 < 100000000000000000000000000000000000001";
    answer = bigNumbersComparison(input2);
    assert(strcmp(answer,"TAK") == 0);

    char input3[] = "999 >= 20000";
    answer = bigNumbersComparison(input3);
    assert(strcmp(answer,"NIE") == 0);

    char input4[] = "997 <= 996";
    answer = bigNumbersComparison(input4);
    assert(strcmp(answer,"NIE") == 0);

    char input5[] = "1010101010101010101010101010101010110 == 1010101010101010101010101010101010110";
    answer = bigNumbersComparison(input5);
    assert(strcmp(answer,"TAK") == 0);

    char input6[] = "123456789987456123 != 123456789987456122";
    answer = bigNumbersComparison(input6);
    assert(strcmp(answer,"TAK") == 0);    
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}