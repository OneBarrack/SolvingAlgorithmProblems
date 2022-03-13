//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 리틀 프렌즈 사천성
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
//bool SortNumbers(const int& a, const int& b)
//{
//    string strA = to_string(a);
//    string strB = to_string(b);
//    return stoi(strA + strB) > stoi(strB + strA);
//}
//
//string solution(vector<int> numbers)
//{
//    string answer = "";
//
//    sort(numbers.begin(), numbers.end(), SortNumbers);
//    if ( numbers.front() == 0 )
//    {
//        answer = "0";
//    }
//    else
//    {
//        for ( int num : numbers )
//            answer += to_string(num);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    //vector<int> numbers = { 6, 10, 2 };
//    vector<int> numbers = { 3, 0, 30, 34, 5, 9 };
//    cout << solution(numbers) << endl;
//
//    return 0;
//}