//#include <iostream>
//// 프로그래머스 연습 문제 : 무인도 여행
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
//const int GetFoodCountOnDesertIsland(const vector<string>& maps, vector<vector<bool>>& visits, int row, int col)
//{
//    if (maps[row][col] == 'X' || visits[row][col])
//        return 0;
//    
//    visits[row][col] = true;
//    int foodCount = maps[row][col] - '0';
//
//    if (row > 0)                  foodCount += GetFoodCountOnDesertIsland(maps, visits, row - 1, col);
//    if (row < maps.size() - 1)    foodCount += GetFoodCountOnDesertIsland(maps, visits, row + 1, col);
//    if (col > 0)                  foodCount += GetFoodCountOnDesertIsland(maps, visits, row, col - 1);
//    if (col < maps[0].size() - 1) foodCount += GetFoodCountOnDesertIsland(maps, visits, row, col + 1);
//
//    return foodCount;
//}
//
//vector<int> solution(vector<string> maps) {
//    vector<int> answer;
//
//    vector<vector<bool>> visits(maps.size(), vector<bool>(maps[0].size()));
//    for (int row = 0; row < maps.size(); row++)
//    {
//        for (int col = 0; col < maps[0].size(); col++)
//        {
//            const int foodCountOnDesertIsland = GetFoodCountOnDesertIsland(maps, visits, row, col);
//            if (foodCountOnDesertIsland > 0)
//            {
//                answer.push_back(foodCountOnDesertIsland);
//            }
//        }
//    }
//
//    sort(answer.begin(), answer.end());
//    return answer.empty() ? vector<int>{-1} : answer;
//}
//
//int main(void) {
//    vector<string> maps = {"X591X","X1X5X","X231X", "1XXX1"};
//    //vector<string> maps = {"XXX","XXX","XXX"};
//
//    vector<int> results = solution(maps);
//    for (int& res : results)
//        cout << res << endl;
//
//    //cout << solution(maps) << endl;
//
//    return 0;
//}
