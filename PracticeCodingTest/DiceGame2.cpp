//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 주사위 게임 2
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
//int solution(int a, int b, int c) {
//    int answer = a + b + c;
//
//    if (a == b || a == c || b == c)
//    {
//        answer *= static_cast<int>(pow(a, 2) + pow(b, 2) + pow(c, 2));
//        if (a == b && a == c)
//        {
//            answer *= static_cast<int>(pow(a, 3) + pow(b, 3) + pow(c, 3));
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    int a = 5;
//    int b = 3;
//    int c = 3;
//
//    cout << solution(a, b, c) << endl;
//
//    return 0;
//}