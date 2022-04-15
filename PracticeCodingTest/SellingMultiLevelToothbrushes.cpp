//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 다단계 칫솔 판매
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
//vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
//{
//    vector<int> answer;
//    unordered_map<string, string> referrals;
//    unordered_map<string, int> profits;
//
//    // Referral
//    for ( int i = 0; i < enroll.size(); ++i )
//    {
//        referrals[enroll[i]] = referral[i];
//    }
//
//    // Sell profit
//    for ( int i = 0; i < seller.size(); ++i )
//    {
//        string sellerName = seller[i];
//        int salesProfit = amount[i] * 100;
//
//        while ( salesProfit > 0 && sellerName != "-" )
//        {
//            int distributionProfit = salesProfit / 10;
//            int realProfit = salesProfit - distributionProfit;
//
//            profits[sellerName] += realProfit;
//            sellerName = referrals[sellerName];
//            salesProfit = distributionProfit;
//        }
//    }
//
//    for ( string name : enroll )
//    {
//        answer.push_back(profits[name]);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
//    vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
//    vector<string> seller = { "young", "john", "tod", "emily", "mary" };
//    vector<int> amount = { 12, 4, 2, 5, 10 };
//
//    vector<int> result = solution(enroll, referral, seller, amount);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}