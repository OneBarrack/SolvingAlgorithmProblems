//#include <iostream>
//// 프로그래머스 2019 KAKAO BLIND RECRUITMENT : 무지의 먹방 라이브
//// 4
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
//int solution(vector<int> food_times, long long k)
//{
//    int answer = -1;
//
//    map<int, int> foodTimeCounts;
//    long long totalEatingTime = 0;
//    for (int& foodTime : food_times)
//    {
//        ++foodTimeCounts[foodTime];
//        totalEatingTime += foodTime;
//    }
//
//    if (k < totalEatingTime)
//    {
//        int prevFoodTime = 0;
//        int remainFoodCount = food_times.size();
//        for (auto iter = foodTimeCounts.begin(); iter != foodTimeCounts.end(); ++iter)
//        {
//            int curFoodTime = iter->first;
//            int curFoodTimeCount = iter->second;
//
//            int foodTimeBetweenPrev = curFoodTime - prevFoodTime;
//            long long eatingTime = (long long)foodTimeBetweenPrev * remainFoodCount;
//            prevFoodTime = curFoodTime;
//
//            if (k <= eatingTime)
//            {
//                k %= remainFoodCount;
//
//                if (k == 0)
//                    curFoodTime = next(iter)->first;
//
//                for (int i = 0; i < food_times.size(); ++i)
//                {
//                    if (food_times[i] >= curFoodTime)
//                    {
//                        if (k == 0)
//                        {
//                            answer = i + 1;
//                            break;
//                        }
//
//                        --k;
//                    }
//                }
//
//                break;
//            }
//            else
//            {
//                k -= eatingTime;
//                remainFoodCount -= curFoodTimeCount;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<int> food_times = {3, 1, 2};
//    long long k = 5;
//
//    cout << solution(food_times, k) << endl;
//
//    return 0;
//}
