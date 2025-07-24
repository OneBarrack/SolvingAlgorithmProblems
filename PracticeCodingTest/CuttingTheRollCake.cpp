//#include <iostream>
//// 프로그래머스 연습문제 : 롤케이크 자르기
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
//int solution(vector<int> topping) {
//    map<int, int> leftPiece, rightPiece;
//    
//    leftPiece[topping[0]] = 1;
//    for (int i = 1; i < topping.size(); i++)
//        rightPiece[topping[i]]++;
//
//    int answer = leftPiece.size() == rightPiece.size() ? 1 : 0;
//    for (int i = 1; i < topping.size(); i++)
//    {
//        leftPiece[topping[i]]++;
//        rightPiece[topping[i]]--;
//
//        if (rightPiece[topping[i]] == 0)
//        {
//            rightPiece.erase(topping[i]);
//        }
//
//        if (leftPiece.size() == rightPiece.size())
//        {
//            answer++;
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<int> topping = {1, 2, 1, 3, 1, 4, 1, 2};
//    //vector<int> topping = {1, 1, 1};
//
//    cout << solution(topping) << endl;
//
//    return 0;
//}
