//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 H-Index
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <sstream>
//#include <set>
//
//using namespace std;
//
//int solution(vector<int> citations)
//{
//    int answer = 0;
//
//    sort(citations.begin(), citations.end());
//    for ( int H_Index = citations.size(); H_Index > 0; --H_Index )
//    {
//        int curIndex = citations.size() - H_Index;
//        if ( H_Index <= citations[curIndex] && (curIndex == 0 || citations[curIndex - 1] <= H_Index))
//        {
//            answer = H_Index;
//            break;
//        }
//    }
//    
//    return answer;
//}
//
//int main()
//{
//    vector<int> citations = { 1, 4 };
//    //vector<int> citations = { 9,9,9,12 };
//    cout << solution(citations) << endl;
//
//    return 0;
//}