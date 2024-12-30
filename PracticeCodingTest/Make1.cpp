//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 1로 만들기
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
//int solution(vector<int> num_list) {
//    int answer = 0;
//
//    for (int num : num_list)
//    {
//        while (num > 1)
//        {
//            num = (num % 2 == 0) ? (num / 2) : ((num - 1) / 2);
//            ++answer;
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<int> num_list = {12, 4, 15, 1, 14};
//    
//    cout << solution(num_list) << endl;    
//    
//    return 0;
//}