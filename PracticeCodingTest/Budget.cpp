//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 예산
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
//
//using namespace std;
//
//int solution(vector<int> d, int budget)
//{
//    int count = 0;
//    sort(d.begin(), d.end());
//    while ( count < d.size() && budget > 0 && d[count] <= budget )
//        budget -= d[count++];
//    return count;
//}
//
//int main()
//{
//    vector<int> d = { 1, 3, 2, 5, 4 };
//    int budget = 9;
//    cout << solution(d, budget) << endl;
//
//    return 0;
//}