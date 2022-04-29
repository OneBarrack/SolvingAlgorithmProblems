#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv.Medium - The Time in Words

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

string timeInWords(int h, int m)
{
    string answer = "";

    vector<string> nums = {
        "twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half" };

    if ( m == 0 )
    {
        answer += nums[h % 12] + " o' clock";
    }
    else
    {
        string minuteStr = "";
        string pastToStr = "past ";

        if ( m > 30 )
        {
            h = h + 1;
            m = 60 - m;
            pastToStr = "to ";
        }

        if ( m != 15 && m != 30 )
            minuteStr = (m == 1) ? "minute " : "minutes ";

        answer += nums[m] + " " + minuteStr + pastToStr + nums[h % 12];
    }

    return answer;
}

int main()
{
    int h = 12;
    int m = 45;
    cout << timeInWords(h, m) << endl;

    return 0;
}