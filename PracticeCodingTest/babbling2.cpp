#include <iostream>
// 프로그래머스 연습문제 : 옹알이(2)
// 1

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    const unordered_map<char, string> strMap = {{'a', "aya" }, {'y', "ye"}, {'w', "woo"}, {'m', "ma"}};
        
    for (const string& pronounces : babbling)
    {
        size_t pos = 0;
        string prevPronounce = "";
        while (pos < pronounces.length())
        {
            if (strMap.find(pronounces[pos]) == strMap.end() || (pronounces.find(strMap.at(pronounces[pos]), pos) != pos))
                break;

            const string curPronounce = strMap.at(pronounces[pos]);
            if (prevPronounce == curPronounce)
                break;

            prevPronounce = curPronounce;
            pos += curPronounce.length();
        }

        if (pos == pronounces.length())
            answer++;
    }

    return answer;
}

int main(void)
{
    vector<string> babbling = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};

    cout << solution(babbling) << endl;

    return 0;
}
