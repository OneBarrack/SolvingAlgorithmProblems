#include <iostream>
// 프로그래머스 2023 KAKAO TECH INTERNSHIP : 성격 유형 검사하기
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

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    constexpr int dontKnowAnswerPos = 4;
    constexpr pair<char, char> personalityTypes[4] = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};

    unordered_map<char, int> scores;
    for (int i = 0; i < (int)survey.size(); i++)
    {
        int score = choices[i] - dontKnowAnswerPos;
        if (score == 0) 
            continue;

        const char personalityType = (score < 0) ? survey[i][0] : survey[i][1];
        scores[personalityType] += abs(score);
    }

    for (auto [firstType, secondType] : personalityTypes)
    {
        const char resultType = (scores[firstType] < scores[secondType]) ? secondType : firstType;
        answer.push_back(resultType);
    }

    return answer;
}

int main(void)
{
    //vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"};
    //vector<int> choices = {5, 3, 2, 7, 5};

    vector<string> survey = {"TR", "RT", "TR"};
    vector<int> choices = {7, 1, 3};

    cout << solution(survey, choices) << endl;

    return 0;
}
