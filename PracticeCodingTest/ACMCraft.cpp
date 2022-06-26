//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Gold3 - ACM Craft
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
///*
//예제 입력 1
//2
//4 4
//10 1 100 10
//1 2
//1 3
//2 4
//3 4
//4
//8 8
//10 20 1 5 8 7 1 43
//1 2
//1 3
//2 4
//2 5
//3 6
//5 7
//6 7
//7 8
//7
//예제 출력 1
//120
//39
//*/
//
//int GetTotalBuildTime(vector<int>& buildTimes, vector<int>& totalBuildTimes, vector<vector<int>>& needBuildings, int building)
//{
//    int buildTimeForNeedBuildings = 0;
//
//    for ( int& needBuilding : needBuildings[building] )
//    {
//        if ( totalBuildTimes[needBuilding] > 0 )
//            buildTimeForNeedBuildings = max(buildTimeForNeedBuildings, totalBuildTimes[needBuilding]);
//        else
//            buildTimeForNeedBuildings = max(buildTimeForNeedBuildings, GetTotalBuildTime(buildTimes, totalBuildTimes, needBuildings, needBuilding));
//    }
//    
//    totalBuildTimes[building] = buildTimes[building] + buildTimeForNeedBuildings;
//    return totalBuildTimes[building];
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//
//    while ( T > 0 )
//    {
//        int N, K;
//        cin >> N >> K;
//
//        int answer = 0;
//        vector<int> buildTimes(N + 1);
//        vector<int> totalBuildTimes(N + 1);
//        vector<vector<int>> needBuildings(K + 1);
//
//        for ( int i = 0; i < N; ++i )
//            cin >> buildTimes[i + 1];
//
//        for ( int i = 0; i < K; ++i )
//        {
//            int needBuilding, targetBuilding;
//            cin >> needBuilding >> targetBuilding;
//            
//            needBuildings[targetBuilding].push_back(needBuilding);
//        }
//
//        int finalBuilding;
//        cin >> finalBuilding;
//
//        cout << GetTotalBuildTime(buildTimes, totalBuildTimes, needBuildings, finalBuilding) << "\n";
//
//        --T;
//    }
//    
//    return 0;
//}