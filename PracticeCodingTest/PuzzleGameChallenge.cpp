//#include <iostream>
//// 프로그래머스 연습 문제 : 퍼즐 게임 챌린지
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
//#include <numeric>
//
//using namespace std;
//
//int solution(vector<int> diffs, vector<int> times, long long limit) {
//    int answer = 0;
//
//    int low = 1;
//    int high = *max_element(diffs.begin(), diffs.end());
//    answer = high;
//
//    while (low <= high)
//    {
//        int level = low + (high - low) / 2;
//        if (level < 1)
//            break;
//
//        long long timeSum = 0;
//        for (int i = 0; i < diffs.size(); i++)
//        {
//            int diff = diffs[i];
//            int time = times[i];
//
//            if (diff > level)
//            {
//                int prevTime = times[i - 1];
//                timeSum += ((long long)time + prevTime) * (diff - level) + time;
//            }
//            else
//            {
//                timeSum += time;
//            }
//
//            if (timeSum > limit)
//            {
//                low = level + 1;
//                break;
//            }
//        }
//
//        if (timeSum <= limit)
//        {
//            answer = min(answer, level);
//            high = level - 1;
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    //vector<int> diffs = {1, 5, 3};
//    //vector<int> times = {2, 4, 7};
//    //long long limit = 30;
//
//    //vector<int> diffs = {1, 4, 4, 2};
//    //vector<int> times = {6, 3, 8, 2};
//    //long long limit = 59;
//
//    //vector<int> diffs = {1, 328, 467, 209, 54};
//    //vector<int> times = {2, 7, 1, 4, 3};
//    //long long limit = 1723;
//
//    //vector<int> diffs = {1, 99999, 100000, 99995};
//    //vector<int> times = {9999, 9001, 9999, 9001};
//    //long long limit = 3456789012;
//
//    vector<int> diffs = {1, 1, 4};
//    vector<int> times = {1, 1, 4};
//    long long limit = 50;
//
//    cout << solution(diffs, times, limit) << endl;
//
//    return 0;
//}
