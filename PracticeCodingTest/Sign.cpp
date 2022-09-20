#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze3 - 1247. Sign

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
3
0
0
0
10
1
2
4
8
16
32
64
128
256
-512
6
9223372036854775807
9223372036854775806
9223372036854775805
-9223372036854775807
-9223372036854775806
-9223372036854775804
예제 출력 1
0
-
+
965310000
*/
int main()
{
    for ( int i = 0; i < 3; ++i )
    {
        int N;
        cin >> N;

        long long sumNum = 0;
        int overflowCount = 0;

        while ( N-- > 0 )
        {
            long long inputNum;
            cin >> inputNum;
            
            if ( sumNum > 0 && inputNum > 0 && sumNum > LLONG_MAX - inputNum )
            {
                ++overflowCount;
            }
            else if ( sumNum < 0 && inputNum < 0 && sumNum < LLONG_MIN - inputNum )
            {
                --overflowCount;
            }
            sumNum += inputNum;
        }

        string result = "";
        if ( overflowCount == 0 )
        {
            if ( sumNum == 0 )
            {
                result = "0";
            }
            else if ( sumNum > 0 )
            {
                result = "+";
            }
            else
            {
                result = "-";
            }
        }
        else if ( overflowCount > 0 )
        {
            result = "+";
        }
        else
        {
            result = "-";
        }

        cout << result << '\n';
    }
    
    return 0;
}