//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 배열의 요소만큼 추가하기
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
//vector<int> solution(vector<int> arr) {
//    vector<int> answer;
//
//    for (int& num : arr)
//    {
//        answer.insert(answer.end(), num, num);
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<int> arr = {5, 1, 4};
//
//    vector<int> result = solution(arr);
//    for (int& res : result)
//        cout << res << endl;
//
//    return 0;
//}