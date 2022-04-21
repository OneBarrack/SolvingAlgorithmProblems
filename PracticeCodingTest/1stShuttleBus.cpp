#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - [1차] 셔틀버스

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

int StrTimeToInt(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string intTimeToStr(int time)
{
    string strTime = "";

    int hour = time / 60;
    int min = time % 60;

    if ( hour / 10 == 0 ) strTime += "0";
    strTime += to_string(hour);
    strTime += ":";
    if ( min / 10 == 0 ) strTime += "0";
    strTime += to_string(min);

    return strTime;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    vector<int> answers;

    int shuttleTime = StrTimeToInt("09:00");
    int lastShuttleTime = shuttleTime + ((n - 1) * t);

    vector<int> crewTimes;
    for ( string strTime : timetable )
    {
        int time = StrTimeToInt(strTime);
        if ( time <= lastShuttleTime )
            crewTimes.push_back(time);
    }

    if ( crewTimes.empty() )
    {
        answers.push_back(lastShuttleTime);
    }
    else
    {
        sort(crewTimes.begin(), crewTimes.end());

        int crewCountInShuttle = 0;
        for ( int i = 0; i < crewTimes.size(); ++i )
        {
            ++crewCountInShuttle;
            int curTime = crewTimes[i];

            if ( curTime > shuttleTime )
            {
                while ( curTime > shuttleTime )
                {
                    answers.push_back(shuttleTime);
                    shuttleTime += t;
                    --n;
                    crewCountInShuttle = 1;
                }
            }
            else if ( crewCountInShuttle == m )
            {
                answers.push_back(curTime - 1);
                shuttleTime += t;
                --n;
                crewCountInShuttle = 0;
            }

            if ( n == 0 )
            {
                break;
            }
            else if ( i == crewTimes.size() - 1 )
            {
                answers.push_back(lastShuttleTime);
            }
        }
    }

    return intTimeToStr(answers.back());
}

int main()
{
    int n, t, m;
    vector<string> timetable;
    //n = 1;	t = 1;	m = 5; timetable = { "08:00", "08:01", "08:02", "08:03" };
    n = 2;	t = 10;	m = 2; timetable = { "09:10", "09:09", "08:00" };
    //n = 2;	t = 1;	m = 2; timetable = { "09:00", "09:00", "09:00", "09:00" };
    //n = 1;	t = 1;	m = 5; timetable = { "00:01", "00:01", "00:01", "00:01", "00:01" };
    //n = 1;	t = 1;	m = 1; timetable = { "23:59" };
    //n = 10;	t = 60;	m = 45; timetable = { "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" };
    
    cout << solution(n, t, m, timetable) << endl;

    return 0;
}