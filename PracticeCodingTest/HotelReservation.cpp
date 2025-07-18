//#include <iostream>
//// 프로그래머스 연습문제 / 호텔 대실
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
//int solution(vector<vector<string>> book_time) {
//    int answer = 0;
//    constexpr int cleaningRoomTime = 10;
//
//    priority_queue<int, vector<int>, greater<int>> roomQueue;
//    sort(book_time.begin(), book_time.end());
//
//    for (vector<string>& timeInfo : book_time)
//    {
//        const int sTime = ConvertStringTimeToMin(timeInfo[0]);
//        const int eTime = ConvertStringTimeToMin(timeInfo[1]);
//
//        if (!roomQueue.empty() && roomQueue.top() <= sTime)
//        {
//            roomQueue.pop();
//        }
//
//        roomQueue.push(eTime + cleaningRoomTime);
//        answer = max(answer, static_cast<int>(roomQueue.size()));
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<vector<string>> book_time = {{"15:00", "17:00"} ,{"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};
//
//    cout << solution(book_time) << endl;
//
//    return 0;
//}
