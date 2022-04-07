#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 여행경로

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

void DFS(unordered_map<string, unordered_multimap<string, bool>> ticketsFromCity, string curCityName, int ticketCount, set<vector<string>>& resultList, vector<string> result = vector<string>())
{
    result.emplace_back(curCityName);
    if ( ticketCount == 0 )
    {
        resultList.insert(result);
        return;
    }

    for ( auto iter = ticketsFromCity[curCityName].begin(); iter != ticketsFromCity[curCityName].end(); ++iter )
    {
        string targetCityName = iter->first;
        bool& bUsedTicket = iter->second;
        if ( !bUsedTicket )
        {
            bUsedTicket = true;
            DFS(ticketsFromCity, targetCityName, ticketCount - 1, resultList, result);
            bUsedTicket = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    set<vector<string>> resultList;

    unordered_map<string, unordered_multimap<string, bool>> ticketsFromCity;
    for ( vector<string> ticket : tickets )
    {
        ticketsFromCity[ticket[0]].insert(make_pair(ticket[1], false));
    }

    int ticketCount = tickets.size();
    DFS(ticketsFromCity, "ICN", ticketCount, resultList);
    return *resultList.begin();
}

int main()
{
    vector<vector<string>> tickets = { {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} };
    vector<string> result = solution(tickets);

    for ( string res : result )
        cout << res << endl;

    return 0;
}