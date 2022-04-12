#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.2 - 주차 요금 계산

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

const int limitOutTime = 1439; // 23:59

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<int, int> totalParkingTimes; // < carNumber, totalParkingTime >
    unordered_map<int, int> parkingInfos; // < carNumber, parkingStartTime >

    for ( string record : records )
    {
        int time, carNumber;

        string timeStr, carNumberStr;
        stringstream ss(record);
        getline(ss, timeStr, ' ');
        getline(ss, carNumberStr, ' ');

        time = stoi(timeStr.substr(0, 2)) * 60 + stoi(timeStr.substr(3, 2));
        carNumber = stoi(carNumberStr);

        auto parkingInfo = parkingInfos.find(carNumber);
        if ( parkingInfo == parkingInfos.end() ) // IN
        {
            parkingInfos[carNumber] = time;
        }
        else // OUT
        {
            totalParkingTimes[carNumber] += (time - parkingInfo->second);
            parkingInfos.erase(parkingInfo);
        }
    }

    for ( auto iter = parkingInfos.begin(); iter != parkingInfos.end(); ++iter )
    {
        int carNumber = iter->first;
        int startParkingTime = iter->second;
        totalParkingTimes[carNumber] += (limitOutTime - startParkingTime);
    }

    // fees : 기본 시간(분), 기본 요금(원), 단위 시간(분), 단위 요금(원)
    int defaultTime = fees[0];
    int defaultCost = fees[1];
    int unitTime = fees[2];
    int unitCost = fees[3];
    for ( auto iter = totalParkingTimes.begin(); iter != totalParkingTimes.end(); ++iter )
    {
        int cost = defaultCost;
        int totalParkingTime = iter->second;

        if ( defaultTime < totalParkingTime )
        {
            cost += ceil((totalParkingTime - defaultTime) / (float)unitTime) * unitCost;
        }

        answer.push_back(cost);
    }

    return answer;
}

int main()
{
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

    vector<int> result = solution(fees, records);
    for ( int res : result )
        cout << res << endl;

    return 0;
}