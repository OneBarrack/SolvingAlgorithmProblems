//#include <iostream>
//// 프로그래머스 2023 KAKAO BLIND RECRUITMENT : 택배 배달과 수거하기
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
//#define INDEX_NONE -1
//
//vector<int> GetDistsPerRound(int cap, vector<int> destInfo)
//{
//    vector<int> distsPerRound;
//
//    int startLoadingAndUnlodingIndex = INDEX_NONE;
//    int remainCapCount = cap;
//    for (int index = destInfo.size() - 1; index >= 0; )
//    {
//        // Start
//        if (destInfo[index] > 0 && remainCapCount == cap)
//        {
//            startLoadingAndUnlodingIndex = index;
//        }
//
//        // Calc
//        if (destInfo[index] < remainCapCount)
//        {
//            remainCapCount -= destInfo[index];
//            destInfo[index] = 0;
//        }
//        else
//        {
//            destInfo[index] -= remainCapCount;
//            remainCapCount = 0;
//        }
//
//        // Complete
//        if (remainCapCount == 0)
//        {
//            distsPerRound.push_back(startLoadingAndUnlodingIndex + 1);
//            startLoadingAndUnlodingIndex = -1;
//            remainCapCount = cap;
//        }
//
//        // Next
//        if (destInfo[index] == 0)
//        {
//            index--;
//        }
//    }
//
//    // Last delivery
//    if (remainCapCount > 0 && startLoadingAndUnlodingIndex != INDEX_NONE)
//    {
//        distsPerRound.push_back(startLoadingAndUnlodingIndex + 1);
//    }
//
//    return distsPerRound;
//}
//
//
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//    long long answer = 0;
//    
//    vector<int> deliveryDistsPerRound = GetDistsPerRound(cap, deliveries);
//    vector<int> pickupDistsPerRound = GetDistsPerRound(cap, pickups);
//
//    // Distance per round
//    int distIndex = 0;
//    while (true)
//    {
//        int deliveryDist = 0;
//        int pickupDist = 0;
//
//        if (distIndex < deliveryDistsPerRound.size())
//        {
//            deliveryDist = deliveryDistsPerRound[distIndex];
//        }
//        
//        if (distIndex < pickupDistsPerRound.size())
//        {
//            pickupDist = pickupDistsPerRound[distIndex];
//        }
//
//        if (deliveryDist == 0 && pickupDist == 0)
//            break;
//
//        answer += (long long)max(deliveryDist, pickupDist) * 2;
//        distIndex++;
//    }
//
//    return answer;
//}
//
//int main(void) {
//    //int cap = 4;
//    //int n = 5;
//    //vector<int> deliveries = {1, 0, 3, 1, 2};
//    //vector<int> pickups = {0, 3, 0, 4, 0};    
//
//    int cap = 2;
//    int n = 7;
//    vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
//    vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};
//
//    //int cap = 4;
//    //int n = 5;
//    //vector<int> deliveries = {0, 0, 0, 0, 0};
//    //vector<int> pickups = {0, 0, 0, 0, 0};
//
//    cout << solution(cap, n, deliveries, pickups) << endl;
//
//    return 0;
//}
