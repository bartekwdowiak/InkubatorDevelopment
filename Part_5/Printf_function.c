#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *mr_asprintf(char *format, ...)
{
    const int buffer = 100;
    int resPos = 0, argumentInt, digitCount = 0;    
    char *result = NULL, *intToChar = NULL, *input = NULL, *argumentChar = NULL;

    result = (char*)malloc(sizeof(char*) * (buffer));
    memset(result, '\0', buffer);

    va_list argumentList;
    va_start(argumentList, format);
    

    for (input = format; *input != '\0'; input++)
    {
        while (*input != '{' && *input != '\0')
        {
            result[resPos] = *input;
            resPos++;
            input++;
        }
        
        if (*input == '\0')
        {
            break;
        }

        input++;

        switch (*input)
        {
            case 's':
                argumentChar = va_arg(argumentList, char *);
                for (int i=0; i < strlen(argumentChar); i++)
                {
                    result[resPos] = argumentChar[i];
                    resPos++;
                    result[resPos] = '\0';
                }
                input++;
                break;
            
            case 'i':                
                argumentInt = va_arg(argumentList, int);
                intToChar = (char*)malloc(sizeof(char*) * (buffer));
                memset(intToChar, '\0', buffer);
                sprintf(intToChar, "%d", argumentInt);
                for (int i=0; i < strlen(intToChar); i++)
                {
                    result[resPos] = intToChar[i];
                    resPos++;
                    result[resPos] = '\0';
                }
                input++;
                
                free(intToChar);
                
                break;

            case '{':
                result[resPos] = '{';
                break;            
        }
    }
    
    result[resPos] = '\0';
    va_end(argumentList);
    printf("%s\n", result);
    return result;
}

void test_cases()
{
    char *result = mr_asprintf("Gaius Julius Caesar Augustus Germanicus");
    assert(strcmp(result, "Gaius Julius Caesar Augustus Germanicus") == 0);
    free(result);

    result = mr_asprintf("Nickname: {s}", "Caligula");
    assert(strcmp(result, "Nickname: Caligula") == 0);
    free(result);

    result = mr_asprintf("Reign: {i} AD - {i} AD", 37, 41);
    assert(strcmp(result, "Reign: 37 AD - 41 AD") == 0);
    free(result);

    result = mr_asprintf("born: {s} {i}, {i} in {s}", "August", 31, 12, "Antium");
    assert(strcmp(result, "born: August 31, 12 in Antium") == 0);
    free(result);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}