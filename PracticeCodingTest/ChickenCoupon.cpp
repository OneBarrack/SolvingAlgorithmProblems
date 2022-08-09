#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze2 - 1673. Chicken Coupon

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

/*
예제 입력 1
4 3
10 3
100 5
예제 출력 1
5
14
124
*/

int main()
{
    int couponCount, needStampCount;
    while ( cin >> couponCount >> needStampCount )
    {
        int answer = couponCount;
        int stampCount = couponCount;
        while ( stampCount >= needStampCount )
        {
            couponCount = stampCount / needStampCount;
            stampCount = stampCount % needStampCount;

            answer += couponCount;
            stampCount += couponCount;
        }

        cout << answer << '\n';
    }

    return 0;
}