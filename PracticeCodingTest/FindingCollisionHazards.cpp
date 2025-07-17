//#include <iostream>
//// 프로그래머스 [PCCP 기출문제] 3번 / 충돌위험 찾기
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
//void MoveNextPoint(vector<vector<unordered_map<int, int>>>& visitInfo, vector<int>& currentPos, vector<int> targetPos, int& moveCount, int& collisionCount)
//{
//    if (currentPos == targetPos)
//        return;
//
//    // 좌표 이동
//    if (currentPos[0] != targetPos[0])
//    {
//        if (currentPos[0] < targetPos[0])
//        {
//            currentPos[0]++;
//        }
//        else
//        {
//            currentPos[0]--;
//        }
//    }
//    else
//    {
//        if (currentPos[1] < targetPos[1])
//        {
//            currentPos[1]++;
//        }
//        else
//        {
//            currentPos[1]--;
//        }
//    }
//
//    // 충돌 체크
//    unordered_map<int, int>& visitOrderMap = visitInfo[currentPos[0] - 1][currentPos[1] - 1];
//    visitOrderMap[moveCount]++;
//    if (visitOrderMap[moveCount] == 2)
//    {
//        collisionCount++;
//    }
//
//    // 다음 좌표 탐색
//    moveCount++;
//    MoveNextPoint(visitInfo, currentPos, targetPos, moveCount, collisionCount);
//}
//
//int solution(vector<vector<int>> points, vector<vector<int>> routes) {
//    int answer = 0;
//    constexpr int maxPosSize = 100;
//    vector<vector<unordered_map<int, int>>> visitInfo = vector<vector<unordered_map<int, int>>>(maxPosSize, vector<unordered_map<int, int>>(maxPosSize));
//
//    for (int i = 0; i < routes.size(); i++)
//    {
//        vector<int> targetPoints = routes[i];
//        vector<int> currentPos = points[targetPoints[0] - 1];
//        int moveCount = 0;
//        int collisionCount = 0;
//
//        // 시작 지점 충돌 체크
//        unordered_map<int, int>& visitOrderMap = visitInfo[currentPos[0] - 1][currentPos[1] - 1];
//        visitOrderMap[moveCount]++;
//        if (visitOrderMap[moveCount] == 2)
//        {
//            collisionCount++;
//        }
//
//        // 다음 좌표부터 운송 시작
//        moveCount = 1;
//        int targetPoint;
//        for (int j = 1; j < targetPoints.size(); j++)
//        {
//            targetPoint = targetPoints[j];
//            MoveNextPoint(visitInfo, currentPos, points[targetPoint - 1], moveCount, collisionCount);
//        }
//
//        answer += collisionCount;
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<vector<int>> points = {{3, 2} ,{6, 4},{4, 7},{1, 4}};
//    vector<vector<int>> routes = {{4, 2} ,{1, 3},{2, 4}};
//
//    //vector<vector<int>> points = {{2, 2} ,{2, 3},{2, 7},{6, 6},{5, 2}};
//    //vector<vector<int>> routes = {{2, 3, 4, 5} ,{1, 3, 4, 5}};
//
//    cout << solution(points, routes) << endl;
//
//    return 0;
//}
