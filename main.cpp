#include "testColorCode.h"
#include<string>
using namespace std;
string ToString()
{
                       
    string manual = "-------------------------------------------------\n|Pair no.\t|Major color\t|Minor color\t|\n-------------------------------------------------\n";
    int pairNumber = 1;
    for (int i = 1; i <= numberOfMajorColors; i++)
    {
        
        for (int j = 1; j <= numberOfMinorColors; j++)
        {
            manual = manual + "|"+to_string(pairNumber) + "\t\t|" + MajorColorNames[i - 1] + "\t\t|" + MinorColorNames[j - 1] + "\t\t|\n";
            pairNumber++;
        }
        manual = manual + "-------------------------------------------------\n";
    }
    return manual;
}
int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    string manual = ToString();
    cout << manual;
    return 0;
}
