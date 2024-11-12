//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// [PCCP 기출문제] 1번 / 붕대 감기
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
//    int maxHealth = health;
//
//    int prevAttackTime = -1;
//    for (vector<int>& attack : attacks)
//    {
//        int curAttackTime = attack[0];
//        int damage = attack[1];
//        int attackTimeGap = curAttackTime - prevAttackTime;
//
//        health += ((attackTimeGap - 1) * bandage[1]) + (((attackTimeGap - 1) / bandage[0]) * bandage[2]);
//        health = min(health, maxHealth);
//
//        health -= damage;
//        prevAttackTime = curAttackTime;
//
//        if (health < 1)
//            return -1;
//    }
//
//    return health;
//}
//
//int main()
//{
//    //vector<int> bandage = {5, 1, 5}; 
//    //int health = 30; 
//    //vector<vector<int>> attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};
//
//    vector<int> bandage = {3, 2, 7}; 
//    int health = 20; 
//    vector<vector<int>> attacks = {{1, 15}, {5, 16}, {8, 6}};
//
//    cout << solution(bandage, health, attacks) << endl;
//
//    return 0;
//}
