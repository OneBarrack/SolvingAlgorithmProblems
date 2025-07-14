//#include <iostream>
//// 프로그래머스 코드챌린지 1차 예선 : 유연근무제
//// 1
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <sstream>
//
//using namespace std;
//
//int GetRecognizedTime(int desiredTime)
//{
//    int hour = (desiredTime / 100);
//    int minute = desiredTime % 100;
//
//    if (minute > 59)
//    {
//        minute -= 60;
//        ++hour;
//
//        if (hour > 23)
//        {
//            hour = 0;
//        }
//    }
//
//    return (hour * 100) + minute;
//}
//
//int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
//    int answer = 0;
//
//    for (int employeeIndex = 0; employeeIndex < schedules.size(); employeeIndex++)
//    {
//        bool isPassed = true;
//        const int desiredTime = schedules[employeeIndex];
//
//        for (int dayCount = 0; dayCount < timelogs[employeeIndex].size(); dayCount++)
//        {
//            const int dayOfTheWeek = ((startday - 1) + dayCount) % 7;
//            if (dayOfTheWeek == 5 || dayOfTheWeek == 6)
//                continue;
//
//            const int goToWorkTime = timelogs[employeeIndex][dayCount];
//            const int recognizedTime = GetRecognizedTime(desiredTime + 10);
//
//            if (goToWorkTime > recognizedTime)
//            {
//                isPassed = false;
//                break;
//            }
//        }
//
//        if (isPassed)
//        {
//            answer++;
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<int> schedules = {700, 800, 1100};
//    vector<vector<int>> timelogs = {{710, 2359, 1050, 700, 650, 631, 659} ,{800, 801, 805, 800, 759, 810, 809}, {1105, 1001, 1002, 600, 1059, 1001, 1100}};
//    int startday = 5;
//
//    cout << solution(schedules, timelogs, startday) << endl;
//
//    return 0;
//}
