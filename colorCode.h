#include "colorCodeData.h"
#include<iostream>
#include <assert.h>
#include<string>
using namespace std;
string manualToString()
{    string manual = "-------------------------------------------------\n|Pair no.\t|Major color\t|Minor color\t|\n-------------------------------------------------\n";
    int pairNumber = 1;
    for (int i = 1; i <= numberOfMajorColors; i++)
    {
        for (int j = 1; j <= numberOfMinorColors; j++)
        {
            manual += "|" + to_string(pairNumber) + "\t\t|" + MajorColorNames[i - 1] + "\t\t|" + MinorColorNames[j - 1] + "\t\t|\n";
            pairNumber++;
        }
        manual = manual + "-------------------------------------------------\n";
    }
    return manual;
}
ColorPair GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor =
        (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor =
        (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
}
int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}
void testNumberToPair(int pairNumber,MajorColor expectedMajor,MinorColor expectedMinor)
{
    ColorPair colorPair =
        GetColorFromPairNumber(pairNumber);
    cout << "Got pair " << colorPair.ToString() << endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}
void testPairToNumber(MajorColor major,MinorColor minor,int expectedPairNumber)
{
    int pairNumber = GetPairNumberFromColor(major, minor);
    cout << "Got pair number " << pairNumber << endl;
    assert(pairNumber == expectedPairNumber);
}
