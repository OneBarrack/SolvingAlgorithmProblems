//#include <iostream>
//// 프로그래머스 PCCE 기출문제 10번 : 데이터 분석
//// 1
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
//    vector<vector<int>> answer;
//    unordered_map<string, int> infoIndex = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};
//
//    for (const vector<int>& dataElem : data)
//        if (dataElem[infoIndex[ext]] < val_ext)
//            answer.push_back(dataElem);
//
//    sort(answer.begin(), answer.end(), [&infoIndex, &sort_by](const vector<int>& v1, const vector<int>& v2) {
//        return v1[infoIndex[sort_by]] < v2[infoIndex[sort_by]];
//        });
//
//    return answer;
//}
//
//int main(void)
//{
//    vector<vector<int>> data = {{1, 20300104, 100, 80} ,{2, 20300804, 847, 37},{3, 20300401, 10, 8}};
//    string ext = "date";
//    int val_ext = 20300501;
//    string sort_by = "remain";
//
//    vector<vector<int>> result = solution(data, ext, val_ext, sort_by);
//    for (vector<int> res : result)
//    {       
//        for (int r : res)
//            cout << r << endl;
//
//        cout << endl;
//    }
//    return 0;
//}
