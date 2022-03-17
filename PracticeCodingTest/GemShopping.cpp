#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv3 [카카오 인턴] 보석 쇼핑

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

bool CompareGems(vector<pair<string, int>>& a, vector<pair<string, int>>& b)
{
    if ( a.size() > b.size() ) return true;
    if ( a.size() < b.size() ) return false;
  
    return (a.back().second - a.front().second) < (b.back().second - b.front().second);
}

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    vector<vector<pair<string, int>>> gemInfos;
    set<string> gemSet;

    for ( int index = 0; index < gems.size(); ++index )
    {
        string gemName = gems[index];
        gemSet.insert(gemName);

        for ( vector<pair<string, int>>& gemInfo : gemInfos )
        {
            if ( find_if(gemInfo.begin(), gemInfo.end(), 
                [gemName](pair<string, int>& elem)
                { return elem.first == gemName; }
                ) == gemInfo.end())
            {
                gemInfo.push_back(make_pair(gemName, index));
            }
        }

        vector<pair<string, int>> curGemInfo;
        curGemInfo.push_back(make_pair(gemName, index));
        gemInfos.push_back(curGemInfo);
    }

    sort(gemInfos.begin(), gemInfos.end(), CompareGems);

    answer.emplace_back(gemInfos.front().front().second + 1);
    answer.emplace_back(gemInfos.front().back().second + 1);
    return answer;
}

int main()
{
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> result = solution(gems);
    for ( int res : result )
    cout << res << endl;

    return 0;
}