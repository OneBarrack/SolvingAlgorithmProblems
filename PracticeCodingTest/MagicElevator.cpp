//#include <iostream>
//// 프로그래머스 연습 문제 : 마법의 엘리베이터
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
//int solution(int storey) {
//    int answer = 0;
//
//    while (storey >= 10)
//    {
//        int num = storey % 10;
//
//        if (num < 5 || (num == 5 && storey / 10 % 10 < 5))
//        {
//            storey -= num;
//            answer += num;
//        }
//        else
//        {
//            storey += 10 - num;
//            answer += 10 - num;
//        }
//
//        storey /= 10;
//    }
//
//    answer += (storey > 5) ? (10 - storey + 1) : (storey);
//    return answer;
//}
//
//int main(void) {
//    //int storey = 2554;
//    //int storey = 15555;
//    //int storey = 9;
//    int storey = 545;
//
//    cout << solution(storey) << endl;
//
//    return 0;
//}
