#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Silver5 - 1205. Get Rank

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
3 90 10
100 90 80
예제 출력 1
2
예제 입력 2
10 1 10
10 9 8 7 6 5 4 3 2 1
예제 출력 2
-1
예제 입력 3
10 1 10
10 9 8 7 6 5 4 3 3 0
예제 출력 3
10
*/

int main()
{
    int N, newScore, P;
    cin >> N >> newScore >> P;

    int rank = 1;
    int prevScore = INT_MAX;
    int overlapCount = 1;
    for ( int i = 0; i < N; ++i )
    {
        int curScore;
        cin >> curScore;

        if ( P == 0 || (prevScore >= newScore && newScore > curScore) )
        {
            rank += overlapCount - 1;
            break;
        }

        if ( prevScore > curScore )
        {
            rank += overlapCount;
            prevScore = curScore;
            overlapCount = 1;
        }
        else
        {
            ++overlapCount;
        }

        --P;
    }

    if ( P > 0 ) cout << rank;
    else         cout << -1;

    return 0;
}