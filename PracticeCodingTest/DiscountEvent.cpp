//#include <iostream>
//// 프로그래머스 연습문제 : 할인 행사
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
//int solution(vector<string> want, vector<int> number, vector<string> discount) {
//    constexpr int membershipPeriod = 10;
//    int answer = 0;
//
//    map<string, int> wantProductCounts;    
//    int remainWantProductCount = 0;
//
//    for (int i = 0; i < want.size(); i++)
//    {
//        wantProductCounts[want[i]] = number[i];
//        remainWantProductCount += number[i];
//    }
//
//    // 1 ~ 10 days
//    for (int i = 0; i < membershipPeriod; i++)
//    {
//        if ((wantProductCounts.find(discount[i]) != wantProductCounts.end()) && wantProductCounts[discount[i]]-- > 0)
//        {
//            remainWantProductCount--;
//        }
//    }
//
//    if (remainWantProductCount == 0)
//        answer++;
//
//    // 11 days ~
//    for (int joinDate = 1, lastDate = membershipPeriod; lastDate < discount.size(); joinDate++, lastDate++)
//    {
//        if ((wantProductCounts.find(discount[joinDate - 1]) != wantProductCounts.end()) && wantProductCounts[discount[joinDate - 1]]++ > -1)
//        {
//            remainWantProductCount++;
//        }
//
//        if (wantProductCounts.contains(discount[lastDate]) && wantProductCounts[discount[lastDate]]-- > 0)
//        {
//            remainWantProductCount--;
//        }
//
//        if (remainWantProductCount == 0)
//            answer++;
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
//    vector<int> number = {3, 2, 2, 2, 1};
//    vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
//
//    //vector<string> want = {"apple"};
//    //vector<int> number = {10};
//    //vector<string> discount = {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"};
//
//    cout << solution(want, number, discount) << endl;
//
//    return 0;
//}
