#include <iostream>
// 프로그래머스 2023 KAKAO BLIND RECRUITMENT : 개인정보 수집 유효기간
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

constexpr int NUM_MONTHS_IN_YEAR = 12;
constexpr int NUM_DAYS_IN_MONTH = 28;
constexpr int DATE_STRING_LENGTH = 10;

int ConvertDateStringToInt(const string& date)
{
    if (date.size() != DATE_STRING_LENGTH) return 0;

    const int year  = stoi(date.substr(0, 4));
    const int month = stoi(date.substr(5, 2));
    const int day   = stoi(date.substr(8, 2));

    return ((year - 1) * (NUM_MONTHS_IN_YEAR * NUM_DAYS_IN_MONTH)) + ((month - 1) * NUM_DAYS_IN_MONTH) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    const int todayInDays = ConvertDateStringToInt(today);

    unordered_map<char, int> termPeriods;
    for (const string& term : terms)
    {
        const char termType = term[0];
        const int  period   = stoi(term.substr(2));
        
        termPeriods[termType] = period;
    }
        
    for (int i = 0; i < (int)privacies.size(); i++)
    {
        const string date   = privacies[i].substr(0, DATE_STRING_LENGTH);
        const char termType = privacies[i].back();

        const int expiryInDays = ConvertDateStringToInt(date) + (termPeriods[termType] * NUM_DAYS_IN_MONTH) - 1;
        if (expiryInDays < todayInDays)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main(void)
{
    //string today = "2022.05.19";
    //vector<string> terms = {"A 6", "B 12", "C 3"};
    //vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};

    string today = "2020.01.01";
    vector<string> terms = {"Z 3", "D 5"};
    vector<string> privacies = {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"};

    vector<int> result = solution(today, terms, privacies);
    for (int res :result)
        cout << res << endl;

    return 0;
}
