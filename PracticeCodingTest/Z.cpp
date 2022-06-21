#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Silver1 - Z

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

/*
예제 입력 1
2 3 1
예제 출력 1
11
예제 입력 2
3 7 7
예제 출력 2
63
예제 입력 3
1 0 0
예제 출력 3
0
예제 입력 4
4 7 7
예제 출력 4
63
예제 입력 5
10 511 511
예제 출력 5
262143
*/
int GetQuadrant(int quadSideLength, int r, int c)
{
    int quadrant[2][2] = { {2, 1}, {3, 4} };
    return quadrant[r / quadSideLength][c / quadSideLength];
}

int main()
{
    int N, r, c;
    cin >> N >> r >> c;

    int answer = 0;
    while ( N > 0 )
    {
        int quadSideLength = pow(2, N - 1);
        switch ( GetQuadrant(quadSideLength, r, c) )
        {
            case 4: answer += quadSideLength * quadSideLength;
            case 3: answer += quadSideLength * quadSideLength;
            case 1: answer += quadSideLength * quadSideLength;
            case 2: break;
        }

        r %= quadSideLength;
        c %= quadSideLength;
        --N;
    }

    cout << answer;
    return 0;
}