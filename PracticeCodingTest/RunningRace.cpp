//#include <iostream>
//// Codility 코딩테스트 연습 
//// Lesson 10 easy. CountFactors 
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
//vector<string> solution(vector<string> players, vector<string> callings) {
//    unordered_map<string, int> playerRanks;
//
//    for (int i = 0; i < players.size(); i++)
//    {
//        playerRanks[players[i]] = i;
//    }
//
//    for (string& call : callings)
//    {
//        string frontPlayer = players[playerRanks[call] - 1];
//
//        swap(players[playerRanks[call]], players[playerRanks[call] - 1]);
//        playerRanks[frontPlayer]++;
//        playerRanks[call]--;
//    }
//
//    return players;
//}
//
//int main()
//{
//    vector<string> players = {"mumu", "soe", "poe", "kai", "mine"};
//    vector<string> callings = {"kai", "kai", "mine", "mine"};
//
//    vector<string> result = solution(players, callings);
//    for (string res : result)
//        cout << res << endl;
//
//    char asdf = 'a';
//    cout << asdf << " " << (char)(asdf + 1) << endl;
//
//    return 0;
//}
