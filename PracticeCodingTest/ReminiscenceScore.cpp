//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 연습문제. 추억 점수
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
//vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
//    vector<int> answer;
//
//    unordered_map<string, int> scores;
//    for (int i = 0; i < name.size(); i++)
//        scores[name[i]] = yearning[i];
//
//    for (vector<string>& photoNames : photo)
//    {
//        int score = 0;
//        for (string& photoName : photoNames)
//        {
//            if (scores.find(photoName) != scores.end())
//            {
//                score += scores[photoName];
//            }
//        }
//
//        answer.push_back(score);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> name = {"may", "kein", "kain", "radi"};
//    vector<int> yearning = {5, 10, 1, 3};
//    vector<vector<string>> photo = {{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"},{"kon", "kain", "may", "coni"}};
//
//    vector<int> results = solution(name, yearning, photo);
//
//    for (int& result : results)
//        cout << result << endl;
//
//    return 0;
//}
