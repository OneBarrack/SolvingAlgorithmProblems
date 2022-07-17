#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze3 - 1284. Home Adress

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
120
5611
100
0
예제 출력 1
13
15
14
*/

int main()
{
    while ( true )
    {
        string homeNumber;
        cin >> homeNumber;

        if ( homeNumber == "0" )
            break;

        int totalWidth = homeNumber.length() + 1;
        for ( char num : homeNumber )
        {
            switch ( num )
            {
                case '0': totalWidth += 4; break;
                case '1': totalWidth += 2; break;
                default : totalWidth += 3; break;
            }
        }

        cout << totalWidth << endl;
    }

    return 0;
}