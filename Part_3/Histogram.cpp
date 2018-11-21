#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string drawHistogram(std::string input)
{
    std::string result = "", spaces = "", currentLine = "", dice = "123456";
    int occurArray[6], maxOccur = 0;


    //loop to fill occurances array and check what is the max occurance value
    for (int i = 0; i < 6; i++)
    {
        occurArray[i] = std::count(input.begin(), input.end(), dice[i]);

        if (maxOccur < occurArray[i] + 1)
        {
            maxOccur = occurArray[i] + 1;
        }
    }


    //loops that format the string to be printable as a histogram
    for (int lineNumber = maxOccur; lineNumber > 0; lineNumber--)
    {
        for (int diceSide = 0; diceSide < 6; diceSide++)
        {
            //checks if it is the first character in collumn
            if (occurArray[diceSide] + 1 == lineNumber)
            {
                //checking if number consists of 2 digits
                if (occurArray[diceSide]/10 == 0)
                {   
                    //if it doesn't it adds a space
                    spaces += ' ';
                }

                currentLine += spaces;

                //if there are no occurances don't print '0'
                if (occurArray[diceSide] == 0)
                {
                    currentLine += ' ';
                }

                //if any other value greater than 0, adds it to current line
                else
                {
                    currentLine += std::to_string(occurArray[diceSide]);
                }

                spaces = "";
            }

            //if it isn't the first character in collumn it adds '#'
            else if (occurArray[diceSide] >= lineNumber)
            {
                spaces += ' ';
                currentLine += spaces;
                currentLine += '#';             
                spaces = "";
            }

            //if a number occurs less than "lineNumber" times i adds spaces to variable keeping track of how many of them must be added
            else
            {
                spaces += "  ";
            }
        }

        //adding current line to result and zeroing variables
        result += currentLine;
        result += '\n';
        currentLine = "";
        spaces = "";
    }

    //adding bottom part of histogram and printing it
    result += " - - - - - -\n 1 2 3 4 5 6\n";
    std::cout<<result<<std::endl;

    return result;
}

void test_cases()
{
    std::string answer = drawHistogram("113445665551");
    assert(answer =="         4\n"
                    " 3       #\n"
                    " #     2 # 2\n"
                    " #   1 # # #\n"
                    " #   # # # #\n"
                    " - - - - - -\n"
                    " 1 2 3 4 5 6\n");

    answer = drawHistogram("123456");
    assert(answer ==" 1 1 1 1 1 1\n"
                    " # # # # # #\n"
                    " - - - - - -\n"
                    " 1 2 3 4 5 6\n");

    answer = drawHistogram("122333444455555666666");
    assert(answer =="           6\n"
                    "         5 #\n"
                    "       4 # #\n"
                    "     3 # # #\n"
                    "   2 # # # #\n"
                    " 1 # # # # #\n"
                    " # # # # # #\n"
                    " - - - - - -\n"
                    " 1 2 3 4 5 6\n");

    answer = drawHistogram("12546123165421654216545612415461264126541265412461235641234123412341235412354124621642164213546213542164216421642134213546");
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}