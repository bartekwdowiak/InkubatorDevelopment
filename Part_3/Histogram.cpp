#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string drawHistogram(std::string input)
{
    std::string result = "", spaces = "", currentLine = "";
    int occurArray[6], maxOccur = 0;


    occurArray[0]=std::count(input.begin(), input.end(), '1');
    occurArray[1]=std::count(input.begin(), input.end(), '2');
    occurArray[2]=std::count(input.begin(), input.end(), '3');
    occurArray[3]=std::count(input.begin(), input.end(), '4');
    occurArray[4]=std::count(input.begin(), input.end(), '5');
    occurArray[5]=std::count(input.begin(), input.end(), '6');

    for (int i = 0; i < 6; i++)
    {
        if (maxOccur < occurArray[i] + 1)
        {
            maxOccur = occurArray[i] + 1;
        }
    }

    for (int lineNumber = maxOccur; lineNumber > 0; lineNumber--)
    {
        for (int diceSide = 0; diceSide < 6; diceSide++)
        {
            if (occurArray[diceSide] + 1 == lineNumber)
            {
                if (occurArray[diceSide]/10 == 0)
                {   
                    spaces += ' ';
                }
                currentLine += spaces;
                if (occurArray[diceSide] == 0)
                {
                    currentLine += ' ';
                }

                else
                {
                    currentLine += std::to_string(occurArray[diceSide]);
                }

                spaces = "";
            }

            else if (occurArray[diceSide] >= lineNumber)
            {
                spaces += ' ';
                currentLine += spaces;
                currentLine += '#';             
                spaces = "";
            }

            else
            {
                spaces += "  ";
            }
        }

        result += currentLine;
        result += '\n';
        currentLine = "";
        spaces = "";
    }


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