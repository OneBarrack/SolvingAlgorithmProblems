//#include <iostream>
//// 프로그래머스 연습 문제 : 광물 캐기
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
//enum class EMineralType : uint8_t
//{
//    NONE = 0,
//    Diamond,
//    Iron,
//    Stone,
//    EMineralType_MAX
//};
//
//void MineMineral(const vector<vector<int>>& staminaCostPerPickaxe, vector<int>& consumedStaminas, const EMineralType mineralType)
//{
//    const int maxMineralTypeSize = static_cast<int>(EMineralType::EMineralType_MAX) - 1;
//    if (consumedStaminas.size() < maxMineralTypeSize)
//        return;
//
//    for (int i = 0; i < maxMineralTypeSize; i++)
//    {
//        consumedStaminas[i] += staminaCostPerPickaxe[i][static_cast<int>(mineralType) - 1];
//    }
//}
//
//void CalcMinStaminaCost(const vector<vector<int>> consumedStaminasAll, vector<int> remainedPickaxes, int depth, int staminaCostSum, int& minStaminaCost)
//{
//    if (depth == consumedStaminasAll.size() || all_of(remainedPickaxes.begin(), remainedPickaxes.end(), [](int count) { return count == 0; }))
//    {
//        minStaminaCost = min(minStaminaCost, staminaCostSum);
//        return;
//    }
//
//    for (int i = 0; i < remainedPickaxes.size(); i++)
//    {
//        if (remainedPickaxes[i] == 0)
//            continue;
//
//        vector<int> tempRemainedPickaxes = remainedPickaxes;
//        tempRemainedPickaxes[i]--;
//
//        CalcMinStaminaCost(consumedStaminasAll, tempRemainedPickaxes, depth + 1, staminaCostSum + consumedStaminasAll[depth][i], minStaminaCost);
//    }
//}
//
//int solution(vector<int> picks, vector<string> minerals) {    
//    constexpr int maxMineralsMinedPerPickaxe = 5;
//    const vector<vector<int>> staminaCostPerPickaxe = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
//    
//    vector<vector<int>> consumedStaminasAll;
//
//    vector<int> consumedStaminas(static_cast<int>(EMineralType::EMineralType_MAX) - 1);
//    int mineralCount = 0;
//    for (string& mineral : minerals)
//    {
//        mineralCount++;
//
//        EMineralType mineralType = EMineralType::NONE;
//
//        if (mineral == "diamond")    mineralType = EMineralType::Diamond;
//        else if (mineral == "iron")  mineralType = EMineralType::Iron;
//        else if (mineral == "stone") mineralType = EMineralType::Stone;
//
//        if (mineralType != EMineralType::NONE)
//        {
//            MineMineral(staminaCostPerPickaxe, consumedStaminas, mineralType);
//        }
//
//        if (mineralCount == maxMineralsMinedPerPickaxe)
//        {            
//            consumedStaminasAll.push_back(consumedStaminas);
//
//            fill(consumedStaminas.begin(), consumedStaminas.end(), 0);
//            mineralCount = 0;
//        }
//    }
//
//    if (mineralCount > 0)
//    {
//        consumedStaminasAll.push_back(consumedStaminas);
//    }
//
//    int answer = INT_MAX;
//    CalcMinStaminaCost(consumedStaminasAll, picks, 0, 0, answer);
//
//    return answer;
//}
//
//int main(void) {
//    //vector<int> picks = {1, 3, 2};
//    //vector<string> minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};
//
//    vector<int> picks = {0, 1, 1};
//    vector<string> minerals = {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};
//    
//    cout << solution(picks, minerals) << endl;
//
//    return 0;
//}
