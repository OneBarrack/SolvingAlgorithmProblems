//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 콜라츠 수열 만들기
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
//vector<int> solution(int n) {
//    vector<int> answer;
//    answer.push_back(n);
//
//    while (n > 1)
//    {
//        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
//        answer.push_back(n);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 10;
//    vector<int> result = solution(n);
//
//    for (int res : result)
//        cout << res << endl;
//
//    return 0;
//}