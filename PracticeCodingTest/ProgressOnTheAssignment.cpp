//#include <iostream>
//// 프로그래머스 연습 문제 : 과제 진행하기
//// 2
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
//int ConvertStringTimeToMin(string strTime)
//{
//    return stoi(strTime.substr(0, 2)) * 60 + stoi(strTime.substr(3, 5));
//}
//
//vector<string> solution(vector<vector<string>> plans) {
//    vector<string> answer;
//    vector<pair<string, int>> remainTaskInfos;
//
//    sort(plans.begin(), plans.end(), [](const vector<string>& planA, const vector<string>& planB) {
//        return ConvertStringTimeToMin(planA[1]) < ConvertStringTimeToMin(planB[1]);
//        });
//
//    vector<string> currTask = plans[0];
//    for (int i = 1; i < plans.size(); i++)
//    {
//        vector<string> nextTask = plans[i];
//
//        int timeGap = ConvertStringTimeToMin(nextTask[1]) - ConvertStringTimeToMin(currTask[1]);
//
//        int currTaskPlayTime = stoi(currTask[2]);
//        if (currTaskPlayTime <= timeGap)
//        {
//            answer.push_back(currTask[0]);
//            timeGap -= currTaskPlayTime;
//
//            while (timeGap > 0 && !remainTaskInfos.empty())
//            {
//                pair<string, int>& remainTask = remainTaskInfos.back();
//                
//                if (remainTask.second <= timeGap)
//                {
//                    answer.push_back(remainTask.first);
//                    timeGap -= remainTask.second;
//
//                    remainTaskInfos.pop_back();
//                }
//                else
//                {
//                    remainTask.second -= timeGap;
//                    timeGap = 0;
//                }
//            }
//        }
//        else
//        {
//            remainTaskInfos.push_back(make_pair(currTask[0], currTaskPlayTime - timeGap));
//        }
//
//        currTask = nextTask;
//    }
//
//    answer.push_back(currTask[0]);
//    for (auto rIter = remainTaskInfos.rbegin(); rIter != remainTaskInfos.rend(); rIter++)
//    {
//        answer.push_back((*rIter).first);
//    }
//
//    return answer;
//}
//
//int main(void) {
//    //vector<vector<string>> plans = {{"korean", "11:40", "30"} ,{"english", "12:10", "20"}, {"math", "12:30", "40"}};
//    vector<vector<string>> plans = {{"science", "12:40", "50"} ,{"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};
//    vector<vector<string>> plans = {{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}};
//    
//    vector<string> results = solution(plans);
//    for (string& res : results)
//        cout << res << endl;
//    //cout << solution(maps) << endl;
//
//    return 0;
//}
