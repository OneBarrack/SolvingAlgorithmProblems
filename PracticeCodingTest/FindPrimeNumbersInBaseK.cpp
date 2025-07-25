//#include <iostream>
//// 프로그래머스 2022 KAKAO BLIND RECRUITMENT : K진수에서 소수 개수 구하기
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
//bool IsPrime(long long n)
//{
//    if (n < 2) return false;
//
//    for (long long i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0) 
//            return false;
//    }
//
//    return true;
//}
//
//string ConvertDecimalNumberSystem(int n, int k)
//{
//    string result = "";
//    while (n > 0)
//    {
//        result += to_string(n % k);
//        n /= k;
//    }
//
//    reverse(result.begin(), result.end());
//    return result;
//}
//
//int solution(int n, int k) {
//    int answer = 0;
//    stringstream ss(ConvertDecimalNumberSystem(n, k));
//
//    string token;
//    while (getline(ss, token, '0'))
//    {
//        if (!token.empty() && IsPrime(stoll(token)))
//            answer++;
//    }
//
//    return answer;
//}
//
//int main(void) {
//    int n = 437674;
//    int k = 3;
//
//    //int n = 110011;
//    //int k = 10;
//
//    cout << solution(n, k) << endl;
//
//    return 0;
//}
