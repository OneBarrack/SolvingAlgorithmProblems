#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 디스크 컨트롤러

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

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end());

    int totalProgressTime = 0;
    int diskProgressTime = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for ( vector<int> job : jobs )
    {
        int startTime = job[0];
        int taskTime = job[1];

        while ( startTime > diskProgressTime )
        {
            if ( !pq.empty() )
            {
                int curStartTime = pq.top().second;
                int curTaskTime = pq.top().first;
                pq.pop();

                diskProgressTime += curTaskTime;
                totalProgressTime += (diskProgressTime - curStartTime);
            }
            else
            {
                diskProgressTime = startTime;
            }
        }

        pq.push(make_pair(taskTime, startTime));
    }

    while ( !pq.empty() )
    {
        int curStartTime = pq.top().second;
        int curTaskTime = pq.top().first;
        pq.pop();

        diskProgressTime += curTaskTime;
        totalProgressTime += (diskProgressTime - curStartTime);
    }

    return totalProgressTime / jobs.size();
}

int main()
{
    //vector<vector<int>> jobs = { {0, 10} };
    //vector<vector<int>> jobs = { {0, 10}, {0, 10} };
    vector<vector<int>> jobs = { {0, 5}, {6, 1}, {6, 2} };
    //vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6}, {4, 3} };

    cout << solution(jobs) << endl;

    return 0;
}