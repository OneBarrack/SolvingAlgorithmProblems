//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 연습문제. 대충 만든 자판
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
//int solution(int k, int m, vector<int> score) {
//    sort(score.begin(), score.end(), greater<int>());
//
//    int answer = 0;
//    for (int i = 0; i + m <= score.size(); i = i + m)
//    {
//        answer += score[i + m - 1] * m;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int k = 4;
//    int m = 3;
//    vector<int> score = {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2};
//
//    cout << solution(k, m, score) << endl;
//
//    return 0;
//}
