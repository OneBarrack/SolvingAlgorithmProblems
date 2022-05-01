#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2. 순위 검색

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

enum class InfoType
{
    Language,
    JobGroup,
    Career,
    SoulFood,
    Score,
};

int GetMatchedApplicantsCount(unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>>& infoList, string language, string jobGroup, string career, string soulFood, int score, InfoType infoType)
{
    int count = 0;

    switch ( infoType )
    {
        case InfoType::Language:
        {
            auto& curList = infoList;
            if ( language == "-" )
            {
                for ( auto iter = curList.begin(); iter != curList.end(); ++iter )
                {
                    count += GetMatchedApplicantsCount(infoList, iter->first, jobGroup, career, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
                }
            }
            else
            {
                count += GetMatchedApplicantsCount(infoList, language, jobGroup, career, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
            }
        }
        break;
        case InfoType::JobGroup:
        {
            auto& curList = infoList[language];
            if ( jobGroup == "-" )
            {
                for ( auto iter = curList.begin(); iter != curList.end(); ++iter )
                {
                    count += GetMatchedApplicantsCount(infoList, language, iter->first, career, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
                }
            }
            else
            {
                count += GetMatchedApplicantsCount(infoList, language, jobGroup, career, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
            }
        }
        break;
        case InfoType::Career:
        {
            auto& curList = infoList[language][jobGroup];
            if ( career == "-" )
            {
                for ( auto iter = curList.begin(); iter != curList.end(); ++iter )
                {
                    count += GetMatchedApplicantsCount(infoList, language, jobGroup, iter->first, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
                }
            }
            else
            {
                count += GetMatchedApplicantsCount(infoList, language, jobGroup, career, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
            }
        }
        break;
        case InfoType::SoulFood:
        {
            auto& curList = infoList[language][jobGroup][career];
            if ( soulFood == "-" )
            {
                for ( auto iter = curList.begin(); iter != curList.end(); ++iter )
                {
                    count += GetMatchedApplicantsCount(infoList, language, jobGroup, career, iter->first, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
                }
            }
            else
            {
                count += GetMatchedApplicantsCount(infoList, language, jobGroup, career, soulFood, score, static_cast<InfoType>(static_cast<int>(infoType) + 1));
            }
        }
        break;
        case InfoType::Score:
        {
            auto& scores = infoList[language][jobGroup][career][soulFood];
            count += scores.end() - lower_bound(scores.begin(), scores.end(), score);
        }
        break;
    }

    return count;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>> infoList;

    for ( string& strInfo : info )
    {
        stringstream ss(strInfo);
        string language;
        string jobGroup;
        string career;
        string soulFood;
        string score;

        getline(ss, language, ' ');
        getline(ss, jobGroup, ' ');
        getline(ss, career, ' ');
        getline(ss, soulFood, ' ');
        getline(ss, score, ' ');

        infoList[language][jobGroup][career][soulFood].push_back(stoi(score));
    }

    for ( auto languageIter = infoList.begin(); languageIter != infoList.end(); ++languageIter )
        for ( auto jobGroupIter = languageIter->second.begin(); jobGroupIter != languageIter->second.end(); ++jobGroupIter )
            for ( auto careerIter = jobGroupIter->second.begin(); careerIter != jobGroupIter->second.end(); ++careerIter )
                for ( auto soulFoodIter = careerIter->second.begin(); soulFoodIter != careerIter->second.end(); ++soulFoodIter )
                    sort(soulFoodIter->second.begin(), soulFoodIter->second.end());

    for ( string& strQuery : query )
    {
        stringstream ss(strQuery);
        string language;
        string jobGroup;
        string career;
        string soulFood;
        string score;

        string tempStr;
        getline(ss, language, ' '); getline(ss, tempStr, ' ');
        getline(ss, jobGroup, ' '); getline(ss, tempStr, ' ');
        getline(ss, career, ' ');   getline(ss, tempStr, ' ');
        getline(ss, soulFood, ' ');
        getline(ss, score, ' ');

        answer.push_back(GetMatchedApplicantsCount(infoList, language, jobGroup, career, soulFood, stoi(score), InfoType::Language));
    }

    return answer;
}

int main()
{
    vector<string> info = { 
        "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50" 
    };

    vector<string> query = {
        "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150" 
    };

    vector<int> result = solution(info, query);

    for ( int res : result )
        cout << res << endl;

    return 0;
}