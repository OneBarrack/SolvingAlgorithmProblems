//#include <iostream>
//// 프로그래머스 연습문제 : 우박수열 정적분
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
//vector<double> solution(int k, vector<vector<int>> ranges) {
//    vector<double> answer;
//
//    vector<double> sectionAreas;
//    while (k > 1)
//    {
//        int nextNum = (k % 2 == 0) ? k / 2 : k * 3 + 1;
//        sectionAreas.push_back((k + nextNum) / 2.0);
//
//        k = nextNum;
//    }
//
//    for (vector<int>& range : ranges)
//    {
//        int startIndex = range[0];
//        int endIndex = sectionAreas.size() + range[1];
//
//        double sumAreas = (startIndex <= endIndex) ? accumulate(sectionAreas.begin() + startIndex, sectionAreas.begin() + endIndex, 0.0) : -1.0;
//        answer.push_back(sumAreas);
//    }
//
//    return answer;
//}
//
//int main(void) {
//    //int k = 5;    
//    //vector<vector<int>> ranges = {{0, 0}, {0, -1}, {2, -3}, {3, -3}};
//
//    int k = 3;
//    vector<vector<int>> ranges = {{0, 0}, {1, -2}, {3, -3}};
//
//    vector<double> result = solution(k, ranges);
//    for (double& res : result)
//        cout << res << endl;
//
//    //cout << solution(k, ranges) << endl;
//
//    return 0;
//}
