//#include <iostream>
//// 프로그래머스 2025 프로그래머스 코드챌린지 2차 예선 : 봉인된 주문
//// 3
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
//long long GetOrderByString(string ban)
//{
//    constexpr int alphaSize = 26;
//    long long stringOrder = 0;
//
//    int stringDigitBase = 0;
//    reverse(ban.begin(), ban.end());
//    for (char& c : ban)
//    {
//        stringOrder += pow(alphaSize, stringDigitBase) * (c - 'a' + 1);
//        stringDigitBase++;
//    }
//
//    return stringOrder;
//}
//
//string GetStringByOrder(long long order)
//{
//    constexpr int alphaSize = 26;
//    string outString = "";
//
//    while (order > 0)
//    {
//        int remainder = order % alphaSize;
//
//        char tempChar;
//        if (remainder > 0)
//        {
//            tempChar = remainder + 'a' - 1;
//        }
//        else
//        {
//            tempChar = 'z';
//            order--;
//        }
//
//        outString = string(1, tempChar) + outString;
//        order /= alphaSize;
//    }
//
//    return outString;
//}
//
//string solution(long long n, vector<string> bans) {
//    string answer = "";
//
//    vector<long long> bannedStringOrders;
//    for (string& ban : bans)
//    {
//        bannedStringOrders.push_back(GetOrderByString(ban));
//    }
//
//    sort(bannedStringOrders.begin(), bannedStringOrders.end());
//
//    for (long long bannedStringOrder : bannedStringOrders)
//    {
//        if (bannedStringOrder <= n)
//        {
//            n++;
//        }
//    }
//
//    return GetStringByOrder(n);
//}
//
//int main(void) {
//    int n = 7388;
//    vector<string> bans = {"gqk", "kdn", "jxj", "jxi", "fug", "jxg", "ewq", "len", "bhc"};
//
//    //long long n = 3817158266467285;
//    //vector<string> bans = {"dfdfdfd"};
//
//    cout << solution(n, bans) << endl;
//
//    return 0;
//}
