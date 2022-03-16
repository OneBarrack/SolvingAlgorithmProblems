#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 순위 검색

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

using namespace std;

int GetQueryResult(unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>> infoArr, vector<string> queryWordList, int depth)
{
    int count = 0;

    if ( depth > 3 )
    {
        string language = queryWordList[0];
        string jobGroup = queryWordList[1];
        string career = queryWordList[2];
        string soulFood = queryWordList[3];
        int targetScore = stoi(queryWordList[4]);

        vector<int> scoreList = infoArr[language][jobGroup][career][soulFood];
        count += scoreList.size() - (lower_bound(scoreList.begin(), scoreList.end(), targetScore) - scoreList.begin());
    }
    else if ( queryWordList[depth] != "-" )
    {
        count += GetQueryResult(infoArr, queryWordList, depth + 1);
    }
    else
    {
        vector<string> wordList;

        switch ( depth )
        {
            case 0:
            {
                wordList.emplace_back("cpp");
                wordList.emplace_back("java");
                wordList.emplace_back("python");
                break;
            }
            case 1:
            {
                wordList.emplace_back("backend");
                wordList.emplace_back("frontend");
                break;
            }
            case 2:
            {
                wordList.emplace_back("junior");
                wordList.emplace_back("senior");
                break;
            }
            case 3:
            {
                wordList.emplace_back("chicken");
                wordList.emplace_back("pizza");
                break;
            }
        }

        for ( string word : wordList )
        {
            queryWordList[depth] = word;
            count += GetQueryResult(infoArr, queryWordList, depth + 1);
        }
    }

    return count;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer(query.size());
    
    unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>> infoArr;

    for ( string infoStr : info )
    {
        istringstream ss(infoStr);
        string language, jobGroup, career, soulFood, scoreStr;
        int score;

        getline(ss, language, ' ');        
        getline(ss, jobGroup, ' ');
        getline(ss, career, ' ');
        getline(ss, soulFood, ' ');
        getline(ss, scoreStr, ' ');
        score = stoi(scoreStr);

        infoArr[language][jobGroup][career][soulFood].emplace_back(score);
    }

    for ( auto& languageBasedInfos : infoArr )
    {
        for ( auto& jobGroupBasedInfos : languageBasedInfos.second )
        {
            for ( auto& careerBasedInfos : jobGroupBasedInfos.second )
            {
                for ( auto& soulFoodBasedInfos : careerBasedInfos.second )
                {
                    vector<int>& scores = soulFoodBasedInfos.second;
                    sort(scores.begin(), scores.end());
                }
            }
        }
    }

    for ( int i = 0; i < query.size(); ++i )
    {        
        istringstream ss(query[i]);
        vector<string> queryWordList(query.size(), "");
        string tempStr;

        getline(ss, queryWordList[0], ' '); getline(ss, tempStr, ' ');
        getline(ss, queryWordList[1], ' '); getline(ss, tempStr, ' ');
        getline(ss, queryWordList[2], ' '); getline(ss, tempStr, ' ');
        getline(ss, queryWordList[3], ' ');
        getline(ss, queryWordList[4], ' ');
     
        answer[i] = GetQueryResult(infoArr, queryWordList, 0);
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
        /*"java and backend and junior and pizza 100",*/
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